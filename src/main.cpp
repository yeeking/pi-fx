/// This example uses the simpleclock class
/// to periodically draw a rectangle on the screen


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <iostream> 

#include "SimpleClock.h"

struct input_event ev[64];

struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
int ticks = 0;
enum class DialEventType {left,right,down,up,unknown};
struct DialEvent{
    DialEventType type;
    signed int value;
};

unsigned short int rgb_to_16bit(int r, int g, int b) {
    // Clamp and scale each component to its respective bit count
    r = (r & 0xFF) >> 3;  // 5 bits
    g = (g & 0xFF) >> 2;  // 6 bits
    b = (b & 0xFF) >> 3;  // 5 bits

    // Combine components into a single 16-bit number
    return (r << 11) | (g << 5) | b;
}



DialEvent getChar(int file_ref)
    {
            DialEvent event;
            event.type = DialEventType::unknown;
            event.value = 0;/* Some value you want to assign */

        int rd, code_id, ev_count, key_code;
        ev_count = 0;
        key_code = 0;
        // keep reading until 
        // we get a key down or key held event
        while(1)
        {
            rd = read(file_ref, ev, sizeof(struct input_event) * 64);
//            printf("%i  %i %i \n", ev->code, ev->type, ev->value);
            //printf("read %i\n", rd);
            if (rd > 48) 
            {
              printf("Ignoring\n");
              continue; // holding lots of keys, ignore.
            }
            ev_count = rd / sizeof(struct input_event);
            printf("ev_count %i\n", ev_count);
            if(ev_count == 2)
            {
                code_id = 0;
            }
            else if (ev_count == 3)
            {
                code_id = 1;
            }
            //printf("\ncode id: %i", code_id);

            // .code tells you the key they pressed
            key_code = ev[code_id].code;
            // .value tells you key up, down, hold 
            //1 and 2 are key down or held events
            // if (ev[code_id].value == 1 || ev[code_id].value == 2)
            printf("KeyUtisl:: %i %i \n", key_code, ev[code_id].value);  

            if (key_code == 7) { // spin
                if (ev[code_id].value < 0) {
                  printf("spin left\n");
                  event.type = DialEventType::left;
                  event.value = ev[code_id].value;
                  return event;
                }
                if (ev[code_id].value > 0) {
                  printf("spin right\n");
                  event.type = DialEventType::right;
                  event.value = ev[code_id].value;
                  return event; 
                }
            }
            if (key_code == 256) { // click
                if (ev[code_id].value == 1) {
                  printf("click down\n");
                  event.type = DialEventType::down;
                  event.value = ev[code_id].value;
                 return event; 
                }
                if (ev[code_id].value == 1) {
                  printf("click up\n");
                  event.type = DialEventType::up;
                  event.value = ev[code_id].value;
                  return event; 
                }
	    }
            if (ev[code_id].value == 0) // only break on key up...
            {
        //          std::cout << "KeyUtils:: breaking " << std::endl;
                break;
            }
            // else {
            //     std::cout << "KeyUtils:: waiting " << std::endl;
            // }
        }

      return event;
   //     return key_code;  
    } 



void updateDisplay( 
                   char *fbp, int col)
// void updateDisplay(fb_var_screeninfo& vinfo, 
//                    fb_fix_screeninfo& finfo, 
//                    char *fbp)
{
   printf("updateDisplay col: %i\n", col);
    long int location = 0;
    int x = 0, y = 0;
  x = 0; y = 0;       // Where we are going to put the pixel

// Figure out where in memory to put the pixel
for (y = 0; y < vinfo.height; y++)
    for (x = 0; x < vinfo.width; x++) {

        location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                (y+vinfo.yoffset) * finfo.line_length;
       // std::cout << x << ":" << y << ":" <<"Got location" << std::endl;
       if (vinfo.bits_per_pixel == 16){

         //   int r = 0;
         //   int g = 255;     // A little green
         //   int b = redOffset;    // A lot of red
//         unsigned short r = col;
//         unsigned short  g = col;
//	unsigned short  b = col;
//            unsigned short int t = r<<11 | g << 5 | b;

	    unsigned short int t = rgb_to_16bit(col, col, col);
            *((unsigned short int*)(fbp + location)) = t;
       }
        // if (vinfo.bits_per_pixel == 32) {
        //     *(fbp + location) = 100;        // Some blue
        //     *(fbp + location + 1) = 15+(x-100)/2;     // A little green
        //     *(fbp + location + 2) = redOffset-(y-100)/5;    // A lot of red
        //     *(fbp + location + 3) = 0;      // No transparency
        // } 

    }
}

int main()
{
    int fbfd = 0;
    // struct fb_var_screeninfo vinfo;
    // struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    //int x = 0, y = 0;
    //long int location = 0;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
                    fbfd, 0);
    if ((long int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    SimpleClock clock{};
    
    // clock.setCallback([vinfo, finfo, fbp](){
    //     updateDisplay(vinfo, finfo, fbp);
    // });
    ticks = 0;
    clock.setCallback([fbp](){

         std::cout << "tick " << ticks << std::endl;
//        updateDisplay(fbp, ticks);
        ticks = (ticks + 1) % 255;
    });
    
    clock.start(100);
    int input;

    // fire up the dial
    int file_ref = open("/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00", O_RDONLY);
    int col = 0;
    while(1){
        DialEvent dial = getChar(file_ref);
        switch(dial.type){
          case DialEventType::left:
           col += dial.value;
           break;
          case DialEventType::right:
           col += dial.value;
           break;
          case DialEventType::down:
           col = 0;
           break;
        }
//        printf("From dial: %i", getChar(file_ref));
        updateDisplay(fbp, col);
    }

    
    //    while(true){
    //    //std::cout << "Still going? 0 to stop " << std::endl;
    //    std::cin >> input; 
    //    if (input == 0) break; 
    //}
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}
