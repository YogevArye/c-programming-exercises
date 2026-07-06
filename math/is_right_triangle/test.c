#include "is_right_triangle.h"

/**
 * @brief Tests the IsRightTriangle function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestRightTriangle(shared_tc* s_tc) {
    right_triangle_tc* rt_test = (right_triangle_tc*)s_tc;
    rt_test->s_tc.actual.i_val = IsRightTriangle(rt_test->a, rt_test->b, rt_test->c);
}

/**
 * @brief Creates and initializes a test case for the IsRightTriangle function.
 *
 * @param expected Indicates whether the given sides form a right triangle (1) or not (0).
 * @param test_case_num The identifier for the test case.
 * @param a Side length a.
 * @param b Side length b.
 * @param c Side length c.
 * @return A IsRightTriangleTestCase struct containing the initialized test case data.
 */
static right_triangle_tc CreateRightTriangleTC(int expected, int test_case_num,
                                               float a, float b, float c) {
   right_triangle_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.i_val = expected}, 
                     (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */ 
                     test_case_num, TYPE_INT, TestRightTriangle), 
      .a = a,
      .b = b,
      .c = c
   };
    return test_case;
}

void RunTests(void) {
    size_t num_test_cases , i;
   
    right_triangle_tc test_cases[] = 
    {
        CreateRightTriangleTC(1,  1,  3.0,   4.0,   5.0),  /* Right triangle: 3, 4, 5      */
        CreateRightTriangleTC(0,  2,  1.0,   1.0,   2.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1,  3,  5.0,  12.0,  13.0),  /* Right triangle: 5, 12, 13    */
        CreateRightTriangleTC(0,  4,  7.0,  10.0,  12.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1,  5,  8.0,  15.0,  17.0),  /* Right triangle: 8, 15, 17    */
        CreateRightTriangleTC(0,  6,  2.0,   2.0,   3.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1,  7,  9.0,  40.0,  41.0),  /* Right triangle: 9, 40, 41    */
        CreateRightTriangleTC(1,  8,  6.0,   8.0,  10.0),  /* Right triangle: 6, 8, 10     */
        CreateRightTriangleTC(0,  9,  5.0,   5.0,   7.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1, 10, 11.0,  60.0,  61.0),  /* Right triangle: 11, 60, 61   */
        CreateRightTriangleTC(0, 11,  2.0,   3.0,   5.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1, 12,  7.0,  24.0,  25.0),  /* Right triangle: 7, 24, 25    */
        CreateRightTriangleTC(0, 13,  1.0,   2.0,   2.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1, 14, 12.0,  35.0,  37.0),  /* Right triangle: 12, 35, 37   */
        CreateRightTriangleTC(0, 15,  4.0,   4.0,   5.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1, 16, 15.0, 112.0, 113.0),  /* Right triangle: 15, 112, 113 */
        CreateRightTriangleTC(0, 17,  2.0,   5.0,   6.0),  /* Not a right triangle         */
        CreateRightTriangleTC(1, 18, 20.0,  21.0,  29.0)   /* Right triangle: 20, 21, 29   */
    };

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0 ; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}
