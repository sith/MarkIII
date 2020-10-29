//
// Created by Fedorov, Alex on 10/12/20.
//

#ifndef MARKIII_L293DDUALMOTORDRIVER_H
#define MARKIII_L293DDUALMOTORDRIVER_H

#include <Movement.h>

class L293DDualMotorDriver {
    unsigned char leftEn = 9;
    unsigned char leftIn1 = 8;
    unsigned char leftIn2 = 7;
    unsigned char rightEn = 3;
    unsigned char rightIn1 = 5;
    unsigned char rightIn2 = 4;

    unsigned char leftWheelSpeed = 0;
    unsigned char rightWheelSpeed = 0;

    void stopMotor(unsigned char in1, unsigned char in2, unsigned char en);

    void controlMotor(const Movement &movement, unsigned char speed, unsigned char in1, unsigned char in2, unsigned char en);

public:
    void init();

    void leftWheel(Movement movement, unsigned char speed);

    void rightWheel(Movement movement, unsigned char speed);

    bool isRunning() const;

    void stop();
};


#endif //MARKIII_L293DDUALMOTORDRIVER_H
