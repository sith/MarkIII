//
// Created by Fedorov, Alex on 5/2/21.
//

#ifndef MARKIII_STATEMACHINETESTS_H
#define MARKIII_STATEMACHINETESTS_H


#include <unity.h>
#include <StateMachine.h>
#include "MultiplierState.h"
#include "SequentialStateMachineDefinition.h"

class ArrayStateRepository {
    State *states[2];
public:


    void set(int index, State &state) {
        states[index] = &state;
    }

    State &get(int index) {
        return *states[index];
    }
};

void runsStateMachine() {
    int targetValue = 2;
    int stateDefinition[]{0, 1};
    SequentialStateMachineDefinition<int> sequentialStateMachineDefinition{stateDefinition, 0, 2};
    ArrayStateRepository repository{};
    MultiplierState stateA{targetValue, 2};
    MultiplierState stateB{targetValue, 3};
    repository.set(0, stateA);
    repository.set(1, stateB);
    StateMachine<ArrayStateRepository, SequentialStateMachineDefinition<int>, int> stateMachine{repository,
                                                                                                sequentialStateMachineDefinition};

    stateMachine.process();
    stateMachine.process();
    stateMachine.process();

    TEST_ASSERT_EQUAL(12, targetValue);
}

void stateMachineTests() {
    RUN_TEST(runsStateMachine);
}

#endif //MARKIII_STATEMACHINETESTS_H
