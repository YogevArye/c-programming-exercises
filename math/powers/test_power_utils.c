#include "powers.h" 

PowerFunction global_power_func;

/**
 * @brief Tests the selected power function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestPowerFunction(shared_tc* s_tc) {
    power_func_tc* pow_f_tc = (power_func_tc*)s_tc;
    pow_f_tc->s_tc.actual.f_val = global_power_func(pow_f_tc->base, pow_f_tc->exp);
}

/**
 * @brief Creates and initializes a test case for the selected power function.
 *
 * @param expected The result of raising the base to the power of exponent.
 * @param test_case_num The identifier for the test case.
 * @param base The base value for the power calculation.
 * @param exp The exponent value for the power calculation.
 * @return A PowerFunctionTestCase struct containing the initialized test case data.
 */
static power_func_tc CreatePowerFunctionTC(float expected, int test_case_num, float base, int exp) { 
   power_func_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.f_val = expected}, 
                     (TestValue){.f_val = 0.0f}, /* Sets 'actual' initial value to '0.0f' */ 
                     test_case_num, TYPE_FLOAT, TestPowerFunction), 
      .base = base,
      .exp = exp
   };
    return test_case;
}

void TestPowerUtils(PowerFunction power_func, const char *name) {
    size_t num_test_cases;
    size_t i;

    global_power_func = power_func;

    power_func_tc test_cases[] = {
        CreatePowerFunctionTC(   1.0f,   1,  2.0f,  0), /* Edge case: 2^0 = 1           */
        CreatePowerFunctionTC(   0.0f,   2,  0.0f,  5), /* Edge case: 0^5 = 0           */
        CreatePowerFunctionTC(   1.0f,   3,  5.0f,  0), /* Edge case: 5^0 = 1           */
        CreatePowerFunctionTC(  -1.0f,   4, -1.0f,  1), /* Edge case: (-1)^1 = -1       */
        CreatePowerFunctionTC(   1.0f,   5, -1.0f,  2), /* Edge case: (-1)^2 = 1        */
        CreatePowerFunctionTC(   1.0f,   6,  0.0f,  0), /* Edge case: 0^0 = 1           */
        CreatePowerFunctionTC( INFINITY, 7,  0.0f, -5), /* Edge case: 0^-5 is undefined,
                                                           results in positive INFINITY */         
        CreatePowerFunctionTC(  0.25f,   8,  2.0f, -2), /* Normal case: 2^-2 = 0.25     */
        CreatePowerFunctionTC(  25.0f,   9,  5.0f,  2), /* Normal case: 5^2 = 25        */
        CreatePowerFunctionTC(  0.04f,  10,  5.0f, -2), /* Normal case: 5^-2 = 0.04     */
        CreatePowerFunctionTC( 100.0f,  11, 10.0f,  2), /* Normal case: 10^2 = 100      */
        CreatePowerFunctionTC(  0.01f,  12, 10.0f, -2), /* Normal case: 10^-2 = 0.01    */
        CreatePowerFunctionTC(1024.0f,  13,  2.0f, 10), /* Normal case: 2^10 = 1024     */
        CreatePowerFunctionTC(   8.0f,  14,  2.0f,  3)  /* Normal case: 2^3 = 8         */
    };

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Testing %s:\n", name);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}