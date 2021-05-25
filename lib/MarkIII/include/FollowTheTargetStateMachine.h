//
// Created by Fedorov, Alex on 5/18/21.
//

#ifndef MARKIII_FOLLOWTHETARGETSTATEMACHINE_H
#define MARKIII_FOLLOWTHETARGETSTATEMACHINE_H

#include <pid.h>
#include "Arduino.h"

template<typename Motor, typename Compass, typename DistanceSensor>
class FollowTheTargetStateMachine {
    Inch targetDistance;
    Pilot<Motor, Compass, DistanceSensor> &pilot;
    DistanceSensor &distanceSensor;
    PID pid{0.1,64, -64, 10, 0.0, 0.0};
    Timer timer{100};
public:
    FollowTheTargetStateMachine(Inch targetDistance, Pilot<Motor, Compass, DistanceSensor> &pilot,
                                DistanceSensor &distanceSensor) : targetDistance(
            targetDistance), pilot(pilot), distanceSensor(distanceSensor) {

    }

    void process() {

        Inch currentDistance = distanceSensor.getDistance();

        if (targetDistance == currentDistance) {
//            pilot.stop();
            Serial.println("Stop engines");
        } else {
            if (timer.isReady()) {
                double controlSignal = pid.calculate(targetDistance, currentDistance);
                Serial.print("Control signal: ");
                Serial.println(controlSignal);
            }

        }
    }

    double diff(double a, double b) const { return a - b; }
};

#endif //MARKIII_FOLLOWTHETARGETSTATEMACHINE_H
