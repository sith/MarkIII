#include <Arduino.h>
#include <Compass.h>
#include <HCSR04.h>
#include <LCDDisplay.h>
#include <L293DDualMotorDriver.h>
#include <SquareRunnerMode.h>
#include <StateMachine.h>
#include "ErrorCodes.h"

void setup() {
    LCDDisplay lcdDisplay;
    lcdDisplay.init();
    lcdDisplay.showWelcomeMessage();

    Compass compass;
    if (compass.init()) {
        lcdDisplay.showErrorAndBlock(cannotInitializeCompassErrorCode);
    }
    HCSR04 distanceSensor{2, 6};

    L293DDualMotorDriver l293DDualMotorDriver;
    l293DDualMotorDriver.init();
//    StateMachine stateMachine{};

}

void loop() {

}
