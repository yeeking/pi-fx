/// This example uses the simpleclock class
/// to periodically draw a rectangle on the screen


#include "screen.h"
#include "dial.h"
#include "ui.h"
#include "SimpleClock.h"

int main()
{

    FBScreen screen;
    Color black = screen.rgb_to_16bit(0, 0, 0);
    Color red = screen.rgb_to_16bit(255, 0, 0);
    
    screen.fillBackground(black);
    Knob knob1{160, 120, 100, red};
    
    int input;
    // fire up the dial
    int dialDev = open("/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00", O_RDONLY);
    while (1)
    {
        DialEvent dialEvent = getDialEvent(dialDev);
        switch (dialEvent.type)
        {
        case DialEventType::left:
            knob1.moveLeft(-1 * dialEvent.value);
            break;
        case DialEventType::right:
            knob1.moveRight(dialEvent.value);
            break;
        case DialEventType::down:
            //col = 0;
            break;
        }
        screen.fillBackground(black);
        knob1.draw(screen);
                // screen.drawCircle(50, 50, 25, color);
        //screen.drawCircleOutline(160, 120, 100, color, 15);
    }

    return 0;
}
