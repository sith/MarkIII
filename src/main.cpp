#include <Arduino.h>
#include <Compass.h>
#include <HCSR04.h>
#include <LCDDisplay.h>
#include <L293DDualMotorDriver.h>
#include <StateMachine.h>
#include <RotateState.h>
#include <SystemMonitor.h>
#include <Timer.h>
#include <FollowTheTargetStateMachine.h>
#include "ErrorCodes.h"

Timer systemMonitorTimer{250};
LCDDisplay lcdDisplay;
Compass compass;
HCSR04 distanceSensor{2, 6};
L293DDualMotorDriver l293DDualMotorDriver;

SystemMonitor<LCDDisplay, Compass, Timer, HCSR04> systemMonitor{lcdDisplay,
                                                                compass,
                                                                systemMonitorTimer,
                                                                distanceSensor};
Pilot<L293DDualMotorDriver, Compass, HCSR04> pilot{l293DDualMotorDriver, compass, distanceSensor};

FollowTheTargetStateMachine<L293DDualMotorDriver, Compass, HCSR04> followTheTargetStateMachine{15, pilot,
                                                                                               distanceSensor};

void setup() {
    Serial.begin(9600);
    lcdDisplay.init();

    if (!compass.init()) {
        lcdDisplay.showErrorAndBlock(cannotInitializeCompassErrorCode);
    }

    systemMonitorTimer.start();
    distanceSensor.init();
    systemMonitor.init();
    l293DDualMotorDriver.init();

//    lcdDisplay.countDownToStart(5);
    lcdDisplay.clear();
}

void loop() {
    distanceSensor.process();
    compass.process();
    systemMonitor.process();

    followTheTargetStateMachine.process();
}
