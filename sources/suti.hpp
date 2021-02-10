#ifndef SUTI_HPP
#define SUTI_HPP

/*
 * Simple Unit Test Interface
 * suti.hpp
 * t.lachaux
 */

#include <vector>
#include <functional>
#include <iostream>
#include <iomanip>

namespace suti
{

/*
 * ------------------------------------------------------
 * Private definitions
 * ------------------------------------------------------
 */

// standard output colors

std::string bold        ("\e[1m");
std::string red         ("\033[0;31m\e[1m");
std::string green       ("\033[0;32m\e[1m");
std::string blue        ("\033[0;34m\e[1m");
std::string reset       ("\033[0m");

// text labels

#define LABEL_1             std::string("\n[TEST] ")
#define LABEL_2             std::string("  <ASSERT> ")
#define LABEL_3             std::string("  <CRASH>  ")

// text alignment function

#define ALIGN_TEXT(TEXT)    std::setw(70 - std::string(TEXT).size())

/*
 * ------------------------------------------------------
 * Public API
 * ------------------------------------------------------
 */

// main declaration

#define SUTI(PROJECT, TESTS) \
                        int main(int argc, char ** argv) \
                        { \
                            (void) argc; (void) argv; \
                            std::cout   << suti::bold \
                                        << "--------------------------------------------------------------\n" \
                                        << ">>> " << PROJECT << " (UNIT TESTS)" \
                                        << "\n--------------------------------------------------------------" << suti::reset << std::endl; \
                            std::vector<std::function<void(void)>> test_cases; \
                            TESTS; \
                            for (auto test : test_cases) { test(); } \
                            std::cout << suti::reset << std::endl; \
                        }

// test case

#define SUTI_TEST(ID, CODE) \
                        test_cases.push_back([]() \
                        { \
                            std::cout << suti::blue << LABEL_1 << ID << suti::reset << std::endl; \
                            CODE \
                        });

// assertion

#define SUTI_EQUAL(ID, TESTED, EXPECTED) \
                        std::cout << suti::bold << LABEL_2 << suti::reset << ID; \
                        if (TESTED == EXPECTED) std::cout << ALIGN_TEXT(LABEL_2 + ID) << suti::green << "OK" << suti::reset << std::endl; \
                        else                    std::cout << ALIGN_TEXT(LABEL_2 + ID) << suti::red << "NOK" << suti::reset << std::endl;

// crash test

#define SUTI_CRASH(ID) \
                        std::cout << suti::bold << LABEL_3 << suti::reset << ID << ALIGN_TEXT(LABEL_3 + ID) << suti::green << "OK" << suti::reset << std::endl;


};

#endif // SUTI_HPP
