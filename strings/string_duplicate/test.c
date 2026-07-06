#include "duplication.h"

/**
 * @brief Tests the StringDuplicate function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestStringDuplication(shared_tc* s_tc) {
    s_tc->actual.str_val = StringDuplicate(s_tc->expected.str_val);
}     

/**
 * @brief Creates and initializes a test case for the StringDuplicate function.
 *
 * @param expected The string to duplicate (may be NULL); also used as the expected result.
 * @param test_case_num The identifier for the test case.
 * @return A SharedTestCase struct containing the initialized test case data.
 */
static shared_tc CreateStringDuplicationTC(char* expected, int test_case_num) { 
   return CreateSharedTCValuesCase((TestValue){.str_val = expected}, 
                                   (TestValue){.str_val = NULL}, /* Sets 'actual' initial value to 'NULL' */ 
                                    test_case_num, TYPE_STRING,
                                    TestStringDuplication);
}

void RunTests(void) {
    size_t num_test_cases;
    size_t i;

    shared_tc test_cases[] = {
    CreateStringDuplicationTC("hello world",     1),   /* Copy 'hello world' */
    CreateStringDuplicationTC("good morning",    2),   /* Copy 'good morning' */
    CreateStringDuplicationTC("open sesame",     3),   /* Copy 'open sesame' */
    CreateStringDuplicationTC("happy birthday",  4),   /* Copy 'happy birthday' */
    CreateStringDuplicationTC("quick brown",     5),   /* Copy 'quick brown' */
    CreateStringDuplicationTC("fox jumps",       6),   /* Copy 'fox jumps' */
    CreateStringDuplicationTC("over fence",      7),   /* Copy 'over fence' */
    CreateStringDuplicationTC("lazy dog",        8),   /* Copy 'lazy dog' */
    CreateStringDuplicationTC("bright stars",    9),   /* Copy 'bright stars' */
    CreateStringDuplicationTC("green grass",    10),   /* Copy 'green grass' */
    CreateStringDuplicationTC("blue sky",       11),   /* Copy 'blue sky' */
    CreateStringDuplicationTC("deep ocean",     12),   /* Copy 'deep ocean' */
    CreateStringDuplicationTC("red apple",      13),   /* Copy 'red apple' */
    CreateStringDuplicationTC("golden sunset",  14),   /* Copy 'golden sunset' */
    CreateStringDuplicationTC("snowy mountain", 15),   /* Copy 'snowy mountain' */
    CreateStringDuplicationTC(NULL,             16)    /* NULL Case */
};
    
    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i]);
        RunAndValidateTest(&test_cases[i]);
        PrintSharedTC(&test_cases[i], &expected_label, &actual_label);  
        free(test_cases[i].expected.str_val);  
        free(test_cases[i].actual.str_val);  
    }
}