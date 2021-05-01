#ifndef MARKIII_COMPASS_H
#define MARKIII_COMPASS_H

#include <Adafruit_LIS2MDL.h>

class Compass {
    Adafruit_LIS2MDL compass{12345};
    double currentDirection = -1.0;

    const float xMin = -88.35;
    const float xMax = 29.55;
    const float yMin = -75.00;
    const float yMax = 35.55;
    const float declinationAngle = -0.2714;
public:

    bool init();

    void process();

    double direction();
};

#endif //MARKIII_COMPASS_H
