//
// Created by Fedorov, Alex on 10/14/20.
//

#include "InMemoryMotor.h"

InMemoryMotor::InMemoryMotor() {}

void InMemoryMotor::turnRight(char speed) {
    InMemoryMotor::speed = speed;
    leftWheelMovement = FORWARD;
    rightWheelMovement = BACKWARD;
}

void InMemoryMotor::turnLeft(char speed) {
    InMemoryMotor::speed = speed;
    leftWheelMovement = BACKWARD;
    rightWheelMovement = FORWARD;
}


bool InMemoryMotor::doesTurnRight() const {
    return leftWheelMovement == FORWARD && rightWheelMovement == BACKWARD;
}

bool InMemoryMotor::doesTurnLeft() const {
    return leftWheelMovement == BACKWARD && rightWheelMovement == FORWARD;
}

bool InMemoryMotor::doesNotMove() const {
    return leftWheelMovement == NO_MOVEMENT && rightWheelMovement == NO_MOVEMENT;
}

bool InMemoryMotor::goesForward() const {
    return leftWheelMovement == FORWARD && rightWheelMovement == FORWARD;
}

char InMemoryMotor::getSpeed() const {
    return speed;
}

void InMemoryMotor::forward(char speed) {
    InMemoryMotor::speed = speed;
    leftWheelMovement = FORWARD;
    rightWheelMovement = FORWARD;
}

void InMemoryMotor::stop() {
    leftWheelMovement = NO_MOVEMENT;
    rightWheelMovement = NO_MOVEMENT;
    speed = 0;
}
