#include "is_right_triangle.h"
#include "../../utils/math/float_comparisons.h"

/**
 * @brief Determines whether three sides satisfy the Pythagorean theorem.
 *  
 * @param a Potential side 
 * @param b Potential side
 * @param c Potential hypotenuse
 * @return 1 if the sides satisfy the Pythagorean theorem, 0 otherwise
 */
static int IsRight(float a, float b, float c) {
    return IsEqualFloat(a*a + b*b, c*c); 
}

int IsRightTriangle(float a, float b, float c) {
   return (IsRight(a ,b ,c) ||(IsRight(a, c, b) || IsRight(b, c, a)));
} 

/** 
 * @note Alternate approuch:
 *       if (IsRight(a, b, c)) return 1;
 *       if (IsRight(a, c, b)) return 1;
 *       if (IsRight(b, c, a)) return 1;
 *       return 0;
 */
