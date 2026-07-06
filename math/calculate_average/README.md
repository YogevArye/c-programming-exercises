Calculate Average

Overview
This project demonstrates a C program that calculates the rounded average of an array of integers. 
It showcases floating-point arithmetic and array manipulation to compute the average, rounding it to the nearest whole number.

Features
- Calculate the rounded average of an integer array.
- Handles various scenarios: multiple elements, single 
  element, all-zero array, mixed positive/negative values, and 
  an empty array.
- Includes comprehensive test cases.

Files
calculate_average.c: Implements the CalculateAverage function.
calculate_average.h: The header file.
test.c: Contains test cases for the CalculateAverage function.
main.c: Entry point for program execution.

Usage
Compile and Link:
gcc -o calculate_average test.c main.c calculate_average.c ^
 ../../utils/test_cases/print_test_case_details.c ^
 ../../utils/test_cases/update_test_case_status.c ^
 ../../utils/test_cases/print_test_case_num.c ^
 ../../utils/test_cases/run_and_validate_test.c ^
 ../../utils/test_cases/create_shared_test_case.c ^
 ../../utils/utils.c    

Run:
./calculate_average (On Windows: calculate_average)
