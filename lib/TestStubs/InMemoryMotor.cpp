//
// Created by Fedorov, Alex on 10/14/20.
//

#include "InMemoryMotor.h"

bool InMemoryMotor::doesRotateRight() const {
    return leftWheelMovement == FORWARD && rightWheelMovement == BACKWARD && leftWheelSpeed > 0 && rightWheelSpeed > 0;
}

bool InMemoryMotor::doesRotateLeft() const {
    return leftWheelMovement == BACKWARD && rightWheelMovement == FORWARD && leftWheelSpeed > 0 && rightWheelSpeed > 0;
}

bool InMemoryMotor::doesNotMove() const {
    return leftWheelSpeed == 0 && rightWheelSpeed == 0;
}

bool InMemoryMotor::goesForward() const {
    return leftWheelMovement == FORWARD && rightWheelMovement == FORWARD && leftWheelSpeed > 0 &&
           rightWheelSpeed > 0 and leftWheelSpeed == rightWheelSpeed;
}

void InMemoryMotor::leftWheel(Movement movement, unsigned char speed) {
    leftWheelMovement = movement;
    InMemoryMotor::leftWheelSpeed = speed;
}

void InMemoryMotor::rightWheel(Movement movement, unsigned char speed) {
    rightWheelMovement = movement;
    InMemoryMotor::rightWheelSpeed = speed;
}

void InMemoryMotor::stop() {
    leftWheelSpeed = 0;
    rightWheelSpeed = 0;
}

unsigned char InMemoryMotor::getLeftWheelSpeed() const {
    return leftWheelSpeed;
}

unsigned char InMemoryMotor::getRightWheelSpeed() const {
    return rightWheelSpeed;
}

bool InMemoryMotor::isRunning() {
    return leftWheelSpeed > 0 || rightWheelSpeed > 0;
}
