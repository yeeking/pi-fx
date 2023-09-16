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
#include "SimpleClock.h"


struct input_event ev[64];


int ticks = 0;
enum class DialEventType
{
    left,
    right,
    down,
    up,
    unknown
};
struct DialEvent
{
    DialEventType type;
    signed int value;
};


DialEvent getChar(int file_ref)
{
    DialEvent event;
    event.type = DialEventType::unknown;
    event.value = 0; /* Some value you want to assign */

    int rd, code_id, ev_count, key_code;
    ev_count = 0;
    key_code = 0;
    // keep reading until
    // we get a key down or key held event
    while (1)
    {
        rd = read(file_ref, ev, sizeof(struct input_event) * 64);
        //            printf("%i  %i %i \n", ev->code, ev->type, ev->value);
        // printf("read %i\n", rd);
        if (rd > 48)
        {
            printf("Ignoring\n");
            continue; // holding lots of keys, ignore.
        }
        ev_count = rd / sizeof(struct input_event);
        printf("ev_count %i\n", ev_count);
        if (ev_count == 2)
        {
            code_id = 0;
        }
        else if (ev_count == 3)
        {
            code_id = 1;
        }
        // printf("\ncode id: %i", code_id);

        // .code tells you the key they pressed
        key_code = ev[code_id].code;
        // .value tells you key up, down, hold
        // 1 and 2 are key down or held events
        // if (ev[code_id].value == 1 || ev[code_id].value == 2)
        printf("KeyUtisl:: %i %i \n", key_code, ev[code_id].value);

        if (key_code == 7)
        { // spin
            if (ev[code_id].value < 0)
            {
                printf("spin left\n");
                event.type = DialEventType::left;
                event.value = ev[code_id].value;
                return event;
            }
            if (ev[code_id].value > 0)
            {
                printf("spin right\n");
                event.type = DialEventType::right;
                event.value = ev[code_id].value;
                return event;
            }
        }
        if (key_code == 256)
        { // click
            if (ev[code_id].value == 1)
            {
                printf("click down\n");
                event.type = DialEventType::down;
                event.value = ev[code_id].value;
                return event;
            }
            if (ev[code_id].value == 1)
            {
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
    }

    return event;
}



int main()
{

    FBScreen screen;
    
    int input;
    // fire up the dial
    int file_ref = open("/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00", O_RDONLY);
    int col = 0;
    while (1)
    {
        DialEvent dial = getChar(file_ref);
        switch (dial.type)
        {
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
        Color color = screen.rgb_to_16bit(col, 0, 0);
        screen.fillBackground(color);
    }


    return 0;
}
