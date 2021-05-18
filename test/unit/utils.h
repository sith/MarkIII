//
// Created by Fedorov, Alex on 5/18/21.
//

#ifndef MARKIII_UTILS_H
#define MARKIII_UTILS_H

void log(const char *message, unsigned char value) {
    Serial.print(message);
    Serial.println(value);
}

#endif //MARKIII_UTILS_H
