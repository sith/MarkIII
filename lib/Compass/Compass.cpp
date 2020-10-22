//
// Created by Fedorov, Alex on 10/15/20.
//

#include "Compass.h"

void Compass::init() {
    compass.init();
    compass.setCalibration(-1923, 0, -9281, 0, -6983, 0);

    readSensor();
}

void Compass::readSensor() {
    compass.read();
    currentDirection = compass.getAzimuth();
}

void Compass::process() {
    readSensor();
}

int Compass::direction() {
    return currentDirection;
}
