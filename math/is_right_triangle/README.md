Right Triangle Checker

Overview
This project implements a program to check if three given sides form a right triangle using floating-point arithmetic with an approximation. 
The project includes a set of test cases to verify the correctness of the solution.

Features
- Functions to calculate and compare floating-point values 
  with a tolerance for error (epsilon).
- Two versions of the right triangle checker function (v1 and 
  v2), with v2 optimized for better readability and 
  modularity, which simplifies maintenance and can potentially 
  aid in performance optimizations in more complex scenarios.
- Test cases to ensure the accuracy of the right triangle 
  check.

Files
is_right_triangle.h: Header file.
main.c: Entry point for program execution.
test.c: Contains test cases and automated testing logic.
v1.c: First implementation of the right triangle checker.
v2.c: Improved version of the right triangle checker with  
      better structure.

Usage
Compile and Link
gcc -o triangle_test is_right_triangle.c main.c test.c ^
../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c ^
 ../../utils/utils.c 

Run:
./triangle_test (On Windows: triangle_checker)


