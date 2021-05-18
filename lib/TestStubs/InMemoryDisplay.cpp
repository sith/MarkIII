#include "InMemoryDisplay.h"

void InMemoryDisplay::showState(SystemState &systemState) {
    printedSystemState = systemState;
}

const SystemState &InMemoryDisplay::getPrintedSystemState() const {
    return printedSystemState;
}

void InMemoryDisplay::log(const char *key, char value) {

}

void InMemoryDisplay::log(const char *key, int value) {

}

void InMemoryDisplay::log(const char *key, long value) {

}

void InMemoryDisplay::log(const char *key, float value) {

}

void InMemoryDisplay::log(const char *key, double value) {

}

