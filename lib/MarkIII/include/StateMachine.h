//
// Created by Fedorov, Alex on 5/2/21.
//

#ifndef MARKIII_STATEMACHINE_H
#define MARKIII_STATEMACHINE_H


#include "State.h"

template<typename STATE_REPOSITORY, typename STATE_MACHINE_DEFINITION, typename STATE_ID>
class StateMachine {
    const STATE_REPOSITORY &stateRepository;
    STATE_MACHINE_DEFINITION stateMachineDefinition;

public:
    StateMachine(const STATE_REPOSITORY &stateRepository, STATE_MACHINE_DEFINITION stateMachineDefinition)
            : stateRepository(stateRepository), stateMachineDefinition(stateMachineDefinition) {
    }

    void process() {
        STATE_ID *currentStateId = stateMachineDefinition.getCurrentStateId();
        if (currentStateId == nullptr) {
            return;
        }

        State &state = stateRepository.get(*currentStateId);
        if (state.isDone()) {
            stateMachineDefinition.nextState();
        }
    }
};


#endif //MARKIII_STATEMACHINE_H
