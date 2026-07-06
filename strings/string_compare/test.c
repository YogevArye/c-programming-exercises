#include "string_compare.h"

/**
 * @brief Tests the StringCompare function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestStringCompare(shared_tc* s_tc) {
    string_compare_tc* str_compare_tc = (string_compare_tc*)s_tc;
    str_compare_tc->s_tc.actual.i_val = StringCompare(str_compare_tc->str1, str_compare_tc->str2);
}     

/**
 * @brief Creates and initializes a test case for the StringCompare function.
 *
 * @param expected The lexicographical comparison result of the two strings.
 * @param test_case_num The identifier for the test case.
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return A StringCompareTestCase struct containing the initialized test case data.
 */
static string_compare_tc CreateStringCompareTC(int expected, int test_case_num, char* str1, char* str2) {                                        
   string_compare_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.i_val = expected}, 
                     (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */ 
                     test_case_num, TYPE_INT, TestStringCompare), 
      .str1 = str1,
      .str2 = str2
   };
    return test_case;
}

void RunTests(void) {
    string_compare_tc test_cases[] = {
    CreateStringCompareTC(  0,   1,  "apple",  "apple"),       /* Equal strings         */
    CreateStringCompareTC(  1,   2,  "banana", "apple"),       /* 'b' - 'a' = 1         */
    CreateStringCompareTC( -1,   3,  "apple",  "banana"),      /* 'a' - 'b' = -1        */
    CreateStringCompareTC(  0,   4,  "grape",  "grape"),       /* Equal strings         */
    CreateStringCompareTC(  3,   5,  "orange", "lemon"),       /* 'o' - 'l' = 3         */
    CreateStringCompareTC( -3,   6,  "lemon",  "orange"),      /* 'l' - 'o' = -3        */
    CreateStringCompareTC(  0,   7,  "cherry", "cherry"),      /* Equal strings         */
    CreateStringCompareTC( 15,   8,  "pear",   "apple"),       /* 'p' - 'a' = 15        */
    CreateStringCompareTC(-15,   9,  "apple",  "pear"),        /* 'a' - 'p' = -15       */
    CreateStringCompareTC(  0,  10,  "mango",  "mango"),       /* Equal strings         */
    CreateStringCompareTC( 10,  11,  "kiwi",   "apple"),       /* 'k' - 'a' = 10        */
    CreateStringCompareTC(-10,  12,  "apple",  "kiwi"),        /* 'a' - 'k' = -10       */
    CreateStringCompareTC(  0,  13,  "peach",  "peach"),       /* Equal strings         */
    CreateStringCompareTC(  9,  14,  "plum",   "grape"),       /* 'p' - 'g' = 9         */
    CreateStringCompareTC( -9,  15,  "grape",  "plum"),        /* 'g' - 'p' = -9        */
    CreateStringCompareTC( INT_MIN,  16,  NULL,  "non-empty"), /* First string is NULL  */
    CreateStringCompareTC( INT_MIN,  17,  "non-empty", NULL),  /* Second string is NULL */
    CreateStringCompareTC( INT_MIN,  18,  NULL,  NULL)         /* Both strings are NULL */
};

    size_t i, num_test_cases;

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}