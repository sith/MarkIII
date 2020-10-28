//
// Created by Fedorov, Alex on 10/12/20.
//

#include "L293DDualMotorDriver.h"
#include <Arduino.h>

void L293DDualMotorDriver::leftWheel(Movement movement, char speed) {
    controlMotor(movement, speed, leftIn1, leftIn2, leftEn);
}

void L293DDualMotorDriver::rightWheel(Movement movement, char speed) {
    controlMotor(movement, speed, rightIn1, rightIn2, rightEn);
}

void L293DDualMotorDriver::controlMotor(const Movement &movement, char speed, int in1, int in2, int en) {
    if (speed == 0) {
        stopMotor(in1, in2, en);
    }
    switch (movement) {
        case FORWARD:
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            break;
        case BACKWARD:
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            break;
    }
    analogWrite(en, speed);
}

void L293DDualMotorDriver::stopMotor(int in1, int in2, int en) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(en, 0);
}

void L293DDualMotorDriver::init() {

    // Set all the motor control pins to outputs
    pinMode(leftEn, OUTPUT);
    pinMode(rightEn, OUTPUT);
    pinMode(leftIn1, OUTPUT);
    pinMode(leftIn2, OUTPUT);
    pinMode(rightIn1, OUTPUT);
    pinMode(rightIn2, OUTPUT);

    // Turn off motors - Initial state
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, LOW);
    digitalWrite(rightIn1, LOW);
    digitalWrite(rightIn2, LOW);


}

void L293DDualMotorDriver::stop() {
    stopMotor(leftIn1, leftIn2, leftEn);
    stopMotor(rightIn1, rightIn2, rightEn);
}
