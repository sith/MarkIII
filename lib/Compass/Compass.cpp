//
// Created by Fedorov, Alex on 10/15/20.
//

#include "Compass.h"

bool Compass::init() {
    if (!compass.begin()) {
        return false;
    }

    process();
    return true;
}

void Compass::process() {
    sensors_event_t event;
    compass.getEvent(&event);

    double heading = atan2((event.magnetic.y - ((yMax + yMin) / 2.0)), (event.magnetic.x - ((xMax + xMin) / 2.0)));

    heading += declinationAngle;

    if (heading < 0) {
        heading += 2 * PI;
    }
    if (heading > 2 * PI) {
        heading -= 2 * PI;
    }
    currentDirection = heading * 180 / M_PI; // Convert radians to degrees.
}

double Compass::direction() {
    return currentDirection;
}
