#pragma once
#include <linux/fb.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <iostream>
#include <cmath>
#include <vector> 
#include "letters.h"
typedef unsigned short int Color;


class FBScreen
{
public:
    FBScreen()
    {
        fbfd = 0;

        screensize = 0;
        fbp = 0;

        // Open the file for reading and writing
        fbfd = open("/dev/fb0", O_RDWR);
        if (fbfd == -1)
        {
            perror("Error: cannot open framebuffer device");
            exit(1);
        }
        printf("The framebuffer device was opened successfully.\n");

        // Get fixed screen information
        if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1)
        {
            perror("Error reading fixed information");
            exit(2);
        }

        // Get variable screen information
        if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1)
        {
            perror("Error reading variable information");
            exit(3);
        }

        printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

        // Figure out the size of the screen in bytes
        screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

        // Map the device to memory
        fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
                           fbfd, 0);
        if ((long int)fbp == -1)
        {
            perror("Error: failed to map framebuffer device to memory");
            exit(4);
        }
        printf("The framebuffer device was mapped to memory successfully.\n");
    }
    ~FBScreen()
    {
        munmap(fbp, screensize);
        close(fbfd);
    }

    Color rgb_to_16bit(int r, int g, int b)
    {
        // Clamp and scale each component to its respective bit count
        r = (r & 0xFF) >> 3; // 5 bits
        g = (g & 0xFF) >> 2; // 6 bits
        b = (b & 0xFF) >> 3; // 5 bits

        // Combine components into a single 16-bit number
        return (r << 11) | (g << 5) | b;
    }
    // void drawCircle()

    void fillBackground(Color color)
    {
        long int location = 0;
        int x = 0, y = 0;
        x = 0;
        y = 0; // Where we are going to put the pixel

        for (y = 0; y < vinfo.height; y++)
        {
            for (x = 0; x < vinfo.width; x++)
            {
                location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                           (y + vinfo.yoffset) * finfo.line_length;
                if (vinfo.bits_per_pixel == 16)
                {
                    *((unsigned short int *)(fbp + location)) = color;
                }
            }
        }
    }

    void drawCircle(int centerX, int centerY, int diameter, Color color)
    {
        int radius = diameter / 2;
        long int location = 0;
        int x = 0, y = 0;

        // Iterate over the bounding square of the circle
        for (y = centerY - radius; y < centerY + radius; y++)
        {
            for (x = centerX - radius; x < centerX + radius; x++)
            {
                int dx = x - centerX;
                int dy = y - centerY;
                // Check if the pixel is inside the circle
                if (dx * dx + dy * dy <= radius * radius)
                {
                    location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                               (y + vinfo.yoffset) * finfo.line_length;

                    if (vinfo.bits_per_pixel == 16)
                    {
                        *((unsigned short int *)(fbp + location)) = color;
                    }
                    // Add cases for other color depths if necessary.
                }
            }
        }
    }

    void drawCircleOutline(int centerX, int centerY, int diameter, Color color, int thickness)
    {
        Color black = rgb_to_16bit(0, 0, 0);
        drawCircle(centerX, centerY, diameter, color);
        drawCircle(centerX, centerY, diameter - thickness, black);
    }
    void drawLine(int startX, int startY, int angle, int length, Color col)
    {
        int endX = startX + length * cos(angle * M_PI / 180.0);
        int endY = startY + length * sin(angle * M_PI / 180.0);

        int dx = abs(endX - startX);
        int dy = abs(endY - startY);

        int sx = (startX < endX) ? 1 : -1;
        int sy = (startY < endY) ? 1 : -1;

        int err = dx - dy;

        while (true)
        {
            long int location = (startX + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                                (startY + vinfo.yoffset) * finfo.line_length;

            if (vinfo.bits_per_pixel == 16)
            {
                *((unsigned short int *)(fbp + location)) = col;
            }
            // Add cases for other color depths if necessary.

            if (startX == endX && startY == endY)
            {
                break;
            }

            int e2 = 2 * err;
            if (e2 > -dy)
            {
                err -= dy;
                startX += sx;
            }
            if (e2 < dx)
            {
                err += dx;
                startY += sy;
            }
        }
    }




void drawChar(int x, int y, char c, Color col) {
    if ((c < 'A' || c > 'Z') && (c < '0' || c > '9')) return; 

    const unsigned short *bitmap;
    if (c >= 'A' && c <= 'Z') {
        bitmap = CHAR_LOOKUP[c - 'A'];
    } else {
        bitmap = CHAR_LOOKUP[c - '0' + 26];  // Assuming numbers come after letters in the lookup
    }

    for (int cy = 0; cy < CHAR_HEIGHT; cy++) {
        for (int cx = 0; cx < CHAR_WIDTH; cx++) {
            if (bitmap[cy] & (0b1000000000000000 >> cx)) {  // Check each bit in the 2-byte integer
                long int location = (x + cx + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                                    (y + cy + vinfo.yoffset) * finfo.line_length;
                if (vinfo.bits_per_pixel == 16) {
                    *((unsigned short int *)(fbp + location)) = col;
                }
            }
        }
    }
}



void drawText(int x, int y, const std::string &text, Color col) {
    for (size_t i = 0; i < text.size(); i++) {
        drawChar(x + i * CHAR_WIDTH, y, text[i], col);
    }
}


private:
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    char *fbp;
    int fbfd;
    long int screensize;

    // Color FONT_BITMAP[26][CHAR_WIDTH][CHAR_HEIGHT];  // This would contain the actual bitmaps for 'A' to 'Z'.

};
