#include <Arduino.h>
#include <Compass.h>
#include <Messages.h>
#include <L293DDualMotorDriver.h>
#include <Pilot.h>
#include <LCDDisplay.h>
#include <HCSR04.h>

HCSR04 distanceSensor{2, 6};
L293DDualMotorDriver motorDriver;
Compass compass{};
Pilot<L293DDualMotorDriver, Compass, HCSR04> pilot{motorDriver, compass, distanceSensor};

LCDDisplay lcdDisplay;

void setup() {
    Serial.begin(9600);
    Wire.begin();

    lcdDisplay.init();
    lcdDisplay.showWelcomeMessage();
    motorDriver.init();
    distanceSensor.init();
    pilot.start();
    pilot.setSpeed((char) 128);

    lcdDisplay.countDownToStart(5);
    lcdDisplay.clear();
}

void loop() {
    distanceSensor.process();

    pilot.process();
}
