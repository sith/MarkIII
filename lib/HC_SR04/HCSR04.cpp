//
// Created by Fedorov, Alex on 10/12/20.
//

#include "HCSR04.h"

HCSR04::HCSR04(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {
}

Inch HCSR04::getDistance() const {
    return distance;
}

void HCSR04::init() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    readSensor();
}

void HCSR04::process() {
    readSensor();
}

void HCSR04::readSensor() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    unsigned long duration = pulseIn(echoPin, HIGH);
    distance = duration / (74 * 2);
}
