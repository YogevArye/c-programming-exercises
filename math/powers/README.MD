Power Functions

Overview
This project contains various implementations of power functions, including iterative, recursive, optimized recursive, and standard versions. 
It includes a test suite to evaluate each implementation.

Features
Iterative Power Function: Computes power using an iterative approach.
Recursive Power Function: Computes power using a simple recursive approach.
Optimized Recursive Power Function: Computes power using an optimized recursive approach with divide-and-conquer.
Standard Power Function: Computes power using a basic loop approach.
Automated Testing: Runs a set of predefined tests for all implementations.
Manual Testing: Allows for custom, manual testing of specific cases.

Files
main.c: Entry point for program execution.
iterative_power.c: Contains the implementation of the iterative power function.
recursive_power.c: Contains the implementation of the basic recursive power function.
optimized_recursive_power.c: Contains the implementation of the optimized recursive power function.
standard_power.c: Contains the implementation of the standard power function.
test_loop.c: Contains the automated test suite.
test_manually.c: Contains the manual test suite.
power_test_utils.c: Contains utility function for testing.
Makefile: A build script that simplifies the compilation process. 
                It is designed to work on both Windows and Linux environments, but minor adjustments may be needed for platform-specific commands (e.g., clean targets).

Note: A new data structure is defined in power_test_utils.c to handle additional variables not covered by the existing structure
in utils.h. 
This eliminates the need for complex type conversions and enhances clarity and safety when managing the test cases.

Usage
Automated Tests
Compile and Link:
For using the Makefile, use the following command: make manual_tests

For without using the Makefile, use the following command:
gcc -D RUN_AUTOMATED_TESTS -o automate_test test_loop.c standard_power.c recursive_power.c optimized_recursive_power.c main.c iterative_power.c ^
 power_test_utils.c ../../utils/utils.c ../../utils/test_cases/print_test_case_details.c ../../utils/test_cases/update_test_case_status.c ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ../../utils/test_cases/create_shared_test_case.c ../../utils/math/math.c   

This command includes the RUN_AUTOMATED_TESTS macro, which triggers the automated tests when running the automate_test executable.

Run:
./automate_test

Manual Tests
Compile and Link:
For using the Makefile, use the following command: 
make automate_test

For without using the Makefile, use the following command:
gcc -o manual_tests main.c iterative_power.c recursive_power.c optimized_recursive_power.c standard_power.c test_manually.c power_test_utils.c ^
../../utils/utils.c ../../utils/test_cases/print_test_case_details.c ../../utils/test_cases/update_test_case_status.c ../../utils/test_cases/print_test_case_num.c ^
../../utils/test_cases/run_and_validate_test.c ../../utils/test_cases/create_shared_test_case.c ../../utils/math/math.c


This command does not define the RUN_AUTOMATED_TESTS macro, so the RunTestsManually() function will be executed when running the manual_tests executable.
 
Note: Before compiling for manual testing, you have to uncomment the desired function you wish to test in test_manually.c. 
For example, to test the optimized recursive power function, update the test_manually.c file as follows:

/* #define TEST_ITERATIVE */
/* #define TEST_RECURSIVE */
#define TEST_OPTIMIZED_RECURSIVE
/* #define TEST_STANDARD */

Run:
/.manual_tests


gcc -o test_loop test_loop.c test_power_utils.c ^
standard_power/standard_power.c iterative_power/iterative_power.c ^
optimized_recursive_power/optimized_recursive_power.c recursive_power/recursive_power.c ^
../../utils/test_cases/print_test_case_details.c ^
../../utils/test_cases/update_test_case_status.c ^
../../utils/test_cases/print_test_case_num.c ^
../../utils/test_cases/run_and_validate_test.c ^
../../utils/test_cases/create_shared_test_case.c ^
../../utils/utils.c ../../utils/math/math.c

