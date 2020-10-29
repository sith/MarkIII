#include <Arduino.h>
#include <Compass.h>
#include <Messages.h>
#include <L293DDualMotorDriver.h>
#include <Pilot.h>
#include <LCDDisplay.h>
#include <HCSR04.h>
#include <SystemMonitor.h>
#include <Timer.h>

HCSR04 distanceSensor{2, 6};
L293DDualMotorDriver motorDriver;
Compass compass{};
Pilot<L293DDualMotorDriver, Compass, HCSR04> pilot{motorDriver, compass, distanceSensor};

LCDDisplay lcdDisplay;

Timer systemMonitorTimer{250};

SystemMonitor<LCDDisplay, Compass, Timer, L293DDualMotorDriver, HCSR04> systemMonitor{lcdDisplay,
                                                                                      compass,
                                                                                      systemMonitorTimer,
                                                                                      motorDriver,
                                                                                      distanceSensor};

void setup() {
    Serial.begin(9600);
    Wire.begin();

    lcdDisplay.init();
    lcdDisplay.showWelcomeMessage();
    motorDriver.init();
    distanceSensor.init();
    systemMonitor.init();

    pilot.start();
    pilot.setSpeed((char) 128);

    lcdDisplay.countDownToStart(5);
    lcdDisplay.clear();
}

void loop() {
    distanceSensor.process();

    systemMonitor.process();
    pilot.process();
}
