#ifndef MARKIII_LCDDISPLAY_H
#define MARKIII_LCDDISPLAY_H

const int LCD_COLS = 16;
const int LCD_ROWS = 2;

static const char DELIMITER = ':';

#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header
#include <SystemState.h>


class LCDDisplay {
    hd44780_I2Cexp lcd;

    void clearRow(int rowIndex);

public:

    int init();

    void showWelcomeMessage();

    void clear();

    void countDownToStart(int seconds);

    void showErrorAndBlock(char errorCode);

    void showState(const SystemState &systemState);

    void log(const char *key, char value);

    void log(const char *key, int value);

    void log(const char *key, long value);

    void log(const char *key, float value);

    void log(const char *key, double value);
};


#endif //MARKIII_LCDDISPLAY_H
