//
// Created by Fedorov, Alex on 10/12/20.
//

#ifndef MARKIII_L293DDUALMOTORDRIVER_H
#define MARKIII_L293DDUALMOTORDRIVER_H

#include <Movement.h>

class L293DDualMotorDriver {
    int leftEn = 9;
    int leftIn1 = 8;
    int leftIn2 = 7;

    int rightEn = 3;
    int rightIn1 = 5;
    int rightIn2 = 4;

    void stopMotor(int in1, int in2, int en);

    void controlMotor(const Movement &movement, char speed, int in1, int in2, int en);

public:
    void init();

    void leftWheel(Movement movement, char speed);
    void rightWheel(Movement movement, char speed);

    void stop();
};


#endif //MARKIII_L293DDUALMOTORDRIVER_H
