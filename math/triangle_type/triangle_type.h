#ifndef TRIANGLE_TYPE_H
#define TRIANGLE_TYPE_H

#include "../../utils/utils.h"

/** 
 * @struct TriangleTypeTestCase
 * @brief Structure representing a test case for determining a triangle's
 *        type based on its angles.
 */
typedef struct TriangleTypeTestCase {
shared_tc s_tc;
unsigned angle_a;
unsigned angle_b;
} triangle_type_tc;
   
/**
 * @brief Determines the type of triangle based on two given angles.
 *
 * @param angle_a The first given angle of the triangle.
 * @param angle_b The second given angle of the triangle.
 * @return An integer representing the type of the triangle.
 */
int TriangleType(unsigned angle_a, unsigned angle_b);

/**
 * @brief Runs a set of TriangleType function test cases.
 */
void RunTests(void);

#endif
