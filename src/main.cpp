#include <Arduino.h>
#include <L293DDriver.h>
#include <HMC5883L.h>
#include <HCSR04.h>
#include <LCDDisplay.h>


HMC5883L compass;
HCSR04 distanceSensor{8, 9};
LCDDisplay hd44780;
L293DDriver motorDriver;


void setup() {
    Serial.begin(9600);
}

void loop() {


}

void setupHMC5883L() {
    //Setup the HMC5883L, and check for errors
    int error;
    error = compass.SetScale(1.3); //Set the scale of the compass.
    if (error != 0) Serial.println(compass.GetErrorText(error)); //check if there is an error, and print if so

    error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
    if (error != 0) Serial.println(compass.GetErrorText(error)); //check if there is an error, and print if so
}
