/*
 * Simple Unit Test Interface
 * example.cpp
 * t.lachaux
 */

#include "../sources/suti.hpp"

SUTI
(

    SUTI_TEST
    (
        "<test case description 1>",

        SUTI_ASSERT("Perform addition", 2 + 2, 4)
        SUTI_ASSERT("Perform substraction", 2 * 3, 5)
    )

    SUTI_TEST
    (
        "<test case description 2>",

        // int * buffer = nullptr;
        // buffer[10] = 2;

        SUTI_NO_CRASH
    )

)
