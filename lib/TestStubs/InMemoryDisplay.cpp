#include "InMemoryDisplay.h"

unsigned int InMemoryDisplay::getPrintedDistance() const {
    return printedDistance;
}

void InMemoryDisplay::showDistanceToObstacle(unsigned int distance) {
    InMemoryDisplay::printedDistance = distance;
}

