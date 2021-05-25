//
// Created by Fedorov, Alex on 10/28/20.
//

#include "Timer.h"
#include <Arduino.h>

bool Timer::isReady() {
    unsigned long currentTime = millis();

    if (previousTime + duration > currentTime) {
        return false;
    }

    previousTime = currentTime;
    return true;
}

Timer::Timer(int duration) : duration(duration) {}

void Timer::start() {
    previousTime = millis();
}
