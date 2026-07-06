#include "divide.h"

/**
 * @brief Prints error messages based on the provided error code.
 *
 * @param error_code: The error code representing the specific error condition.
 */
static void PrintErrorCode(int error_code) {

   /** 
    * @note Using simple if-else logic instead of a switch,
    *       as there are only two cases to handle.
    *       No plans to expand this function beyond the current 
    *       error cases (division by zero and overflow).
    */
    if (error_code == -1) {
        printf("Error: Division by zero detected.\n");
    } else if (error_code == INT_MAX) {
        printf("Error: Overflow detected during division.\n");
    }
}

/**
 * @brief Tests the Divide function using the provided test case
 *        and prints any errors if needed.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestDivide(shared_tc* s_tc) {
    divide_tc* div_tc = (divide_tc*)s_tc;

    div_tc->s_tc.actual_array[0].i_val = Divide(div_tc->numerator, div_tc->denominator,
                                                &div_tc->s_tc.actual_array[1].i_val,
                                                &div_tc->s_tc.actual_array[2].i_val);
    PrintErrorCode(div_tc->s_tc.actual_array[0].i_val);                                           
}

/**
 * @brief Creates and initializes a test case for the Divide function.
 *
 * @param expected_return Indicates whether the division succeeded (0) or failed (-1, INT_MAX).
 *                        
 * @param expected_quotient The quotient of the division.
 * @param expected_remainder The remainder of the division.
 * @param test_case_num The identifier for the test case.
 * @param numerator The given numerator for the division operation.
 * @param denominator The given denominator for the division operation.
 * @return A DivideTestCase struct containing the initialized test case data.
 */
static divide_tc CreateDivideTC(int expected_return, int expected_quotient, int expected_remainder,
                                int test_case_num, int numerator, int denominator) {
    TestValue expected_array[] = {
        {.i_val = expected_return},
        {.i_val = expected_quotient},
        {.i_val = expected_remainder}
    };
    TestValue actual_array[] = {
        {.i_val = 0},
        {.i_val = 0},
        {.i_val = 0}
    };

    divide_tc test_case = {
        .s_tc  = CreateSharedTCArraysCase(expected_array, actual_array,
                                                 3, test_case_num, 
                                                 TYPE_INT, TestDivide),                               
        .numerator = numerator,
        .denominator = denominator
    };
    return test_case;
}

void RunTests(void) {
   size_t num_test_cases;
   size_t i;

   const char* expected_labels [] = {"Expected Divide Function's Return", "Expected Quotient",
                                     "Expected Remainder"};
   const char* actual_labels [] = {"Actual Divide Function's Return", "Actual Quotient",
                                   "Actual Remainder"};
        
   divide_tc test_cases[] = {
     CreateDivideTC( 0,          3,       1,  1,   10,      3),  /* Division of 10 by 3 */
     CreateDivideTC( 0,          3,      -1,  2,  -10,     -3),  /* Division of -10 by -3 */
     CreateDivideTC(-1,          0,       0,  3,   10,      0),  /* Division of 10 by 0 */
     CreateDivideTC( 0,         -3,      -1,  4,  -10,      3),  /* Division of -10 by 3 */
     CreateDivideTC( 0,          7,       0,  5,    7,      1),  /* Division of 7 by 1 */
     CreateDivideTC( 0,          0,       0,  6,    0,      5),  /* Division of 0 by 5 */
     CreateDivideTC( 0,         -3,       1,  7,   10,     -3),  /* Division of 10 by -3 */
     CreateDivideTC( 0,         INT_MAX,  0,  8,  INT_MAX,  1),  /* Division of INT_MAX by 1 */
     CreateDivideTC(INT_MAX,     0,       0,  9,  INT_MIN, -1),  /* Division of INT_MIN by -1 */
     CreateDivideTC( 0,        -INT_MAX,  0, 10, -INT_MAX,  1),  /* Division of -INT_MAX by 1 */
     CreateDivideTC( 0,          2,       1, 11,    5,      2),  /* Division of 5 by 2 */
     CreateDivideTC( 0,          0,       0, 12,    0,      1),  /* Division of 0 by 1 */
     CreateDivideTC( 0,          3,       0, 13,   15,      5),  /* Division of 15 by 5 */
     CreateDivideTC( 0,          5,       0, 14,   20,      4)   /* Division of 20 by 4 */
};

   num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

   for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, expected_labels, actual_labels);
        
        free(test_cases[i].s_tc.expected_array);
        free(test_cases[i].s_tc.actual_array);
    }
}
