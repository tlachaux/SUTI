/*
 * Simple Unit Test Interface
 * t.lachaux
 */

#include "../sources/suti.hpp"

SUTI
(

    SUTI_TEST
    (
        "<test case description 1>",

        int a = 2 + 2;
        int b = 2 - 3;
        
        SUTI_ASSERT("Perform addition", a, 4)
        SUTI_ASSERT("Perform substraction", b, 5)
    )

    SUTI_TEST
    (
        "<test case description 2>",

        // int * buffer = nullptr;
        // buffer[10] = 2;

        SUTI_NO_CRASH
    )

)
