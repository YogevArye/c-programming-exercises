#include "approx_sqrt.h"

float ApproximateSqrt(float num) {
    float sqrt;
    float temp;
  
    sqrt = num / 2;
    temp = 0;

    /**
     * @note This implementation uses `sqrt != temp` for loop termination.
     *       While `fabs(sqrt - temp) > EPSILON` generally may offer more precision and
     *       potentially reduce iterations, for this exercise, the simpler approach
     *       is sufficient and avoids unnecessary complexity.
     */
    while (sqrt != temp) {
       temp = sqrt;
       sqrt = (sqrt + num / sqrt) / 2;  
    }

   return sqrt;
}