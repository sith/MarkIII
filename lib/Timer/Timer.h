//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_TIMER_H
#define MARKIII_TIMER_H

class Timer {
    int delay;
    unsigned long previousTime = 0;

public:
    Timer(int delay);

    void init();

    bool isReady();
};


#endif //MARKIII_TIMER_H
