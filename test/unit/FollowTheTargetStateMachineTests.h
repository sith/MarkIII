//
// Created by Fedorov, Alex on 5/18/21.
//

#ifndef MARKIII_FOLLOWTHETARGETSTATEMACHINETESTS_H
#define MARKIII_FOLLOWTHETARGETSTATEMACHINETESTS_H

#include <FollowTheTargetStateMachine.h>
#include "utils.h"

namespace followthetargetstatemachine {

    InMemoryMotor inMemoryMotor;
    InMemoryCompass inMemoryCompass{0};
    InMemoryDistanceSensor inMemoryDistanceSensor;
    Pilot<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> pilot{inMemoryMotor, inMemoryCompass,
                                                                        inMemoryDistanceSensor};

    Inch targetDistance = 10;
    FollowTheTargetStateMachine<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> followTheTargetStateMachine{
            targetDistance,
            pilot,
            inMemoryDistanceSensor
    };


    void goesForward() {

        inMemoryDistanceSensor.setDistance(20);
        followTheTargetStateMachine.process();

        TEST_ASSERT(inMemoryMotor.goesForward());
    }


    void stops() {

        inMemoryDistanceSensor.setDistance(targetDistance);
        followTheTargetStateMachine.process();
        TEST_ASSERT(inMemoryMotor.doesNotMove());
    }

    void goesBackwards() {


        inMemoryDistanceSensor.setDistance(5);
        followTheTargetStateMachine.process();
        TEST_ASSERT(inMemoryMotor.goesBackward());
    }

    void tests() {
        RUN_TEST(goesForward);
        RUN_TEST(goesBackwards);
        RUN_TEST(stops);
    }

}
#endif //MARKIII_FOLLOWTHETARGETSTATEMACHINETESTS_H
