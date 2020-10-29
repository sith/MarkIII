#include <unity.h>
#include <Pilot.h>
#include <InMemoryCompass.h>
#include <InMemoryMotor.h>
#include <InMemoryDistanceSensor.h>
#include <HardwareSerial.h>
#include <SystemMonitor.h>
#include <InMemoryDisplay.h>
#include <FixedTimer.h>

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

void setup() {
    inMemoryCompass.setDirection(0);
    distanceSensor.setDistance(0);
    fixedTimer.setReady(false);
}

void printsDistanceAfterTimerIsTriggered() {
    int newDistance = 10;
    distanceSensor.setDistance(newDistance);
    fixedTimer.setReady(false);

    systemMonitor.process();

    TEST_ASSERT_EQUAL(0, inMemoryDisplay.getPrintedDistance());

    fixedTimer.setReady(true);

    Serial.println(fixedTimer.isReady());
    systemMonitor.process();

    TEST_ASSERT_EQUAL(newDistance, inMemoryDisplay.getPrintedDistance());
};


int main(int argc, char **argv) {
    UNITY_BEGIN();
    setup();
    RUN_TEST(printsDistanceAfterTimerIsTriggered);
    UNITY_END();
}

