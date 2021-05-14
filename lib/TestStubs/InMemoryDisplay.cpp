#include "InMemoryDisplay.h"

void InMemoryDisplay::showState(SystemState &systemState) {
    printedSystemState = systemState;
}

const SystemState &InMemoryDisplay::getPrintedSystemState() const {
    return printedSystemState;
}

