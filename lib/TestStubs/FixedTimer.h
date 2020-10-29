//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_FIXEDTIMER_H
#define MARKIII_FIXEDTIMER_H


class FixedTimer {
    bool ready = false;
public:
    void setReady(bool ready);

    bool isReady();

};


#endif //MARKIII_FIXEDTIMER_H
