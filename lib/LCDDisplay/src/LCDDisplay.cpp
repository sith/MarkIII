//
// Created by Fedorov, Alex on 10/12/20.
//

#include "LCDDisplay.h"

void LCDDisplay::init() {
    int status = lcd.begin(LCD_COLS, LCD_ROWS);
    if (status) {
        status = -status;
        hd44780::fatalError(status);
    }
}
