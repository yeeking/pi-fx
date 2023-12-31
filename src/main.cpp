/// This example uses the simpleclock class
/// to periodically draw a rectangle on the screen

#include <vector>
#include "screen.h"
#include "dial.h"
#include "ui.h"
#include "SimpleClock.h"
#include "osc.h"

int main()
{

    OSCClient oscClient(57110);

    FBScreen screen;
    Color black = screen.rgb_to_16bit(0, 0, 0);
    Color red = screen.rgb_to_16bit(255, 0, 0);
    Color blue = screen.rgb_to_16bit(0, 0, 255);
    
    screen.fillBackground(black);
    UI ui{&screen};
    Knob knob1{80, 120, 100, red};
    Knob knob2{240, 120, 100, blue};
    int currentKnob = 0;
    std::vector<Knob*> knobs;
    knobs.push_back(&knob1);
    knobs.push_back(&knob2);
    
    
    ui.addComponent(&knob1);
    ui.addComponent(&knob2);

    SimpleClock clock{};
    clock.setCallback([&ui](){
       ui.updateScreen();
    });
    
    clock.start(250);


    int input;
    // fire up the dial
    int dialDev = open("/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00", O_RDONLY);
    // starter code for receiving data from wiomouse device
    // int dialDev = open("/dev/input/by-id/usb-Seeed_Studio_Seeed_Wio_Terminal_F3D9BE68533346484E202020FF154240-if02-event-mouse", O_RDONLY);
    
    while (1)
    {
        DialEvent dialEvent = getDialEvent(dialDev);
        switch (dialEvent.type)
        {
        case DialEventType::left:
            knobs[currentKnob]->moveLeft(-1 * dialEvent.value);
            break;
        case DialEventType::right:
            knobs[currentKnob]->moveRight(dialEvent.value);
            break;
        case DialEventType::down:
            // std::cout << "DOWN" << std::endl;
            currentKnob = (currentKnob + 1)% knobs.size();
            //col = 0;
            break;
        }
        oscClient.setBus(1, knobs[0]->getValue());
        oscClient.setBus(2, knobs[1]->getValue());

   }

    return 0;
}
