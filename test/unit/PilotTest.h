
#ifndef MARKIII_PILOTTEST_H
#define MARKIII_PILOTTEST_H

#include <unity.h>
#include <Pilot.h>
#include <InMemoryCompass.h>
#include <InMemoryMotor.h>
#include <InMemoryDistanceSensor.h>



namespace pilotTests{
    InMemoryCompass compass{0};
    InMemoryMotor motor{};
    InMemoryDistanceSensor distanceSensor;

    Pilot<InMemoryMotor, InMemoryCompass, InMemoryDistanceSensor> pilot{motor, compass, distanceSensor};


    void goForwardIfOnCourse() {

        compass.setDirection(0);

        pilot.setTargetDirection(0);
        pilot.setSpeed((char) 10);
        pilot.start();

        pilot.process();

        TEST_ASSERT(motor.goesForward());
    }

    void turnLeftIf180() {
        compass.setDirection(180);

        pilot.setTargetDirection(0);
        pilot.setSpeed((char) 10);
        pilot.start();

        pilot.process();

        TEST_ASSERT(motor.doesTurnLeft());
    }

    void turnLeftToGetBackOnCourse() {
        compass.setDirection(0);

        pilot.setTargetDirection(270);
        pilot.setSpeed((char) 10);
        pilot.start();

        pilot.process();

        TEST_ASSERT(motor.doesTurnLeft());
    }

    void turnRightToGetBackOnCourse() {
        compass.setDirection(0);

        pilot.setTargetDirection(30);
        pilot.setSpeed((char) 10);
        pilot.start();

        pilot.process();

        TEST_ASSERT(motor.doesTurnRight());
    }

    void noMovementIfNotStarted() {
        compass.setDirection(0);

        pilot.setTargetDirection(30);

        TEST_ASSERT_EQUAL(compass.getCurrentCourse(), 0);
        TEST_ASSERT(motor.doesNotMove());
    }

    void noMovementIfSpeedIsZero() {
        compass.setDirection(0);

        pilot.setTargetDirection(30);
        pilot.setSpeed(0);
        pilot.start();

        TEST_ASSERT_EQUAL(compass.getCurrentCourse(), 0);
    }

    void stopsIfObstacle() {
        compass.setDirection(0);
        pilot.setTargetDirection(0);
        pilot.setSpeed(100);
        pilot.start();

        pilot.process();
        TEST_ASSERT(motor.goesForward());

        distanceSensor.setDistance(0);

        pilot.process();
        TEST_ASSERT(motor.doesNotMove());
    }


    void resetMocks() {
        motor.stop();
        compass.setDirection(0);
        distanceSensor.setDistance(1000);
    }


    void tests() {
        resetMocks();
        RUN_TEST(turnRightToGetBackOnCourse);
        resetMocks();
        RUN_TEST(turnLeftToGetBackOnCourse);
        resetMocks();
        RUN_TEST(turnLeftIf180);
        resetMocks();
        RUN_TEST(goForwardIfOnCourse);
        resetMocks();
        RUN_TEST(noMovementIfNotStarted);
        resetMocks();
        RUN_TEST(noMovementIfSpeedIsZero);
        resetMocks();
        RUN_TEST(stopsIfObstacle);
        resetMocks();
    }

}


#endif //MARKIII_PILOTTEST_H
