#include "triangle_type.h"

/**
 * @brief Tests the TriangleType function using the provided test case.
 *
 * @param s_tc A pointer to a SharedTestCase structure, used to centralize 
 *             common test data for consistency across different exercises.
 * @note This function is invoked by the test case management utility.
 */
static void TestTriangleType(shared_tc* s_tc) {
    triangle_type_tc* tr_type_tc = (triangle_type_tc*)s_tc;
    tr_type_tc->s_tc.actual.i_val = TriangleType(tr_type_tc->angle_a, tr_type_tc->angle_b);
}     

/**
 * @brief Creates and initializes a test case for the TriangleType function.
 *
 * @param expected An integer representing the type of the triangle.
 * @param test_case_num The identifier for the test case.
 * @param angle_a The first given angle of the triangle.
 * @param angle_b The second given angle of the triangle.
 * @return A TriangleTypeTestCase struct containing the initialized test case data.
 */
static triangle_type_tc CreateTriangleTypeTC(int expected, int test_case_num,
                                             unsigned angle_a, unsigned angle_b) { 
   triangle_type_tc test_case = {
      .s_tc  = CreateSharedTCValuesCase(
                     (TestValue){.i_val = expected}, 
                     (TestValue){.i_val = 0}, /* Sets 'actual' initial value to '0' */ 
                     test_case_num, TYPE_INT, TestTriangleType), 
      .angle_a = angle_a,
      .angle_b = angle_b
   };

    return test_case;
}

void RunTests(void) {
    size_t num_test_cases;
    size_t i;

   triangle_type_tc test_cases[] = {
    CreateTriangleTypeTC( 3,   1,  45, 45),   /* Right-angled isosceles triangle: 45°, 45°, 90° */
    CreateTriangleTypeTC( 2,   2,  70, 70),   /* Isosceles triangle: 70°, 70°, 40° */
    CreateTriangleTypeTC( 1,   3,  30, 60),   /* Right-angled triangle: 30°, 60°, 90° */
    CreateTriangleTypeTC( 1,   4,  40, 50),   /* Right-angled triangle: 40°, 50°, 90° */
    CreateTriangleTypeTC(-1,   5, 100, 80),   /* Invalid: angles sum to 180° or more */
    CreateTriangleTypeTC( 2,   6,  50, 50),   /* Isosceles triangle: 50°, 50°, 80° */
    CreateTriangleTypeTC( 1,   7,  35, 55),   /* Right-angled triangle: 35°, 55°, 90° */
    CreateTriangleTypeTC( 1,   8,  36, 54),   /* Right-angled triangle: 36°, 54°, 90° */
    CreateTriangleTypeTC(-1,   9,  95, 85),   /* Invalid: angles sum to 180° or more */
    CreateTriangleTypeTC( 2,  10,  80, 50),   /* Isosceles triangle: 80°, 50°, 50° */
    CreateTriangleTypeTC( 0,  11,  75, 52),   /* Scalene triangle: 75°, 52°, 53° */
    CreateTriangleTypeTC(-1,  12, 100, 90),   /* Invalid: angles sum to 180° or more */
    CreateTriangleTypeTC( 1,  13,  33, 57),   /* Right-angled triangle: 33°, 57°, 90° */
    CreateTriangleTypeTC( 2,  14,  58, 58),   /* Isosceles triangle: 58°, 58°, 64° */
    CreateTriangleTypeTC( 1,  15,  44, 46)    /* Right-angled triangle: 44°, 46°, 90° */
};


    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (i = 0; i < num_test_cases; ++i) {
        PrintTCNum(&test_cases[i].s_tc);
        printf("Angle_a: %u, Angle_b: %u\n", test_cases[i].angle_a, test_cases[i].angle_b);
        RunAndValidateTest(&test_cases[i].s_tc);
        PrintSharedTC(&test_cases[i].s_tc, &expected_label, &actual_label);
    }
}
    