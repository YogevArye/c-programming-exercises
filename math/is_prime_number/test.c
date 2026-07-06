#include "is_prime_number.h"

/**
 * @brief Tests the IsPrimeNumber function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestPrimeNumber(shared_tc* s_tc) {
    prime_number_tc* pn_test = (prime_number_tc*)s_tc;
    pn_test->s_tc.actual.i_val = IsPrimeNumber(pn_test->number);
}

/**
 * @brief Creates and initializes a test case for the IsPrimeNumber function.
 *
 * @param expected Indicates whether the given number is a prime number (1) or not (0).
 * @param test_case_num The identifier for the test case.
 * @param number The number to be tested for primality.
 * @return A IsPrimeNumberTestCase struct containing the initialized test case data.
 */
static prime_number_tc CreatePrimeNumberTC(int expected, int test_case_num, unsigned long number) {
   prime_number_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.i_val = expected}, 
                     (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */
                     test_case_num, TYPE_INT, TestPrimeNumber), 
      .number = number
   };
    return test_case;
}

void RunTests(void) {
    size_t num_test_cases;
    size_t i;

    prime_number_tc test_cases[] = {
        CreatePrimeNumberTC(0,  1,  1),    /* 1 is not prime  */
        CreatePrimeNumberTC(1,  2,  2),    /* 2 is prime      */
        CreatePrimeNumberTC(1,  3,  3),    /* 3 is prime      */
        CreatePrimeNumberTC(0,  4,  4),    /* 4 is not prime  */
        CreatePrimeNumberTC(1,  5,  5),    /* 5 is prime      */
        CreatePrimeNumberTC(0,  6,  6),    /* 6 is not prime  */
        CreatePrimeNumberTC(1,  7, 17),    /* 17 is prime     */
        CreatePrimeNumberTC(0,  8, 18),    /* 18 is not prime */
        CreatePrimeNumberTC(1,  9, 19),    /* 19 is prime     */
        CreatePrimeNumberTC(0, 10, 20),    /* 20 is not prime */
        CreatePrimeNumberTC(1, 11, 23),    /* 23 is prime     */
        CreatePrimeNumberTC(0, 12, 24),    /* 24 is not prime */
        CreatePrimeNumberTC(1, 13, 29),    /* 29 is prime     */
        CreatePrimeNumberTC(1, 14, 10007), /* 10,007 is prime */
        CreatePrimeNumberTC(1, 15, 20011), /* 20,011 is prime */
        CreatePrimeNumberTC(0, 16, 30043), /* 30,043 is not prime */
        CreatePrimeNumberTC(1, 17, 40009), /* 40,009 is prime */
        CreatePrimeNumberTC(0, 18, 50009)  /* 50,009 is not prime */
    };

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}
