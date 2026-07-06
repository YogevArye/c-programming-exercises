#include "greater_number.h"  

/**
 * @brief Tests the Maximum function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestGreaterNumber(shared_tc* s_tc){
    greater_number_tc* g_num_test = (greater_number_tc*)s_tc;
    g_num_test->s_tc.actual.i_val = Maximum(g_num_test->first_number, g_num_test->second_number);
}

/**
 * @brief Creates and initializes a GreaterNumberTestCase.
 *
 * @param expected The expected greater number of the two given numbers.
 * @param test_case_num The identifier for the test case.
 * @param first_number The first number to compare.
 * @param second_number The second number to compare.
 * @return A GreaterNumberTestCase struct containing the initialized test case data.
 */
static greater_number_tc CreateGreaterNumberTC(int expected, int test_case_num,
                                               int first_number, int second_number) {
   greater_number_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.i_val = expected}, 
                     (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */
                     test_case_num, TYPE_INT, TestGreaterNumber), 
      .first_number = first_number,
      .second_number = second_number
   };
    return test_case;
}

void RunTests(void) {
    size_t num_test_cases;
    size_t i;
    
    greater_number_tc test_cases[] = 
    {
        CreateGreaterNumberTC(  5, 1,   5,   3),
        CreateGreaterNumberTC( 10, 2,  10,  10),
        CreateGreaterNumberTC(  4, 3,  -3,   4),
        CreateGreaterNumberTC( -2, 4,  -5,  -2),
        CreateGreaterNumberTC(200, 5, 100, 200),
        CreateGreaterNumberTC(  7, 6,   7,   0),
        CreateGreaterNumberTC(  0, 7,   0,   0)
    };

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}
