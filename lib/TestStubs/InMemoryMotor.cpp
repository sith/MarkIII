//
// Created by Fedorov, Alex on 10/14/20.
//

#include "InMemoryMotor.h"

bool InMemoryMotor::doesTurnRight() const {
    return leftWheelMovement == FORWARD && rightWheelMovement == BACKWARD;
}

bool InMemoryMotor::doesTurnLeft() const {
    return leftWheelMovement == BACKWARD && rightWheelMovement == FORWARD;
}

bool InMemoryMotor::doesNotMove() const {
    return speed == 0;
}

bool InMemoryMotor::goesForward() const {
    return leftWheelMovement == FORWARD && rightWheelMovement == FORWARD;
}

void InMemoryMotor::leftWheel(Movement movement, char speed) {
    leftWheelMovement = movement;
    InMemoryMotor::speed = speed;
}

void InMemoryMotor::rightWheel(Movement movement, char speed) {
    rightWheelMovement = movement;
    InMemoryMotor::speed = speed;
}

void InMemoryMotor::stop() {
    speed = 0;
}

