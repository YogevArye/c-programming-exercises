Greater Number Project

Overview
This project is a simple C program that determines the greater of two integers. 
It includes a function to perform the comparison and a series of tests to verify its correctness.

Features
- Function to find the maximum of two integers.
- Structured test cases with expected and actual outputs.
- Automatic status verification (Pass/Fail) for each test 
  case.

Files
main.c: Entry point for program execution.
greater_number.c: Contains the Maximum function, which returns the greater of two numbers.
greater_number.h: Header file with function declarations.
test.c: Contains test cases that validate the Maximum function.

Usage
Compile and Link:
gcc -o greater_number test.c main.c greater_number.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c ^
 ../../utils/utils.c 

Run:
To run the program:
./greater_number (On Windows: greater_number)
