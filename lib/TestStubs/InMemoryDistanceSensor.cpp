#include "InMemoryDistanceSensor.h"

int InMemoryDistanceSensor::getDistance() {
    return distance;
}

void InMemoryDistanceSensor::setDistance(int distance) {
    InMemoryDistanceSensor::distance = distance;
}
