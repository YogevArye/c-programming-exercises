#include "reverse_number.h"

/**
 * @brief Tests the ReverseNumber function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestReverseNumber(shared_tc* s_tc) {
    reverse_num_tc* rev_num_tc = (reverse_num_tc*)s_tc;
    rev_num_tc->s_tc.actual.u_val = ReverseNumber(rev_num_tc->number);
}

/**
 * @brief Creates and initializes a test case for the ReverseNumber function.
 *
 * @param expected The reversed value of the given unsigned integer.
 * @param test_case_num The identifier for the test case.
 * @param number The unsigned integer to reverse.
 * @return A ReverseNumberTestCase struct containing the initialized test case data.
 */
static reverse_num_tc CreateReverseNumberTC(unsigned expected, int test_case_num, unsigned number) { 
   reverse_num_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.u_val = expected}, 
                     (TestValue){.u_val = 0}, /* Sets 'actual' initial value to '0' */ 
                     test_case_num, TYPE_UNSIGNED_INT, TestReverseNumber), 
      .number = number
   };
    return test_case;
}

void RunTests(void) {
    size_t num_test_cases;
    size_t i; 

    reverse_num_tc test_cases[] = {
    CreateReverseNumberTC(321, 1, 123), /*  reverse of 123 = 321   */
    CreateReverseNumberTC(987, 2, 789), /*  reverse of 789 = 987   */
    CreateReverseNumberTC(456, 3, 654), /*  reverse of 654 = 456   */
    CreateReverseNumberTC(111, 4, 111), /*  reverse of 111 = 111   */
    CreateReverseNumberTC(100, 5, 001), /*  reverse of 001 = 100   */
    CreateReverseNumberTC(999, 6, 999), /*  reverse of 999 = 999   */
    CreateReverseNumberTC(321, 7, 123), /*  reverse of 123 = 321   */
    CreateReverseNumberTC(234, 8, 432), /*  reverse of 432 = 234   */
    CreateReverseNumberTC(123, 9, 321)  /*  reverse of 321 = 123   */
};
    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}
