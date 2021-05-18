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
    InMemoryDisplay inMemoryDisplay{};
    InMemoryCompass inMemoryCompass{0};
    FixedTimer fixedTimer;
    InMemoryDistanceSensor distanceSensor;
    SystemMonitor<InMemoryDisplay, InMemoryCompass, FixedTimer, InMemoryDistanceSensor> systemMonitor{
            inMemoryDisplay,
            inMemoryCompass,
            fixedTimer,
            distanceSensor}
;

    void printsDistanceAfterTimerIsTriggered() {
        int newDistance = 10;
        distanceSensor.setDistance(newDistance);
        fixedTimer.setReady(false);

        systemMonitor.process();

        TEST_ASSERT_EQUAL(0, inMemoryDisplay.getPrintedSystemState().distanceToObstacle);

        fixedTimer.setReady(true);

        systemMonitor.process();

        TEST_ASSERT_EQUAL(newDistance, inMemoryDisplay.getPrintedSystemState().distanceToObstacle);
    };


    void before() {
        inMemoryCompass.setDirection(0);
        distanceSensor.setDistance(0);
        fixedTimer.setReady(false);
    }

    void tests() {
        before();
        RUN_TEST(printsDistanceAfterTimerIsTriggered);
    }
}
#endif //MARKIII_SYSTEMMONITORTESTS_H
