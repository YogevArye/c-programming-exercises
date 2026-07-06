#ifndef STRING_TO_INTEGER_H
#define STRING_TO_INTEGER_H

#include "../../utils/utils.h"

/** 
 * @struct StringToIntTestCase
 * @brief Structure representing a test case for converting a string to an integer.
 */
typedef struct StringToIntTestCase {
    shared_tc s_tc;
    const char* str;
} str_int_tc;

/**
 * @brief Converts a null-terminated string to an integer.
 *
 * @param str The string to be converted.
 * @return The integer representation of the string.
 */
int StringToInteger(const char *str);

/**
 * @brief Runs a set of StringToInteger function test cases.
 */
void RunTests(void);

#endif 