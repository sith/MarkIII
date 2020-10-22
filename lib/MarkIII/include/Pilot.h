#ifndef MARKIII_PILOT_H
#define MARKIII_PILOT_H

#include <Movement.h>
#include <DistanceUnits.h>

template<typename Motor, typename Compass, typename DistanceSensor>
class Pilot {
    Motor &motor;
    Compass &compass;
    DistanceSensor &distanceSensor;
    int targetDirection = 0;
    char speed = 0;
    bool started = false;
    Inch criticalDistance = 10;
public:
    Pilot(Motor &motor, Compass &compass, DistanceSensor &distanceSensor)
            : motor(motor), compass(compass), distanceSensor(distanceSensor) {}

    int getTargetDirection() const {
        return targetDirection;
    }

    void setTargetDirection(int direction) {
        Pilot::targetDirection = direction;
    }

    char getSpeed() const {
        return speed;
    }

    void setSpeed(char speed) {
        Pilot::speed = speed;
    }

    void start() {
        started = true;
    }

    void process() {
        if (!started) {
            return;
        }

        if (distanceSensor.getDistance() < criticalDistance) {
            motor.stop();
            return;
        }

        int currentDirection = compass.direction();
        int delta = targetDirection - currentDirection;

        if (delta > 180) {
            delta = 180 - delta;
        }

        if (delta > 0) {
            motor.turnRight(speed);
        } else if (delta < 0) {
            motor.turnLeft(speed);
        } else {
            motor.forward(speed);
        }
    }


};


#endif //MARKIII_PILOT_H
