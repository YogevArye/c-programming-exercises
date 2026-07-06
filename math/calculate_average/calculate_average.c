#include "calculate_average.h"

/**
 * @brief Checks if adding a value to the total will cause overflow.
 *
 * @param total The current total sum of the array elements.
 * @param value The long long integer value to be added.
 * @return 1 if adding the value would cause overflow, otherwise 0.
 */
static int CheckOverflowSum(long long total, long long value) {
    return (value > 0 && total > LLONG_MAX - value);
}

/**
 * @brief Checks if subtracting a value from the total will cause underflow.
 *
 * @param total The current total sum of the array elements.
 * @param value The long long integer value to be subtracted.
 * @return 1 if subtracting the value would cause underflow, otherwise 0.
 */
static int CheckUnderflowSum(long long total, long long value) {
    return (value < 0 && total < LLONG_MIN - value);
}

/**
 * @brief Rounds the average of the total based on the size.
 *
 * @param total The total value to be averaged.
 * @param size The number of elements used for averaging.
 * @return The rounded average value as a long long integer.
 *
 * @example For total = 10 and size = 4:
 *          (10 + (4 / 2)) / 4 = (10 + 2) / 4 = 12 / 4 = 3
 *
 *          For total = -10 and size = 4:
 *          (-10 - (4 / 2)) / 4 = (-10 - 2) / 4 = -12 / 4 = -3
 */
static long long RoundedAverage(long long total, size_t size) {
    if (total >= 0) {
        return (total + (size / 2)) / size;   
    } else {
        return (total - (size / 2)) / size;
    }
}

avg_result CalculateAverage(const long long array[], size_t size) {
    avg_result result = {0, AVG_SUCCESS};
    long long total = 0;
    size_t i;

    if (size == 0) {
        result.error_code = AVG_EMPTY_ARRAY;
        return result;   
    }

    for (i = 0; i < size; ++i) { 

        /** 
         * @note Overflow Behavior: 
         *       Using long long (or int64_t) ensures we handle large sums
         *       consistently across both 32-bit and 64-bit platforms.
         *       On 32-bit systems, long long (64 bits) is necessary
         *       to avoid overflow when summing large integers.
         * 
         *       On 64-bit systems, long is already 64 bits, so technically,
         *       using long could also work. However, using long long provides
         *       uniform behavior across different architectures,
         *       ensuring compatibility and preventing platform-specific issues.
         */
        if (CheckOverflowSum(total, array[i])) {
            result.error_code = AVG_OVERFLOW_SUMMATION; 
            return result;     
        } else if (CheckUnderflowSum(total, array[i])) {
            result.error_code = AVG_UNDERFLOW_SUMMATION; 
            return result; 
        }
        
        total += array[i]; 
    }

    /**
     * @note Potential Issue:
     *       Using avg = (float)total / size or avg = (double)total / size
     *       can cause rounding errors with large integers due to the precision
     *       limitations of floating-point representation. For example, 
     *       total = 2147483646 and size = 1 may yield an inaccurate
     *       average of 2147483688.000000.
     *
     *       To avoid this, we use RoundedAverage for rounding via integer
     *       arithmetic, preserving the exact value before conversion.
     *       This ensures the calculated average is accurate, even for large sums.
     */
    result.average = RoundedAverage(total, size);

    return result;    
}


