
#ifndef MARKIII_TIMERTEST1_H
#define MARKIII_TIMERTEST1_H

#include "unity.h"
#include "Timer.h"
#include "Arduino.h"

void testTimer() {
    Timer timer{250};
    timer.init();
    delay(50);
    TEST_ASSERT_FALSE(timer.isReady());
    delay(250);
    TEST_ASSERT(timer.isReady())
}

void timerTests() {
    RUN_TEST(testTimer);
}

#endif //MARKIII_TIMERTEST1_H
