//
// Created by Fedorov, Alex on 10/12/20.
//

#ifndef MARKIII_HCSR04_H
#define MARKIII_HCSR04_H

#include <Arduino.h>

class HCSR04 {

    const int trigPin;
    const int echoPin;

public:
    HCSR04(const int trigPin, const int echoPin) : trigPin(trigPin), echoPin(echoPin) {
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }


    double measureDistance() {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        unsigned long duration = pulseIn(echoPin, HIGH);
        return (duration * .0343) / 2;
    };
};

#endif //MARKIII_HCSR04_H
