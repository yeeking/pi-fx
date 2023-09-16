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

#include "draw.h"
#include "dial.h"
#include "SimpleClock.h"

int main()
{

    FBScreen screen;
    Color color = screen.rgb_to_16bit(0, 0, 0);
    screen.fillBackground(color);
        
    int input;
    // fire up the dial
    int dialDev = open("/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00", O_RDONLY);
    int col = 0;
    while (1)
    {
        DialEvent dialEvent = getDialEvent(dialDev);
        switch (dialEvent.type)
        {
        case DialEventType::left:
            col += dialEvent.value;
            break;
        case DialEventType::right:
            col += dialEvent.value;
            break;
        case DialEventType::down:
            col = 0;
            break;
        }
        Color color = screen.rgb_to_16bit(col, 0, 0);
        //screen.fillBackground(color);
        // screen.drawCircle(50, 50, 25, color);
        screen.drawCircleOutline(160, 120, 100, color, 15);
    }

    return 0;
}
