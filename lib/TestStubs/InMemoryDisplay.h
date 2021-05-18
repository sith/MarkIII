//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_INMEMORYDISPLAY_H
#define MARKIII_INMEMORYDISPLAY_H


#include <SystemState.h>

class InMemoryDisplay {
    bool printedState = false;
    SystemState printedSystemState;
public:

    void showState(SystemState &systemState);

   const SystemState &getPrintedSystemState() const;

    void log(const char *key, char value);

    void log(const char *key, int value);

    void log(const char *key, long value);

    void log(const char *key, float value);

    void log(const char *key, double value);

};


#endif //MARKIII_INMEMORYDISPLAY_H
