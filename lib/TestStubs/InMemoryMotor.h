//
// Created by Fedorov, Alex on 10/14/20.
//

#ifndef MARKIII_INMEMORYMOTOR_H
#define MARKIII_INMEMORYMOTOR_H

#include <Movement.h>
#include <InMemoryCompass.h>

class InMemoryMotor {
public:
    Movement leftWheelMovement = FORWARD;
    Movement rightWheelMovement = FORWARD;
    unsigned char leftWheelSpeed = 0;
    unsigned char rightWheelSpeed = 0;

    bool doesRotateRight() const;

    bool doesRotateLeft() const;

    bool doesNotMove() const;

    bool goesForward() const;

    bool goesBackward() const;

    void leftWheel(Movement movement, unsigned char speed);

    void rightWheel(Movement movement, unsigned char speed);

    void stop();

    bool isRunning();

    unsigned char getLeftWheelSpeed() const;

    unsigned char getRightWheelSpeed() const;


};


#endif //MARKIII_INMEMORYMOTOR_H
