#include "string_to_integer.h"

/**
 * @brief Prints error messages based on specific error codes returned by the StringToInteger function.
 *
 * @param actual_value The returned value from StringToInteger.
 */
static void PrintErrorCode(int actual_value) {
    if (actual_value == INT_MAX) {
        printf("Error: Overflow detected during casting\n");
    } else if (actual_value == INT_MIN) {
        printf("Error: Underflow detected during casting\n");
    } else if (actual_value == INT_MAX - 1) {
        printf("Error: Input beginning with a non-numeric character detected during testing\n");
    } else if (actual_value == INT_MAX - 2) {
        printf("Error: NULL input detected during testing\n");
    }
}

/**
 * @brief Tests the StringToInteger function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestStringToInt(shared_tc* s_tc) {
    str_int_tc* s_i_tc = (str_int_tc*)s_tc;
    s_i_tc->s_tc.actual.i_val = StringToInteger(s_i_tc->str);
    PrintErrorCode(s_i_tc->s_tc.actual.i_val);
}

/**
 * @brief Creates and initializes a test case for the StringToInteger function.
 *
 * @param expected The integer representation of the string.
 * @param test_case_num The identifier for the test case.
 * @param str The string to be converted.
 * @return A StringToIntTestCase struct containing the initialized test case data.
 */
static str_int_tc CreateStringToIntTC(int expected, int test_case_num, const char* str) {
   str_int_tc test_case = { 
      .s_tc  = CreateSharedTCValuesCase(
                    (TestValue){.i_val = expected}, 
                    (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */ 
                    test_case_num, TYPE_INT, TestStringToInt),                               
      .str = str
    };

    return test_case;
}

void RunTests(void) {
  size_t num_test_cases;
  size_t i;

  str_int_tc test_cases[] = {
     CreateStringToIntTC(123,          1, "123"),                 /* Valid integer string */
     CreateStringToIntTC(-456,         2, "-456"),                /* Valid negative integer string */
     CreateStringToIntTC(0,            3, "0"),                   /* Zero as a string */
     CreateStringToIntTC(789,          4, "  789"),               /* Leading spaces */
     CreateStringToIntTC(1011,         5, "1011  "),              /* Trailing spaces */
     CreateStringToIntTC(12,           6, "12abc34"),             /* Mixed alphanumeric, starts with number */
     CreateStringToIntTC(INT_MAX - 1,  7, "abc"),                 /* Does not begin with a numeric
                                                                        character. */
     CreateStringToIntTC(INT_MAX - 1,  8, ""),                    /* Does not begin with a numeric
                                                                        character. */
     CreateStringToIntTC(42,           9, "0042"),                /* Leading zeros */
     CreateStringToIntTC(INT_MAX - 1, 10, " "),                   /* Does not begin with a numeric 
                                                                        character. */
     CreateStringToIntTC(123,         11, "123abc"),              /* Number followed by letters */
     CreateStringToIntTC(INT_MAX - 1, 12, "abc123"),              /* Does not begin with a numeric
                                                                        character. */
     CreateStringToIntTC(123,         13, "123 456"),             /* Space-separated numbers */
     CreateStringToIntTC(INT_MAX - 1, 14, "hello 123"),           /* Does not begin with a numeric
                                                                       character. */
     CreateStringToIntTC(123,         15, "123 hello"),           /* Number followed by word */
     CreateStringToIntTC(INT_MAX,     16, "123456789012345"),     /* Overflow during casting */
     CreateStringToIntTC(INT_MAX - 1, 17, "longstring123456"),    /* Does not begin with a numeric 
                                                                        character. */
     CreateStringToIntTC(123456,      18, "123456longstring"),    /* Long mixed string starting with
                                                                        numbers */
     CreateStringToIntTC(1234567890,  19, "1234567890abcdefg"),   /* Long alphanumeric string */
     CreateStringToIntTC(INT_MAX - 1, 20, "abcdefg1234567890"),   /* Does not begin with a numeric
                                                                        character. */
     CreateStringToIntTC(INT_MIN,     21, "-2147483649"),         /* Underflow during casting */
     CreateStringToIntTC(0,           22, "0000000000000"),        /* 0000000000000 */
     CreateStringToIntTC(INT_MAX -2,  23, NULL)                    /* NULL case */
};

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for ( i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
  }
}
