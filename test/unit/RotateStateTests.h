//
// Created by Fedorov, Alex on 5/4/21.
//

#ifndef MARKIII_ROTATESTATETESTS_H
#define MARKIII_ROTATESTATETESTS_H

#include <RotateState.h>
#include "unity.h"

namespace rotateState {
    InMemoryDisplay display;

    void rotatesRight() {
        InMemoryMotor inMemoryMotor;
        InMemoryCompass inMemoryCompass{0};
        InMemoryDistanceSensor inMemoryDistanceSensor;
        Pilot<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> pilot{inMemoryMotor,
                                                                            inMemoryCompass,
                                                                            inMemoryDistanceSensor};
        RotateState<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor, InMemoryDisplay> rotateState{pilot,
                                                                                                         inMemoryCompass,
                                                                                                         90, display};
        TEST_ASSERT(!rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesRotateRight());

        inMemoryCompass.setDirection(45);
        TEST_ASSERT(!rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesRotateRight());

        inMemoryCompass.setDirection(90);
        TEST_ASSERT(rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesNotMove());
    }

    void rotatesLeft() {
        InMemoryMotor inMemoryMotor;
        InMemoryCompass inMemoryCompass{0};
        InMemoryDistanceSensor inMemoryDistanceSensor;
        Pilot<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> pilot{inMemoryMotor,
                                                                            inMemoryCompass,
                                                                            inMemoryDistanceSensor};
        RotateState<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor, InMemoryDisplay> rotateState{pilot,
                                                                                                         inMemoryCompass,
                                                                                                         -90, display};
        TEST_ASSERT(!rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesRotateLeft());

        inMemoryCompass.setDirection(315);
        TEST_ASSERT(!rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesRotateLeft());

        inMemoryCompass.setDirection(270);
        TEST_ASSERT(rotateState.isDone());
        TEST_ASSERT(inMemoryMotor.doesNotMove());
    }
}

void rotateStateTests() {
    RUN_TEST(rotateState::rotatesRight);
    RUN_TEST(rotateState::rotatesLeft);
}

#endif //MARKIII_ROTATESTATETESTS_H
