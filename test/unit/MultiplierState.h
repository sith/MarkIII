//
// Created by Fedorov, Alex on 5/2/21.
//

#ifndef MARKIII_MULTIPLIERSTATE_H
#define MARKIII_MULTIPLIERSTATE_H


#include <State.h>
#include <WString.h>

class MultiplierState : public State {
    int &targetValue;
    int multiplier;
public:
    MultiplierState(int &targetValue, int multiplier);
public:
    bool isDone() override;
};


#endif //MARKIII_MULTIPLIERSTATE_H
