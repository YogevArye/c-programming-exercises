#ifndef POWER_OPTIMIZED_RECURSIVE
#define POWER_OPTIMIZED_RECURSIVE

#include "../powers.h"

/**
 * @brief Calculates the power of a base raised to an exponent using the Recursive
 *        approach of Exponentiation by Squaring (O(log n)).
 * 
 * @param base The base value for the power calculation.
 * @param exp The exponent value for the power calculation.
 * @return The result value for the power calculation.
 */
float PowerOptimizedRecursive(float base, int exp);

#endif