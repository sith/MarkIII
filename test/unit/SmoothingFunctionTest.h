//
// Created by Fedorov, Alex on 5/14/21.
//

#ifndef MARKIII_SMOOTHINGFUNCTIONTEST_H
#define MARKIII_SMOOTHINGFUNCTIONTEST_H

#include "unity.h"
#include <SmoothingFunction.h>

namespace smoothingFunction {

    void returnsSameValue() {
        SmoothingFunction<4> smoothingFunction;

        TEST_ASSERT_EQUAL_DOUBLE(1.0, smoothingFunction(1.0));
        TEST_ASSERT_EQUAL_DOUBLE(1.0, smoothingFunction(1.0));
        TEST_ASSERT_EQUAL_DOUBLE(1.0, smoothingFunction(1.0));
        TEST_ASSERT_EQUAL_DOUBLE(1.0, smoothingFunction(1.0));
    }

    void returnsAverage() {
        SmoothingFunction<4> smoothingFunction;

        TEST_ASSERT_EQUAL_DOUBLE(1.0, smoothingFunction(1.0));
        TEST_ASSERT_EQUAL_DOUBLE(1.5, smoothingFunction(2.0));
        TEST_ASSERT_EQUAL_DOUBLE(2.0, smoothingFunction(3.0));
        TEST_ASSERT_EQUAL_DOUBLE(2.5, smoothingFunction(4.0));
        TEST_ASSERT_EQUAL_DOUBLE(3.5, smoothingFunction(5.0));
        TEST_ASSERT_EQUAL_DOUBLE(4.5, smoothingFunction(6.0));
        TEST_ASSERT_EQUAL_DOUBLE(5.5, smoothingFunction(7.0));
        TEST_ASSERT_EQUAL_DOUBLE(6.5, smoothingFunction(8.0));
        TEST_ASSERT_EQUAL_DOUBLE(7.5, smoothingFunction(9.0));
        TEST_ASSERT_EQUAL_DOUBLE(8.5, smoothingFunction(10.0));
    }

    void dropOutlier() {
        SmoothingFunction<10> smoothingFunction;

        smoothingFunction(1.0);
        smoothingFunction(1.0);
        smoothingFunction(1.0);
        smoothingFunction(1.0);
        smoothingFunction(1.0);
        smoothingFunction(1.0);
        TEST_ASSERT_EQUAL_DOUBLE(1.0, smoothingFunction(100.0));

    }


    void tests() {
        RUN_TEST(returnsSameValue);
        RUN_TEST(returnsAverage);
        RUN_TEST(dropOutlier);
    };
}


#endif //MARKIII_SMOOTHINGFUNCTIONTEST_H
