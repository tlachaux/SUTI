/*
 * Simple Unit Test Interface
 * example.cpp
 * t.lachaux
 */

#include "../sources/suti.hpp"

SUTI
(
    "PROJECT X",

    SUTI_TEST
    (
        "Example 1",

        int a = 2 + 2;
        int b = 2 - 3;
        int c = 2 * 2;
        int d = 2 / 3;

        SUTI_EQUAL("Perform addition"       , a, 4)
        SUTI_EQUAL("Perform substraction"   , b, 5)
        SUTI_EQUAL("Perform multiplication" , c, 4)
        SUTI_EQUAL("Perform division"       , d, 5)
    )

    SUTI_TEST
    (
        "Example 2",

        int * buffer = nullptr;

        // buffer[10] = 2;

        SUTI_EQUAL("Verify buffer value"    , buffer, nullptr)
        SUTI_CRASH("Allocation error")
    )

)
