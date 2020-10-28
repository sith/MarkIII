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
    char speed = 0;

    bool doesTurnRight() const;

    bool doesTurnLeft() const;

    bool doesNotMove() const;

    bool goesForward() const;

    void leftWheel(Movement movement, char speed);

    void rightWheel(Movement movement, char speed);

    void stop();
};


#endif //MARKIII_INMEMORYMOTOR_H
