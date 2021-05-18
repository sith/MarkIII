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

    currentDirection = smooth(heading);
}

int Compass::direction() {

    if (currentDirection < 0) {
        currentDirection += 2 * PI;
    }
    if (currentDirection > 2 * PI) {
        currentDirection -= 2 * PI;
    }
    return 360 - (currentDirection * 180 / PI);
}
