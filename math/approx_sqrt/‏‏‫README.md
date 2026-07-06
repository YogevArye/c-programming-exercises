Square Root Calculation using Babylonian Method

Overview
This project implements the Babylonian method (also known as Heron's method) for calculating the square root of a given number. 
It includes a header file, a source file, and a test file.

Features
- Computes the square root of a float number using an iterative method.
- Header, source, and test files separated for modularity.

Files
main.c: Entry point for program execution.
sqrt_babylonian.h: Header file declaring the functions.
sqrt_babylonian.c: Source file implementing the SquareRoot function.
test.c: Contains test cases for the SquareRoot function.

Usage
Compile and Link:
gcc -o approx_sqrt main.c approx_sqrt.c test.c ^
 ../../utils/utils.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c 


Run: 
/.sqrt_babylonian  (On Windows: sqrt_babylonian )

