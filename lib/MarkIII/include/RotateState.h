//
// Created by Fedorov, Alex on 5/4/21.
//

#ifndef MARKIII_ROTATESTATE_H
#define MARKIII_ROTATESTATE_H

static const int maxDirection = 360;

#include <State.h>
#include <Pilot.h>
#include <Arduino.h>


template<class Motor, class Compass, class DistanceSensor, class Display>
class RotateState : public State {
    Pilot<Motor, Compass, DistanceSensor> &pilot;
    Compass &compass;
    Display &display;
    int rotationAngle;
    int targetDirection = -1;
    int currentDirection = -1;
    double output = 0.0;
    int threshold = 1;


public:
    RotateState(Pilot<Motor, Compass, DistanceSensor> &pilot, Compass &compass, int rotationAngle, Display &display)
            : pilot(pilot),
              compass(compass),
              rotationAngle(rotationAngle),
              display(display) {
    }

    void setRotationAngle(int rotationAngle) {
        RotateState::rotationAngle = rotationAngle;
    }

    bool isDone() override {
        currentDirection = compass.direction();
        if (targetDirection < 0) {
            targetDirection = currentDirection + rotationAngle;
            if (targetDirection < 0) {
                targetDirection += maxDirection;
            }
            if (targetDirection >= maxDirection) {
                targetDirection -= maxDirection;
            }

            display.log("TD ", targetDirection);
            pilot.setSpeed(medium);
        }

        int diff = abs(targetDirection - currentDirection);
        if (diff > 180) {
            diff = maxDirection - diff;
        }
        if (diff <= threshold) {
            pilot.stop();
            targetDirection = -1;
            return true;
        }

        pilot.setTargetDirection(targetDirection);

        if (rotationAngle > 0) {
            pilot.rotateRight();
        } else {
            pilot.rotateLeft();
        }
        return false;
    }

};

#endif //MARKIII_ROTATESTATE_H
