#ifndef STRING_LENGTH_H
#define STRING_LENGTH_H

#include "../../utils/utils.h"

/** 
 * @struct StringLengthTestCase
 * @brief Structure representing a test case for calculating the length of a string.
 */
typedef struct StringLengthTestCase {
    shared_tc s_tc;
    const char* str;
} str_len_tc;

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * @param str The string whose length is to be calculated.
 * @return The length of the string (excluding the null terminator).
 */
size_t StringLength(const char* str);

/**
 * @brief Runs a set of StringLength function test cases.
 */
void RunTests(void);

#endif 
