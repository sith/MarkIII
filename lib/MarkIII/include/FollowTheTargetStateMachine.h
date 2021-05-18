//
// Created by Fedorov, Alex on 5/18/21.
//

#ifndef MARKIII_FOLLOWTHETARGETSTATEMACHINE_H
#define MARKIII_FOLLOWTHETARGETSTATEMACHINE_H

template<typename Motor, typename Compass, typename DistanceSensor>
class FollowTheTargetStateMachine {
    Inch targetDistance;
    Pilot<Motor, Compass, DistanceSensor> &pilot;
    DistanceSensor &distanceSensor;
public:
    FollowTheTargetStateMachine(Inch targetDistance, Pilot<Motor, Compass, DistanceSensor> &pilot,
                                DistanceSensor &distanceSensor) : targetDistance(
            targetDistance), pilot(pilot), distanceSensor(distanceSensor) {

    }

    void process() {

        Inch currentDistance = distanceSensor.getDistance();

        if (targetDistance == currentDistance) {
            pilot.stop();
        } else if (targetDistance < currentDistance) {
            Serial.println("Should go forward");
            pilot.setSpeed(medium);
            pilot.forward();
        } else {
            Serial.println("Should go backwards");
            pilot.setSpeed(medium);
            pilot.backwards();
        }
    }
};

#endif //MARKIII_FOLLOWTHETARGETSTATEMACHINE_H
