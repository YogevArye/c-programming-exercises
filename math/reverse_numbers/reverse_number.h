#ifndef REVERSE_NUMBER_H
#define REVERSE_NUMBER_H

#include "../../utils/utils.h"

/** 
 * @struct ReverseNumberTestCase
 * @brief Structure representing a test case for reversing a number.
 */
typedef struct ReverseNumberTestCase {
    shared_tc s_tc;
    unsigned number;
} reverse_num_tc;

/**
 * @brief Reverses the digits of an unsigned integer with up to three digits.
 *
 * @param number The unsigned integer to reverse.
 * @return The reversed unsigned integer.
 */
unsigned ReverseNumber(unsigned number);

/**
 * @brief Runs a set of ReverseNumber function test cases.
 */
void RunTests(void);

#endif
