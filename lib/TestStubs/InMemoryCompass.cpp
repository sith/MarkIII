//
// Created by Fedorov, Alex on 10/14/20.
//

#include "InMemoryCompass.h"

InMemoryCompass::InMemoryCompass(int currentCourse) : currentDirection(currentCourse) {}

int InMemoryCompass::getCurrentCourse() const {
    return currentDirection;
}

int InMemoryCompass::direction() const {
    return currentDirection;
}

void InMemoryCompass::setDirection(int newDirection) {
    currentDirection = newDirection;
}
