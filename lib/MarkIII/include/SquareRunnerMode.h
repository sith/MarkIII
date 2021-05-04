//
// Created by Fedorov, Alex on 5/1/21.
//

#ifndef MARKIII_SQUARERUNNERMODE_H
#define MARKIII_SQUARERUNNERMODE_H

template<typename Compass, typename Timer, typename Motor>
class SquareRunnerMode {
    Compass &compass;
    Timer &timer;
    Motor &motor;
public:
    SquareRunnerMode(Compass &compass, Timer &timer, Motor &motor) : compass(compass), timer(timer), motor(motor) {}

    void process() {

    }

};

#endif //MARKIII_SQUARERUNNERMODE_H
