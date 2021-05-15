//
// Created by Fedorov, Alex on 4/29/21.
//

#ifndef MARKIII_DISPLAYINTEGRATIONTESTS_H
#define MARKIII_DISPLAYINTEGRATIONTESTS_H

#include <unity.h>
#include <LCDDisplay.h>

void noErrorsWhenInitializingDisplay() {
    LCDDisplay display;
    TEST_ASSERT_EQUAL(0, display.init());
};


void displayIntegrationTests() {
    RUN_TEST(noErrorsWhenInitializingDisplay);
}

#endif //MARKIII_DISPLAYINTEGRATIONTESTS_H
