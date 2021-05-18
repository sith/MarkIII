//
// Created by Fedorov, Alex on 5/16/21.
//

#ifndef MARKIII_LEFTRIGHTROTATIONSTATEMACHINE_H
#define MARKIII_LEFTRIGHTROTATIONSTATEMACHINE_H

#include <RotateState.h>
#include <Pilot.h>

template<class Motor, class Compass, class DistanceSensor, class Display>
class LeftRightRotationStateMachine {
    RotateState<Motor, Compass, DistanceSensor, Display> rotateState;
    int angle;
public:

    LeftRightRotationStateMachine(int angle, Pilot<Motor, Compass, DistanceSensor> &pilot, Compass &compass,
                                  Display &display) :
            angle(angle),
            rotateState{pilot, compass, angle,display} {
    }

public:
    void process() {
        if (rotateState.isDone()) {
            angle = angle * -1;
            rotateState.setRotationAngle(angle);
        }
    }
};

#endif //MARKIII_LEFTRIGHTROTATIONSTATEMACHINE_H
