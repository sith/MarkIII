//
// Created by Fedorov, Alex on 10/14/20.
//

#ifndef MARKIII_INMEMORYMOTOR_H
#define MARKIII_INMEMORYMOTOR_H

#include <Movement.h>
#include <InMemoryCompass.h>

class InMemoryMotor {
public:
    Movement leftWheelMovement = NO_MOVEMENT;
    Movement rightWheelMovement = NO_MOVEMENT;
    char speed;

    InMemoryMotor();

    bool doesTurnRight() const;

    bool doesTurnLeft() const;

    bool doesNotMove() const;

    bool goesForward() const;

    char getSpeed() const;

    void turnRight(char speed);

    void turnLeft(char speed);

    void forward(char speed);

    void stop();
};


#endif //MARKIII_INMEMORYMOTOR_H
