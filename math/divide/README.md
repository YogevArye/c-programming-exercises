Integer Division Program

Overview
This project implements an integer division function with error handling for edge cases, such as division by zero and overflow conditions. 
It includes a set of test cases to verify the correctness of the division operation.

Features
Division by Zero Handling: Safely handles division by zero, returning a specific error code.
Overflow Detection: Detects and handles overflow cases (e.g., dividing INT_MIN by -1).
Support for Edge Cases: Covers extreme values, including the maximum and minimum integer values.
Detailed Test Results: Provides clear pass/fail status for each test case, with detailed output indicating the expected vs. actual results.
Modular Code: Organized into separate files for easy maintenance and testing.

Files
main.c: Entry point for program execution.
valid_quotient_remainder.h: Header file with function declarations.
valid_quotient_remainder.c: Implementation of the division function.
test.c: Contains test cases for the Divide function.

Usage
Compile and Link: 
gcc -o divide divide.c test.c main.c ^
 ../../utils/utils.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c 


Run:
 /.test_q_r (On Windows: test_q_r) 
