//
// Created by Fedorov, Alex on 5/4/21.
//

#ifndef MARKIII_ROTATESTATE_H
#define MARKIII_ROTATESTATE_H

#include <State.h>
#include <Pilot.h>

template<class Motor, class Compass, class DistanceSensor>
class RotateState : public State {
    Pilot<Motor, Compass, DistanceSensor> &pilot;
    Compass &compass;
    int rotationAngle;
    int targetDirection = -1;

public:

    RotateState(Pilot<Motor, Compass, DistanceSensor> &pilot, Compass &compass, int rotationAngle) : pilot(pilot),
                                                                                                     compass(compass),
                                                                                                     rotationAngle(
                                                                                                             rotationAngle) {
    }

    bool isDone() override {
        if (targetDirection < 0) {
            targetDirection = compass.direction() + rotationAngle;
        }

        if (targetDirection == compass.direction()) {
            pilot.stop();
            targetDirection = -1;
            return true;
        }

        pilot.setTargetDirection(targetDirection);
        pilot.rotateRight();

        return false;
    }

};

#endif //MARKIII_ROTATESTATE_H
