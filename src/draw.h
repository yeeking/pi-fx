#pragma once
#include <linux/fb.h>

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


void drawCircle(int centerX, int centerY, int diameter, Color color) {
    int radius = diameter / 2;
    long int location = 0;
    int x = 0, y = 0;

    // Iterate over the bounding square of the circle
    for (y = centerY - radius; y < centerY + radius; y++) {
        for (x = centerX - radius; x < centerX + radius; x++) {
            int dx = x - centerX;
            int dy = y - centerY;
            // Check if the pixel is inside the circle
            if (dx * dx + dy * dy <= radius * radius) {
                location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                           (y + vinfo.yoffset) * finfo.line_length;

                if (vinfo.bits_per_pixel == 16) {
                    *((unsigned short int *)(fbp + location)) = color;
                }
                // Add cases for other color depths if necessary.
            }
        }
    }
}


private:
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    char *fbp;
    int fbfd;
    long int screensize;
};
