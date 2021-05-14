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

};


#endif //MARKIII_INMEMORYDISPLAY_H
