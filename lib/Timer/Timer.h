//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_TIMER_H
#define MARKIII_TIMER_H

class Timer {
    int duration;
    unsigned long previousTime = 0;

public:
    explicit Timer(int duration);

    void start();

    bool isReady();
};


#endif //MARKIII_TIMER_H
