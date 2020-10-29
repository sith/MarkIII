//
// Created by Fedorov, Alex on 10/28/20.
//

#include "FixedTimer.h"

bool FixedTimer::isReady() {
    return ready;
}

void FixedTimer::setReady(bool ready) {
    FixedTimer::ready = ready;
}
