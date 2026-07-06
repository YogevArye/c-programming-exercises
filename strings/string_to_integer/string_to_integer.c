#include "string_to_integer.h"

int StringToInteger(const char *str) { 
  if (str == NULL) {
      return INT_MAX -2;
  }

  int sign = 1;
  int result = 0;

  while (*str == ' ') {
      ++ str;
  }
  
  if (*str == '-') {
      sign = -sign;
      ++ str;
  } else if (*str == '+') {
      ++ str;
  }
   
  /** 
   * @note Using INT_MAX, INT_MIN, and INT_MAX-1 for error handling,
   *       as these values do not conflict with valid return values.
   *       Since only three errors are currently handled, this approach
   *       is sufficient.
   */
  if (*str < '0' || *str > '9') {
        return INT_MAX - 1; 
    }
   
  while (*str >= '0' && *str <= '9') {

  /**  
   * @note Overflow: result * 10 + (*str - '0') > INT_MAX ->
   *                 result > (INT_MAX - (*str - '0')) / 10 
   *
   *       Underflow: -(result * 10 + (*str - '0')) < INT_MIN ->
   *                  -result < (INT_MIN + (*str - '0')) / 10  
   */
  if (sign == 1 && result > (INT_MAX - (*str - '0')) / 10) {
            return INT_MAX;
        } else if (sign == -1 && -result < (INT_MIN + (*str - '0')) / 10) {
            return INT_MIN;
        }

        result = result * 10 + (*str - '0');
        ++str;
    }

    return result * sign;
}
  
  



