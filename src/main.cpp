#include <Arduino.h>
#include <Compass.h>
#include <HCSR04.h>

void setup(){
    Serial.begin(115200);

    Compass compass;
    HCSR04 distanceSensor{2,6};


}

void loop(){

}
