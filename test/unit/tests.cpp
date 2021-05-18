//
// Created by Fedorov, Alex on 4/29/21.
//
#include <unity.h>
#include "TimerTest.h"
#include "PilotTest.h"
#include "SystemMonitorTests.h"
#include "StateMachineTests.h"
#include "RotateStateTests.h"
#include "SmoothingFunctionTest.h"
#include "FollowTheTargetStateMachineTests.h"
#include <pid.h>


void setup() {}

void loop() {
    UNITY_BEGIN();
    timerTests();
    pilotTests::tests();
    systemMonitor::tests();
    stateMachineTests();
    rotateStateTests();
    smoothingFunction::tests();
    followthetargetstatemachine::tests();
    UNITY_END();
}
