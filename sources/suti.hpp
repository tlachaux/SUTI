#ifndef SUTI_H
#define SUTI_H

/*
 * Simple Unit Test Interface
 * t.lachaux
 */

#include <vector>
#include <functional>
#include <iostream>

std::string red     ("\033[0;31m");
std::string green   ("\033[0;32m");
std::string blue    ("\033[0;34m");
std::string reset   ("\033[0m");

#define SUTI(TESTS) \
                        int main(int argc, char ** argv) \
                        { \
                            (void) argc; (void) argv; \
                            std::vector<std::function<void(void)>> test_cases; \
                            TESTS; \
                            for (auto test : test_cases) { test(); } \
                            std::cout << reset << std::endl; \
                        }


#define SUTI_TEST(ID, CODE) \
                        test_cases.push_back([]() \
                        { \
                            std::cout << blue << "\n[TEST] " << ID << reset << std::endl; \
                            CODE \
                        });


#define SUTI_ASSERT(ID, TESTED, EXPECTED) \
                        std::cout << "  [ASSERT] " << ID; \
                        if (TESTED == EXPECTED) std::cout << green << "\tOK" << reset << std::endl; \
                        else                    std::cout << red << "\tNOK" << reset << std::endl;


#define SUTI_NO_CRASH std::cout << "  [NO CRASH] " << green << "\t\tOK" << reset << std::endl;

#endif // SUTI_H
