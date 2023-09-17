#pragma once 
#include <functional>
#include <iostream>
#include "screen.h"


class Knob {
    public:

    Knob(int x, int y, int diameter, Color color, int max=1000, std::function<void(int)>callback = [](int val){
                    std::cout << "Knob::default knob callback" << val << std::endl;
                }) 
        : x{x}, y{y}, diameter{diameter}, color{color}, max{max}, callback{callback}, value(0) {

    }
    void moveLeft(int amount = 1) {
        value -= amount; 
        if (value < 0) {
            value = 0;
        }
        callback(value);
    }

    void moveRight(int amount = 1) {
        value += amount;
        if (value > 999) {
            value = 999;
        }
        callback(value);
    }
    void draw(FBScreen* screen){
        screen->drawCircleOutline(x, y, diameter, color, diameter/10);
        screen->drawLine(x, y, value%360, diameter/2, color);
        screen->drawText(x-diameter/2, y+diameter/2+10, std::to_string(value), color);
    }
    int getValue(){
        return this->value; 
    }

    private:
    // FBScreen* screen;
    int x;
    int y;
    int diameter;
    Color color; 
    int max;
    std::function<void(int)>callback;
    int value; 
    
};
class UI{
    public:
    UI(FBScreen* screen) : screen {screen}{

    }

    void addComponent(Knob* knob){
        this->uiComps.push_back(knob);
    }
    void updateScreen(){
        Color black = screen->rgb_to_16bit(0, 0, 0);
        Color white = screen->rgb_to_16bit(255, 255, 255);
        
        screen->fillBackground(black);
        for (Knob* knob : uiComps){
            knob->draw(screen);
        }
        screen->drawText(25, 25, "0123456789", white);
    }

    private:
        FBScreen* screen;
        std::vector<Knob*> uiComps; 

};
