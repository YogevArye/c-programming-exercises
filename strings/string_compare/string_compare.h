#ifndef STRING_COMPARE_H
#define STRING_COMPARE_H

#include "../../utils/utils.h"

/** 
 * @struct StringCompareTestCase
 * @brief Structure representing a test case for comparing two strings lexicographically.
 */
typedef struct StringCompareTestCase {
shared_tc s_tc;
char* str1;
char* str2;
} string_compare_tc;
   
/**
 * @brief Compares two strings lexicographically.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return 0 if the strings are identical, a negative value if `str1` is less
 *         than `str2`, or a positive value if `str1` is greater than `str2`.
 */
int StringCompare(const char* str1, const char* str2);

/**
 * @brief Runs a set of StringCompare function test cases.
 */
void RunTests(void);

#endif 
