#include "approx_sqrt.h"

/**
 * @brief Tests the ApproximateSqrt function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestApproximateSqrt(shared_tc* s_tc) {
    approx_sqrt_tc* a_sqrt_tc  = (approx_sqrt_tc*)s_tc;
    a_sqrt_tc ->s_tc.actual.f_val = ApproximateSqrt(a_sqrt_tc ->num);
}     

/**
 * @brief Creates and initializes a ApproximateSqrtTestCase.
 *
 * @param expected The approximate square root of the given number.
 * @param test_case_num The identifier for the test case.
 * @param num The given number for which to approximate the square root.
 * @return A ApproximateSqrtTestCase struct containing the initialized test case data.
 */
static approx_sqrt_tc CreateApproximateSqrtTC(float expected, int test_case_num, float num) { 
   approx_sqrt_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.f_val = expected}, 
                     (TestValue){.f_val = 0}, /* Sets 'actual' initial value to '0.0f' */ 
                     test_case_num, TYPE_FLOAT, TestApproximateSqrt), 
      .num = num 
   };
    return test_case; 
}

void RunTests(void) {
        size_t i;
        size_t num_cases;

    approx_sqrt_tc test_cases[] = {
         CreateApproximateSqrtTC(    1.0f,   1,    1.0f),   /* Square root of 1  */
         CreateApproximateSqrtTC( 1.4142f,   2,    2.0f),   /* Square root of 2  */
         CreateApproximateSqrtTC( 1.7321f,   3,    3.0f),   /* Square root of 3  */
         CreateApproximateSqrtTC(    2.0f,   4,    4.0f),   /* Square root of 4  */
         CreateApproximateSqrtTC(  2.236f,   5,    5.0f),   /* Square root of 5  */
         CreateApproximateSqrtTC( 2.4494f,   6,    6.0f),   /* Square root of 6  */
         CreateApproximateSqrtTC( 2.6457f,   7,    7.0f),   /* Square root of 7  */
         CreateApproximateSqrtTC( 2.8284f,   8,    8.0f),   /* Square root of 8  */
         CreateApproximateSqrtTC(    3.0f,   9,    9.0f),   /* Square root of 9  */
         CreateApproximateSqrtTC( 3.1622f,  10,   10.0f),   /* Square root of 10 */
         CreateApproximateSqrtTC( 3.3166f,  11,   11.0f),   /* Square root of 11 */
         CreateApproximateSqrtTC( 3.4641f,  12,   12.0f),   /* Square root of 12 */
         CreateApproximateSqrtTC( 3.6055f,  13,   13.0f),   /* Square root of 13 */
         CreateApproximateSqrtTC( 3.7416f,  14,   14.0f),   /* Square root of 14 */
         CreateApproximateSqrtTC( 3.8729f,  15,   15.0f),   /* Square root of 15 */
         CreateApproximateSqrtTC(    4.0f,  16,   16.0f),   /* Square root of 16 */
         CreateApproximateSqrtTC( 4.1231f,  17,   17.0f),   /* Square root of 17 */
         CreateApproximateSqrtTC(34.9428f,  18, 1221.0f)    /* Square root of 1221 */
    };

    num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (i = 0; i < num_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}