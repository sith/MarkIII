//
// Created by Fedorov, Alex on 10/28/20.
//

#include "Timer.h"
#include <Arduino.h>

bool Timer::isReady() {
    unsigned long currentTime = millis();

    if (previousTime + delay > currentTime) {
        return false;
    }

    previousTime = currentTime;
    return true;
}

Timer::Timer(int delay) : delay(delay) {}

void Timer::init() {
    previousTime = millis();
}
