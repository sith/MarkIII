//
// Created by Fedorov, Alex on 4/29/21.
//

#ifndef MARKIII_SYSTEMMONITORTESTS_H
#define MARKIII_SYSTEMMONITORTESTS_H

#include <unity.h>
#include <Pilot.h>
#include <InMemoryCompass.h>
#include <InMemoryMotor.h>
#include <InMemoryDistanceSensor.h>
#include <SystemMonitor.h>
#include <InMemoryDisplay.h>
#include <FixedTimer.h>

namespace systemMonitor {
    InMemoryDisplay inMemoryDisplay;
    InMemoryCompass inMemoryCompass{0};
    FixedTimer fixedTimer;
    InMemoryMotor inMemoryMotor;
    InMemoryDistanceSensor distanceSensor;
    SystemMonitor<InMemoryDisplay, InMemoryCompass, FixedTimer, InMemoryMotor, InMemoryDistanceSensor> systemMonitor{
            inMemoryDisplay,
            inMemoryCompass,
            fixedTimer,
            inMemoryMotor,
            distanceSensor};

    void printsDistanceAfterTimerIsTriggered() {
        int newDistance = 10;
        distanceSensor.setDistance(newDistance);
        fixedTimer.setReady(false);

        systemMonitor.process();

        TEST_ASSERT_EQUAL(0, inMemoryDisplay.getPrintedDistance());

        fixedTimer.setReady(true);

        systemMonitor.process();

        TEST_ASSERT_EQUAL(newDistance, inMemoryDisplay.getPrintedDistance());
    };

    void printMotorIsRunning() {
        fixedTimer.setReady(true);
        inMemoryMotor.leftWheel(BACKWARD, 128);
        inMemoryMotor.rightWheel(FORWARD, 0);

        systemMonitor.process();

        TEST_ASSERT(inMemoryDisplay.registeredMotorState());
    }

    void printMotorIsStopped() {
        fixedTimer.setReady(true);
        inMemoryMotor.leftWheel(FORWARD, 0);
        inMemoryMotor.rightWheel(FORWARD, 0);

        systemMonitor.process();

        TEST_ASSERT_FALSE(inMemoryDisplay.registeredMotorState());
    }

    void before() {
        inMemoryCompass.setDirection(0);
        distanceSensor.setDistance(0);
        fixedTimer.setReady(false);
    }

    void tests() {
        before();
        RUN_TEST(printsDistanceAfterTimerIsTriggered);
        before();
        RUN_TEST(printMotorIsRunning);
        before();
        RUN_TEST(printMotorIsStopped);
    }
}
#endif //MARKIII_SYSTEMMONITORTESTS_H
