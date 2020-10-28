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

void LCDDisplay::countDownToStart(int seconds) {
    clearRow(1);
    lcd.setCursor(0, 1);
    String message = "Starting in ";
    lcd.write(message.c_str());
    for (int i = seconds; i > 0; i--) {
        lcd.setCursor(message.length(), 1);
        lcd.print((int) i);
        lcd.write("s");
        delay(1000);
    }
}

void LCDDisplay::clearRow(int rowIndex) {
    for (int i = 0; i < LCD_COLS; i++) {
        lcd.setCursor(i, rowIndex);
        lcd.write(" ");
    }
}



