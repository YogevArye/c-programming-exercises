#ifndef APPROX_SQRT_H
#define APPROX_SQRT_H

#include "../../utils/utils.h"

/** 
 * @struct ApproximateSqrtTestCase
 * @brief Structure representing a test case for approximating the square root
 *        using the Babylonian method.
 */
typedef struct ApproximateSqrtTestCase {
shared_tc s_tc;
float num;
} approx_sqrt_tc;

/** 
 * @brief Approximates the square root of a given number using the Babylonian
 *        method (Heron's method).
 *
 * @param num The given number for which to approximate the square root.
 * @return The approximate square root of the given number.
 */
float ApproximateSqrt(float num);

/** 
 * @brief Runs tests for the ApproximateSqrt function.
 */
void RunTests(void);

#endif 
