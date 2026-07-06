#ifndef IS_RIGHT_TRIANGLE_H
#define IS_RIGHT_TRIANGLE_H

#include "../../utils/utils.h"

/** 
 * @struct IsRightTriangleTestCase
 * @brief Structure represents a test case for determining whether
 *        three sides form a right triangle.
 */
typedef struct IsRightTriangleTestCase {
    shared_tc s_tc;
    float a, b, c;              
} right_triangle_tc;

/**
 * @brief Determines whether three side lengths form a right triangle by
 *        verifying the Pythagorean theorem.
 * 
 * @param a Side length a
 * @param b Side length b
 * @param c Side length c
 * @return 1 if the sides form a right triangle, 0 otherwise
 */
int IsRightTriangle(float a, float b, float c);
 
/**
 * @brief Runs a set of test cases for the IsRightTriangle function.
 */
void RunTests(void);

#endif 
