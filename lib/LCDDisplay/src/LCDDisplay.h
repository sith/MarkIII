#ifndef MARKIII_LCDDISPLAY_H
#define MARKIII_LCDDISPLAY_H

const int LCD_COLS = 16;
const int LCD_ROWS = 2;

#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header


class LCDDisplay {
    hd44780_I2Cexp lcd;

    void clearRow(int rowIndex);
public:

    void init();

    void showWelcomeMessage();

    void clear();

    void countDownToStart(int seconds);

    void showDistanceToObstacle(unsigned int distanceToObstacle);

    void showMotorState(bool running);
};


#endif //MARKIII_LCDDISPLAY_H
