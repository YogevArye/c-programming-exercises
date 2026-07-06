#include "fibonacci.h"

/**
 * @brief Tests the Fibonacci function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestFibonacci(shared_tc* s_tc){
    fibonacci_tc* f_test = (fibonacci_tc*)s_tc;
    f_test->s_tc.actual.ull_val = Fibonacci(f_test->index);
}

/**
 * @brief Creates and initializes a FibonacciTestCase.
 *
 * @param expected The expected Fibonacci value at the nth position.
 * @param test_case_num The identifier for the test case.
 * @param index The nth position of the Fibonacci number to compute.
 * @return A FibonacciTestCase struct containing the initialized test case data.
 */
static fibonacci_tc CreateFibonacciTC(unsigned long long expected, int test_case_num, size_t index) {
 fibonacci_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
    (TestValue){.ull_val = expected}, 
    (TestValue){.ull_val = 0}, /* Sets 'actual' initial value to '0' */
    test_case_num, TYPE_UNSIGNED_LONG_LONG, TestFibonacci),                               
    .index = index 
};
return test_case;
}

void RunTests(void) {   
    size_t num_test_cases;
    size_t i;
    
    fibonacci_tc test_cases[] = {
        CreateFibonacciTC(           0,    1,   0), /* F_0 = 0 */
        CreateFibonacciTC(           1,    2,   1), /* F_1 = 1 */
        CreateFibonacciTC(           1,    3,   2), /* F_2 = 1 */
        CreateFibonacciTC(           2,    4,   3), /* F_3 = 2 */
        CreateFibonacciTC(           3,    5,   4), /* F_4 = 3 */
        CreateFibonacciTC(           5,    6,   5), /* F_5 = 5 */
        CreateFibonacciTC(           8,    7,   6), /* F_6 = 8 */
        CreateFibonacciTC(          13,    8,   7), /* F_7 = 13 */
        CreateFibonacciTC(   102334155,    9,  40), /* F_40 = 102,334,155  */
        CreateFibonacciTC( 12586269025,   10,  50), /* F_50 = 12,586,269,025  */
        CreateFibonacciTC(139583862445,   11,  55), /* F_55 = 1,39,583,862,445  */
        CreateFibonacciTC( 32951280099,   12,  52)  /* F_52 = 32,356,114,163  */
    };

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i){
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }    
}
  
