#ifndef IS_PRIME_NUMBER_H
#define IS_PRIME_NUMBER_H

#include "../../utils/utils.h"

/** 
 * @struct IsPrimeNumberTestCase
 * @brief Structure representing a test case for prime number checking.
 */
typedef struct IsPrimeNumberTestCase {
    shared_tc s_tc;
    unsigned long number; 
} prime_number_tc;

/**
 * @brief Checks if a given number is prime.
 *
 * @param num The number to be checked.
 * @return 1 if the number is prime, 0 otherwise.
 */
int IsPrimeNumber(unsigned long num);

/**
 * @brief Runs a set of test cases for the IsPrimeNumber function.
 */
void RunTests(void);

#endif 