#include <DistanceUnits.h>
#include "InMemoryDistanceSensor.h"

Inch InMemoryDistanceSensor::getDistance() {
    return distance;
}

void InMemoryDistanceSensor::setDistance(Inch distance) {
    InMemoryDistanceSensor::distance = distance;
}
