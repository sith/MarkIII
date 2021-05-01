//
// Created by Fedorov, Alex on 4/29/21.
//
#include <unity.h>
#include "TimerTest.h"
#include "PilotTest.h"
#include "SystemMonitorTests.h"

void setup() {}

void loop() {
    UNITY_BEGIN();
    timerTests();
    pilotTests();
    systemMonitorTests();
    UNITY_END();
}
