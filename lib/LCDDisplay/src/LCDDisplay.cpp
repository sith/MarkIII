//
// Created by Fedorov, Alex on 10/12/20.
//

#include <BlinkMessenger.h>
#include "LCDDisplay.h"

void LCDDisplay::init() {
    int status = lcd.begin(LCD_COLS, LCD_ROWS);
    if (status) {
        blockWithMessage("..-");
    }
}

void LCDDisplay::showWelcomeMessage() {
    lcd.setCursor(0, 0);
    lcd.write("MarkIII");
    lcd.setCursor(0, 1);
    lcd.write("Initializing...");
}

void LCDDisplay::clear() {
    lcd.clear();
}



