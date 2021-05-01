//
// Created by Fedorov, Alex on 4/29/21.
//
#include <unity.h>
#include "DistanceSensortIntegrationTest.h"
#include "DisplayIntegrationTests.h"
#include "CompassIntegrationTests.h"

void setup() {}

void loop() {
    UNITY_BEGIN();
    distanceSensorIntegrationTests();
    displayIntegrationTests();
    compassIntegrationTests();
    UNITY_END();
}
