#include "divide.h"

/** 
 * @brief Checks for the overflow condition specific to integer division.
 *
 * @param numerator: The dividend in the division operation.
 * @param denominator: The divisor in the division operation.
 * @return: Returns 1 (true) if the overflow condition is detected; otherwise, returns 0 (false).
 */
static int CheckOverflow(int numerator, int denominator) {
    return (numerator == INT_MIN && denominator == -1);
}

int Divide(int numerator ,int denominator, int* quotient , int* remainder) {

  /** 
   * @note Using -1 and INT_MAX for error handling, as these values
   *       do not conflict with valid return values. Since only two errors
   *       are currently handled, this approach is sufficient.
   */
  if (denominator == 0) {
      return -1;
  } else if (CheckOverflow(numerator, denominator)) {
    return INT_MAX;
  } 
   
  *quotient  = numerator / denominator;
  *remainder  = numerator % denominator;

  return 0;
}
    
