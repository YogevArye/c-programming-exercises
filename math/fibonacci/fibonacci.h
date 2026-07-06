#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "../../utils/utils.h"

/** 
 * @struct FibonacciTestCase
 * @brief Structure representing a test case for calculating the Fibonacci
 *        number at a given index.
 */
typedef struct FibonacciTestCase {
    shared_tc s_tc; 
    size_t index; 
} fibonacci_tc;

/** 
 * @brief Computes the nth Fibonacci number.
 *
 * @param index The nth position of the Fibonacci number to compute.
 * @return The nth Fibonacci number.
 */
unsigned long long Fibonacci(size_t index);

/** 
 * @brief Runs tests for the Fibonacci function.
 */
void RunTests(void);

#endif 




