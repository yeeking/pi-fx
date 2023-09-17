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
    void draw(FBScreen& screen){
        screen.drawCircleOutline(x, y, diameter, color, diameter/10);
        screen.drawLine(x, y, value%360, diameter/2, color);
        std::cout << "Knob::draw" << value << std::endl;
    }


    private:
    int x;
    int y;
    int diameter;
    Color color; 
    int max;
    std::function<void(int)>callback;
    int value; 
    
};