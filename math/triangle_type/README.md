Triangle Type Identifier

Overview
This project determines the type of a triangle based on two given angles. 
It includes a set of test cases to validate the correctness of the triangle classification logic. 
The project provides an improved version of the triangle classification function to ensure better accuracy and efficiency.

Features
    Classifies triangles based on given angles into different 
    types:
  - Invalid triangle
  - Right-angled triangle
  - Isosceles triangle
  - Right-angled isosceles triangle
  - Includes test cases to ensure accuracy of the  
    classification function.
  - Improved classification function for better performance.

Files
main.c: Entry point for program execution.
triangle_type.h: Header file containing declarations for the triangle classification function and test function.
v1.c: Initial implementation of the triangle classification function.
v2.c: Improved implementation of the triangle classification function.
test.c: Contains test cases for validating the triangle classification function.

Usage

Compile and Link:
gcc -o triangle_type main.c triangle_type.c test.c ^
 ../../utils/utils.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c 

Run:
./triangle_type (On Windows: triangle_type)


