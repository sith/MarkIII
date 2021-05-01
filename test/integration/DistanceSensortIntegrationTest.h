#ifndef MARKIII_DISTANCESENSORTINTEGRATIONTEST_H
#define MARKIII_DISTANCESENSORTINTEGRATIONTEST_H

#include <unity.h>
#include <HCSR04.h>
HCSR04 distanceSensor{2, 6};

void nonZeroDistance() {
    distanceSensor.init();
    distanceSensor.process();
    Inch distance = distanceSensor.getDistance();
    TEST_ASSERT(distance > 0);
}


void distanceSensorIntegrationTests(){
    RUN_TEST(nonZeroDistance);
}
#endif //MARKIII_DISTANCESENSORTINTEGRATIONTEST_H
