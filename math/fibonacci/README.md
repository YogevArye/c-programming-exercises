Fibonacci Sequence Program

Overview
This project implements a Fibonacci sequence calculator in C, along with a test suite to verify its correctness. 
The program uses iterative logic to compute the nth Fibonacci number and includes a set of test cases to validate the results.

Features
- Calculate Fibonacci numbers for a given index.
- Test suite to validate the correctness of the Fibonacci 
  function.
- Modular code structure with separate files for logic and 
  tests.

Files
fibonacci.h - Header file containing the function declaration.
v1.c and v2.c - Source files with two different Fibonacci implementations.
main.c: Entry point for program execution.
test.c - Test suite to validate the Fibonacci function.

Usage
Compile and Link:
gcc -o fibunacci main.c fibonacci.c test.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c ^
 ../../utils/utils.c 

Run:
./fibonacci (On Windows: fibonacci)

Note: For testing version 1, replace v2.c with v1.
 