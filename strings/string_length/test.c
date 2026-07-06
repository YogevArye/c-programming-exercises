#include "string_length.h"

/**
 * @brief Tests the StringLength function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestStringLength(shared_tc* s_tc) {
    str_len_tc* s_l_tc = (str_len_tc*)s_tc;
    s_l_tc->s_tc.actual.st_val = StringLength(s_l_tc->str);
}

/** 
 * @brief Creates and initializes a test case for the StringLength function.
 *
 * @param expected The length of the string (excluding the null terminator).
 * @param test_case_num The identifier for the test case.
 * @param str The string whose length is to be calculated.
 * @return A StringLengthTestCase struct containing the initialized test case data.
 */
static str_len_tc CreateStringLengthTC(size_t expected, int test_case_num, const char* str) {
                                      
   str_len_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                    (TestValue){.st_val = expected}, 
                    (TestValue){.st_val = 0}, /* Sets 'actual' initial value to '0' */ 
                    test_case_num, TYPE_SIZE_T, TestStringLength),                               
      .str = str
    };

    return test_case;
}

void RunTests(void) {
  size_t num_test_cases;
  size_t i;

str_len_tc test_cases[] = {
    CreateStringLengthTC(10,  1, "yogev arye"),          /* Length of "yogev arye" is 12  */
    CreateStringLengthTC( 5,  2, "hello"),               /* Length of "hello" is 5        */
    CreateStringLengthTC( 7,  3, "goodbye"),             /* Length of "goodbye" is 7      */
    CreateStringLengthTC( 9,  4, "test case"),           /* Length of "test case" is 9    */
    CreateStringLengthTC(18,  5, "string length test"),  /* Length of "string length 
                                                            test" is 15                   */
    CreateStringLengthTC( 4,  6, "data"),                /* Length of "data" is 4         */
    CreateStringLengthTC(12,  7, "example text"),        /* Length of "example text"
                                                            is 11                         */
    CreateStringLengthTC( 7,  8, "testing"),             /* Length of "testing" is 8      */
    CreateStringLengthTC(18,  9, "function prototype"),  /* Length of "function prototype"
                                                            is 14                         */
    CreateStringLengthTC(17, 10, "unit test example"),   /* Length of "unit test example"
                                                            is 13                         */
    CreateStringLengthTC(INT_MIN, 11, NULL),             /* NULL case                     */
    CreateStringLengthTC( 0, 12, ""),                    /* Empty string                  */
    CreateStringLengthTC(46, 13, "A very long string with a lot of characters..."), 
                                                         /* Long string                   */
    CreateStringLengthTC( 5, 14, "     "),               /* String with spaces only       */
    CreateStringLengthTC( 1, 15, "\t"),                  /* String with a tab             */
    CreateStringLengthTC(11, 16, "hello\nworld"),        /* String with newline           */
    CreateStringLengthTC(10, 17, "1234567890"),          /* Numeric string                */
    CreateStringLengthTC( 2, 18, "a!"),                  /* Special characters            */
    CreateStringLengthTC(16, 19, "case-insensitive"),    /* Mixed case string             */
    CreateStringLengthTC(10, 20, "A1B2C3D4E5")           /* Alphanumeric string           */
};

     
    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}
