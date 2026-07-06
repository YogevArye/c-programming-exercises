#ifndef GREATER_NUMBER_H
#define GREATER_NUMBER_H

#include "../../utils/utils.h"

/**
 * @struct GreaterNumberTestCase
 * @brief Structure representing a test case for determining the greater 
 *        number between two given numbers.
 */
typedef struct GreaterNumberTestCase {
    shared_tc s_tc;
    int first_number;
    int second_number;
} greater_number_tc;

/**
 * @brief Determines the greater number between two given numbers.
 *
 * @param first_number The first integer to compare.
 * @param second_number The second integer to compare.
 * @return The greater of the two input numbers.
 */
int Maximum(int first_number, int second_number);

/** 
 * @brief Runs tests for the Maximum function.
 */
void RunTests(void);

#endif 