Prime Number Checker

Overview
This project provides a C implementation to determine if a number is a prime number.
It includes different versions of the prime-checking function and a test program to demonstrate its usage.

Features
- Efficient prime number checking using a simple and optimized algorithm.
- Multiple versions of the implementation for comparison.
- Test suite to verify functionality with sample numbers.

Files
main.c: Entry point for program execution.
is_prime_number.h: Header file with function prototypes.
v1.c: First version of the prime-checking function.
v2.c: Second version of the prime-checking function with a typedef.
test.c: Test program that contains a suite of test cases to validate the functionality of the prime-checking functions.

Usage
Compile and Link:
gcc -o prime_test main.c test.c is_prime_number.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c ^
 ../../utils/utils.c 
 
Run:
./test (On Windows: test)






