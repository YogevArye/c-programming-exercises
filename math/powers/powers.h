#ifndef POWERS_H
#define POWERS_H

#include "../../utils/utils.h"

/** 
 * @typedef PowerFunction
 * @brief Type definition for a pointer to a function that calculates 
 *        the power of a float base raised to an integer exponent.
 */
typedef float (*PowerFunction)(float, int);

/** 
 * @struct PowerFunctionTestCase
 * @brief Structure representing a test case for the selected power function.
 */
typedef struct PowerFunctionTestCase {
    shared_tc s_tc;
    float base;
    int exp;
} power_func_tc;

/**
 * @brief Handle cases where the base is zero for exponentiation.
 * 
 * @param base The base value, expected to be 0.0f.
 * @param exp The exponent value.
 * @return The result of 0^exp.
 */
float HandleZeroBase(float base, int exp);

/**
 * @brief Runs a set of test cases for the selected power function.
 * 
 * @param power_func The selected power function to test.
 * @param name The name of the selected power function for logging purposes.
 */
void TestPowerUtils(PowerFunction power_func, const char *name);

#endif 