//
// Created by Fedorov, Alex on 5/4/21.
//

#ifndef MARKIII_ROTATESTATETESTS_H
#define MARKIII_ROTATESTATETESTS_H

#include <RotateState.h>
#include "unity.h"

namespace rotateState {
    void rotatesRight() {
        InMemoryMotor inMemoryMotor;
        InMemoryCompass inMemoryCompass{0};
        InMemoryDistanceSensor inMemoryDistanceSensor;
        Pilot<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> pilot{inMemoryMotor,
                                                                            inMemoryCompass,
                                                                            inMemoryDistanceSensor};
        RotateState<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> rotateState{pilot, inMemoryCompass, 90};
        TEST_ASSERT(!rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesTurnRight());

        inMemoryCompass.setDirection(45);
        TEST_ASSERT(!rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesTurnRight());

        inMemoryCompass.setDirection(90);
        TEST_ASSERT(rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesNotMove());
    }
}

void rotateStateTests() {
    RUN_TEST(rotateState::rotatesRight);
}

#endif //MARKIII_ROTATESTATETESTS_H