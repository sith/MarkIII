//
// Created by Fedorov, Alex on 10/12/20.
//

#include <BlinkMessenger.h>
#include "LCDDisplay.h"

int LCDDisplay::init() {
    return lcd.begin(LCD_COLS, LCD_ROWS);
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
    lcd.setCursor(0, 0);
    lcd.print("Mark III is ready!");
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

void LCDDisplay::showErrorAndBlock(char errorCode) {
    clear();
    lcd.setCursor(0, 0);
    lcd.print("Error: ");
    lcd.print((int) errorCode);
    while (1);
}

void LCDDisplay::showState(const SystemState &systemState) {
    clearRow(0);
    lcd.setCursor(0, 0);
    lcd.write("DO:");
    lcd.print((int) systemState.distanceToObstacle);
    lcd.write("in");

    lcd.setCursor(8, 0);
    lcd.write("D:");
    lcd.print((int) systemState.direction);
}

void LCDDisplay::log(const char *key, char value) {
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.write(key);
    lcd.write(DELIMITER);
    lcd.print(value);
}

void LCDDisplay::log(const char *key, int value) {
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.write(key);
    lcd.write(DELIMITER);
    lcd.print(value);
}

void LCDDisplay::log(const char *key, long value) {
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.write(key);
    lcd.write(DELIMITER);
    lcd.print(value);
}

void LCDDisplay::log(const char *key, float value) {
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.write(key);
    lcd.write(DELIMITER);
    lcd.print(value, 2);
}

void LCDDisplay::log(const char *key, double value) {
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.write(key);
    lcd.write(DELIMITER);
    lcd.print(value, 2);
}



