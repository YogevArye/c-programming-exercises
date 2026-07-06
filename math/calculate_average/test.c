#include "calculate_average.h"

/**
 * @brief Creates and initializes test arrays for average calculations.
 *
 * @param a1 Pointer to the first array.
 * @param a2 Pointer to the second array.
 *            .........             
 *            .........
 *            .........
 * @param a21 Pointer to the nineteenth array.
 */          
static void CreateTestArrays(long long **a1, long long **a2, long long **a3, long long **a4,
                         long long **a5,  long long **a6, long long **a7, long long **a8,
                         long long **a9, long long **a10, long long **a11, long long **a12,
                         long long **a13, long long **a14, long long **a15, long long **a16, 
                         long long **a17, long long **a18, long long **a19, long long **a20,
                         long long **a21) {
    static long long temp_a1[] = {-1, -2, -3, -4};
    static long long temp_a2[] = {10};
    static long long temp_a3[] = {0, 0, 0, 0, 0}; 
    static long long temp_a4[] = {-1, -2, -3, -4, -5};
    static long long temp_a5[] = {5, 15, 25, 35, 45};
    static long long temp_a6[] = {3, 6, 9};
    static long long temp_a7[] = {0, -1, -2};
    static long long temp_a8[] = {100, 200};
    static long long temp_a9[] = {INT_MAX, INT_MIN};
    static long long temp_a10[] = {INT_MAX - 1};
    static long long temp_a11[] = {LONG_MAX, 1};  
    static long long temp_a12[] = {LONG_MIN, -1}; 
    static long long temp_a13[] = {INT_MAX, INT_MAX}; 
    static long long temp_a14[] = {INT_MIN, INT_MIN}; 
    static long long temp_a15[] = {INT_MAX, INT_MAX, INT_MAX}; 
    static long long temp_a16[] = {INT_MIN, INT_MIN, INT_MIN}; 
    static long long temp_a17[] = {INT_MAX}; 
    static long long temp_a18[] = {INT_MIN}; 
    static long long temp_a19[] = {}; 
    static long long temp_a20[] = {LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, 
                                  LLONG_MAX, LLONG_MAX,LLONG_MAX,LLONG_MAX};
    static long long temp_a21[] = {LLONG_MIN, LLONG_MIN};

    *a1 = temp_a1;
    *a2 = temp_a2;
    *a3 = temp_a3;
    *a4 = temp_a4;
    *a5 = temp_a5;
    *a6 = temp_a6;
    *a7 = temp_a7;
    *a8 = temp_a8;
    *a9 = temp_a9;
    *a10 = temp_a10;
    *a11 = temp_a11;
    *a12 = temp_a12;
    *a13 = temp_a13;
    *a14 = temp_a14;
    *a15 = temp_a15;
    *a16 = temp_a16;
    *a17 = temp_a17;
    *a18 = temp_a18;
    *a19 = temp_a19;
    *a20 = temp_a20;
    *a21 = temp_a21;
}

/**
 * @brief Prints the corresponding error message for a given AverageErrorCode.
 *
 * @param error_code The error code returned by the CalculateAverage function.
 */
static void PrintErrorCode(avg_error_code error_code) {
  switch (error_code) {
    case AVG_EMPTY_ARRAY:
        printf("Empty Array - No Average!\n");
        break;
    case AVG_OVERFLOW_SUMMATION:
        printf("Error: Overflow during summation.\n");
        break;
    case AVG_UNDERFLOW_SUMMATION:
        printf("Error: Underflow during summation.\n");
        break;
    default:
        break;
    }
}

/**
 * @brief Tests the CalculateAverage function using the provided test
 *        case and prints any errors if needed.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestAverage(shared_tc* s_tc) {
    average_tc* avg_test = (average_tc*)s_tc;
    avg_result result = CalculateAverage(avg_test->array, avg_test->size);
    avg_test->s_tc.actual.i_val = result.average;
    PrintErrorCode(result.error_code);
}

/**
 * @brief Creates and initializes a test case for the CalculateAverage function.
 *
 * @param expected Indicates the average value of the given array elements.
 * @param test_case_num The identifier for the test case.
 * @param array Pointer to an array of long long integers for which to calculate the average.
 * @param size The number of elements within the array.
 * @return A AverageTestCase struct containing the initialized test case data.
 */
static average_tc CreateAverageTC(int expected, int test_case_num, long long* array, int size) {
    average_tc test_case = {
        .s_tc  = CreateSharedTCValuesCase(
                    (TestValue){.i_val = expected}, 
                    (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */
                    test_case_num, TYPE_INT, TestAverage),                               
        .array = array,
        .size = size 
    };
    return test_case;
}

void RunTests() {
    size_t num_test_cases;
    size_t i;

    long long *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, 
        *a15, *a16, *a17, *a18, *a19, *a20, *a21;
        
    CreateTestArrays(&a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12, &a13,
                     &a14, &a15, &a16, &a17, &a18, &a19, &a20, &a21);  
      
 average_tc test_cases[] = {
    CreateAverageTC(         -3,  1,  a1, 4),  /* Valid average calculation */
    CreateAverageTC(         10,  2,  a2, 1),  /* Valid average calculation */
    CreateAverageTC(          0,  3,  a3, 5),  /* Valid average calculation */
    CreateAverageTC(         -3,  4,  a4, 5),  /* Valid average calculation */
    CreateAverageTC(         25,  5,  a5, 5),  /* Valid average calculation */
    CreateAverageTC(          6,  6,  a6, 3),  /* Valid average calculation */
    CreateAverageTC(         -1,  7,  a7, 3),  /* Valid average calculation */
    CreateAverageTC(        150,  8,  a8, 2),  /* Valid average calculation */
    CreateAverageTC(         -1,  9,  a9, 2),  /* Valid average calculation */
    CreateAverageTC( 2147483646, 10, a10, 1),  /* Valid average calculation */
    CreateAverageTC( 1073741824, 11, a11, 2),  /* Valid average calculation */  
    CreateAverageTC(-1073741825, 12, a12, 2),  /* Valid average calculation */  
    CreateAverageTC( 2147483647, 13, a13, 2),  /* Valid average calculation */
    CreateAverageTC(-2147483648, 14, a14, 2),  /* Valid average calculation */
    CreateAverageTC( 2147483647, 15, a15, 3),  /* Valid average calculation */
    CreateAverageTC(-2147483648, 16, a16, 3),  /* Valid average calculation */
    CreateAverageTC( 2147483647, 17, a17, 1),  /* Valid average calculation */
    CreateAverageTC(-2147483648, 18, a18, 1),  /* Valid average calculation */
    CreateAverageTC(          0, 19, a19, 0),  /* An empty array */
    CreateAverageTC(          0, 20, a20, 8),  /* Overflow detected during summation */
    CreateAverageTC(          0, 21, a21, 2)   /* Underflow detected during summation */
};

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) { 
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }   
}