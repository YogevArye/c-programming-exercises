#ifndef DIVIDE_H
#define DIVIDE_H

#include "../../utils/utils.h"

typedef struct DivideTestCase {
shared_tc s_tc;
int numerator;
int denominator;
}divide_tc;

/**
 * @brief Performs integer division and handles basic error cases.
 *
 * @param numerator The dividend in the division operation.
 * @param denominator The divisor in the division operation.
 * @param quotient Pointer to store the result of numerator / denominator.
 * @param remainder Pointer to store the result of numerator % denominator.
 *
 * @return Returns 0 for a successful division, -1 if division by zero occurs, or 
 *         INT_MAX if an overflow condition occurs.
 */
int Divide(int numerator, int denominator, int* quotient, int* remainder);

/**
 * @brief Runs a set of Divide function test cases.
 */
void RunTests(void);

#endif 
