#ifndef CALCULATE_AVERAGE_H
#define CALCULATE_AVERAGE_H

#include "../../utils/utils.h" 

/** 
 * @enum AverageErrorCode
 * @brief Enum for different error codes that can occur during average calculation.
 */
typedef enum AverageErrorCode {
    AVG_SUCCESS = 0,
    AVG_EMPTY_ARRAY,
    AVG_OVERFLOW_SUMMATION,
    AVG_UNDERFLOW_SUMMATION,
} avg_error_code;

/** 
 * @struct AverageResult
 * @brief Structure to hold the result of the CalculateAverage function.
 */
typedef struct AverageResult {
    int average;
    avg_error_code error_code;
} avg_result;

/** 
 * @struct AverageTestCase
 * @brief Structure representing a test case for average calculations.
 */
typedef struct AverageTestCase {
    shared_tc s_tc;
    const long long *array;
    size_t size;
} average_tc;

/**
 * @brief Calculates the average of an array of long long integers.
 *
 * @param array The array of long long integers to be averaged.
 * @param size The number of elements in the array.
 * @return An AverageResult structure containing the calculated average 
 *         and an error code indicating success or type of failure.
 */
avg_result CalculateAverage(const long long array[], size_t size);

/**
 * @brief Runs a set of CalculateAverage function test cases.
 */
void RunTests(void);

#endif 
