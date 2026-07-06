Move Elements 

Overview
This project demonstrates a solution for shifting the elements of an integer array to the left by a given count. 
It includes two versions of the implementation: 
an initial version (v1) and an improved version (v2). 

Features
- Shifts elements of an integer array to the left by a specified number of positions.
- The improvement in v2 optimizes the shift operation by using the modulus operator (count %= size;), reducing unnecessary shifts when the count exceeds the array size.
- Comprehensive test cases to ensure the correctness of both implementations, including cases where the shift count exceeds the array size.

Files
main.c: Contains the main function and runs the test cases.
test.c: Implements the RunTestCases function and tests various shift scenarios.
move_elements.h: Header file with function prototypes.
v1.c: The initial implementation of the MoveElements function.
v2.c: The improved implementation of the MoveElements function.

Usage
Compile and Link:
gcc -o array_shift main.c test.c v2.c
Run:
./array_shift (On Windows: array_shift)

Note: For testing version 1, replace v2.c with v1.










