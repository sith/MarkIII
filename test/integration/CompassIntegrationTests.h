//
// Created by Fedorov, Alex on 5/1/21.
//

#ifndef MARKIII_COMPASSINTEGRATIONTESTS_H
#define MARKIII_COMPASSINTEGRATIONTESTS_H

#include <unity.h>
#include <Compass.h>

void noErrorsWhenInitializingCompass() {
    Compass compass;

    bool initStatus = compass.init();
    TEST_ASSERT(initStatus);

    int initial_direction = compass.direction();
    TEST_ASSERT_NOT_EQUAL(initial_direction, -1);
};


void compassIntegrationTests() {
    RUN_TEST(noErrorsWhenInitializingCompass);
}

#endif //MARKIII_COMPASSINTEGRATIONTESTS_H
