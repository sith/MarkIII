
#include "MultiplierState.h"

bool MultiplierState::isDone() {
    targetValue *= multiplier;
    return true;
}

MultiplierState::MultiplierState(int &targetValue, int multiplier)
        : targetValue(targetValue), multiplier(multiplier) {}

