//
// Created by Fedorov, Alex on 10/15/20.
//

#include "BlinkMessenger.h"

/*
 * The length of a dot is 1 time unit.

A dash is 3 time units.

The space between symbols (dots and dashes) of the same letter is 1 time unit.

The space between letters is 3 time units.

The space between words is 7 time units.*/

void blockWithMessage(String code) {
    pinMode(LED_BUILTIN, OUTPUT);

    int timeUnit = 250;
    int dot = timeUnit;
    int dash = timeUnit * 3;

    int spaceBetweenSymbols = timeUnit;
    int spaceBetweenLetters = timeUnit * 3;

    while (1) {
        for (const auto &aChar : code) {
            digitalWrite(LED_BUILTIN, HIGH);
            if (aChar == '.') {
                delay(dot);
            } else if (aChar == '-') {
                delay(dash);
            }
            digitalWrite(LED_BUILTIN, LOW);
            delay(spaceBetweenSymbols);
        }
        delay(spaceBetweenLetters);
    }
}
