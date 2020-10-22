//
// Created by Fedorov, Alex on 10/12/20.
//

#ifndef MARKIII_HCSR04_H
#define MARKIII_HCSR04_H

#include <Arduino.h>
#include <DistanceUnits.h>

class HCSR04 {
    const int trigPin;
    const int echoPin;
    unsigned int distance = 0;

    void readSensor();

public:
    HCSR04(int trigPin, int echoPin);

    Inch getDistance() const;

    void init();

    void process();
};

#endif //MARKIII_HCSR04_H
