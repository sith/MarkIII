#include <unity.h>
#include <Timer.h>
#include <Arduino.h>

void testTimer() {
    Timer timer{250};
    timer.init();
    delay(50);
    TEST_ASSERT_FALSE(timer.isReady());
    delay(250);
    TEST_ASSERT(timer.isReady())
}

void setup(){}

void loop(){
    UNITY_BEGIN();
    RUN_TEST(testTimer);
    UNITY_END();
}

