//
// Created by Fedorov, Alex on 5/2/21.
//

#ifndef MARKIII_SEQUANTIALSTATEMACHINEDEFINITION_H
#define MARKIII_SEQUANTIALSTATEMACHINEDEFINITION_H

template<typename STATE_ID>
class SequentialStateMachineDefinition {
    STATE_ID *first;
    int index = 0;
    int size;
public:
    SequentialStateMachineDefinition(STATE_ID *current, int index, int size) : first(current), index(index),
                                                                               size(size) {
    }

    void nextState() {
        if (index < size) {
            index++;
        }
    }

    STATE_ID *getCurrentStateId() {
        if (index >= size) {
            return nullptr;
        }

        return first + index;
    }

};


#endif //MARKIII_SEQUANTIALSTATEMACHINEDEFINITION_H
