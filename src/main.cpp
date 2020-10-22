#include <Arduino.h>
#include <Compass.h>
#include <Messages.h>
#include <L293DDriver.h>
#include <Pilot.h>
#include <LCDDisplay.h>
#include <HCSR04.h>

L293DDriver motorDriver;
Compass compass{};
HCSR04 distanceSensor{2, 6};
Pilot<L293DDriver, Compass, HCSR04> pilot{motorDriver, compass, distanceSensor};

LCDDisplay lcdDisplay;

void setup() {
    Serial.begin(9600);
    Wire.begin();

    lcdDisplay.init();

    lcdDisplay.showWelcomeMessage();

    //    compass.init();
//    pilot.start();

    lcdDisplay.clear();


}

void loop() {

}
