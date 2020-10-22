#ifndef MARKIII_COMPASS_H
#define MARKIII_COMPASS_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <BlinkMessenger.h>
#include <QMC5883LCompass.h>

class Compass {
    QMC5883LCompass compass;
    int currentDirection;

    void readSensor();

public:

    void init();

    void process();

    int direction();
};

#endif //MARKIII_COMPASS_H
