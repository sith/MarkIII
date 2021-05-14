#include <Arduino.h>
#include <Compass.h>
#include <HCSR04.h>
#include <LCDDisplay.h>
#include <L293DDualMotorDriver.h>
#include <StateMachine.h>
#include <RotateState.h>
#include <SystemMonitor.h>
#include <Timer.h>
#include "ErrorCodes.h"

Timer systemMonitorTimer{250};
LCDDisplay lcdDisplay;
Compass compass;
HCSR04 distanceSensor{2, 6};
L293DDualMotorDriver l293DDualMotorDriver;

SystemMonitor<LCDDisplay, Compass, Timer, L293DDualMotorDriver, HCSR04> systemMonitor{lcdDisplay, compass,
                                                                                      systemMonitorTimer,
                                                                                      l293DDualMotorDriver,
                                                                                      distanceSensor};;
Pilot<L293DDualMotorDriver, Compass, HCSR04> pilot{l293DDualMotorDriver, compass, distanceSensor};

RotateState<L293DDualMotorDriver, Compass, HCSR04> rotateState{pilot, compass, 90};

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
    lcdDisplay.countDownToStart(5);

    lcdDisplay.showWelcomeMessage();
    lcdDisplay.clear();
}

void loop() {
    distanceSensor.process();
    compass.process();
    systemMonitor.process();
    pilot.setSpeed(medium);
    pilot.forward();
}
