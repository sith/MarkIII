#include "InMemoryDisplay.h"

unsigned int InMemoryDisplay::getPrintedDistance() const {
    return printedDistance;
}

void InMemoryDisplay::showDistanceToObstacle(unsigned int distance) {
    InMemoryDisplay::printedDistance = distance;
}

void InMemoryDisplay::showMotorState(bool motorIsMoving) {
    InMemoryDisplay::printedMotorIsRunningState = motorIsMoving;
}

bool InMemoryDisplay::registeredMotorState() const {
    return printedMotorIsRunningState;
}

