Reverse Number Program

Overview
This project contains a function that reverses a three-digit number.
It includes two versions of the implementation (v1.c and v2.c), and a test file to validate the function.

Features
- Reverses any three-digit number.
- Simple to compile and test.

Files
main.c: Entry point for program execution.
reverse_number.h: Contains the functions prototypes.
v1.c: First version of the ReverseNumber function implementation.
v2.c: Second version of the ReverseNumber function with slightly different logic.
test.c: Test file to validate the ReverseNumber function. 

Usage
Compile and Link:
gcc -o reverse_number reverse_number.c test.c main.c ^
 ../../utils/utils.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c 

Run: 
./reverse_number_program (On Windows: reverse_number_program)

