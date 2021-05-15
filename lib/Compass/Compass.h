#ifndef MARKIII_COMPASS_H
#define MARKIII_COMPASS_H

#include <Adafruit_LIS2MDL.h>
#include "SmoothingFunction.h"

class Compass {
    Adafruit_LIS2MDL compass{12345};
    double currentDirection = 0.0;

    const float xMin = -10.35;
    const float xMax = 110.55;
    const float yMin = -107.70;
    const float yMax = 7.20;
    const float declinationAngle = -0.2714;

    SmoothingFunction<20> smooth;

public:

    bool init();

    void process();

    int direction();
};

#endif //MARKIII_COMPASS_H
