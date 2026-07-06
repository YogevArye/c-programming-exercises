# C Programming Exercises 

## Overview

This project includes exercises in areas like math calculations and string manipulations,  
organized by problem type. Utility functions are included to support these exercises.  
Each module is modular and includes test file and Makefile for easy building and testing.

## Get Started

To clone the repository, run the following command:
```bash
git clone git@github.com:YogevArye/Exercises.git
```

## Directory Structure

```
├── ds/
├── math/
│   ├── approx_sqrt/
│   ├── calculate_average/
│   ├── divide/
│   ├── fibonacci/
│   ├── greater_number/
│   ├── is_prime_number/
│   ├── is_right_triangle/
│   ├── powers/
│   ├── reverse_numbers/
│   └── triangle_type/
├── strings/
│   ├── string_compare_lexicographically/
│   ├── string_duplicate/
│   ├── string_length/
│   └── string_to_integer/
└── utils/
    ├── test_cases/
    ├── test_malloc/
    └── math/  
```

## Modules

### Data Structures

Placeholder for data structure-related exercises, to be expanded.

### Math

Exercises related to mathematical operations, covering topics like:
- **Square Root Approximation**: `ApproximateSqrt` calculates square root approximations.
- **Average Calculation:** `CalculateAverage` calculates the average of values in a given array.
- **Integer Division:** `Divide` performs division and modulus operations on two values.
- **Fibonacci**: `Fibonacci` efficiently calculates Fibonacci numbers.
- **Prime Number Check**: `IsPrimeNumber` checks if a number is prime.
- **Powers**: Implements power functions (`Power`, `PowerIterative`, `PowerRecursive`, `PowerOptimizedRecursive`).
- **Reverse Numbers**: `ReverseNumber` reverses the digits of a given number.
- **Triangle Type Check**: `TriangleType` identifies triangle types based on angle sizes. 
- **Right Triangle Check :** `IsRightTriangle` determines whether three side lengths form a right triangle.
- **Greater Number:** `Maximum` compares two numbers and returns the greater of the two.

### Strings

Exercises related to string manipulation, including:
- **String Comparison**: `StringCompare` compares two strings lexicographically.
- **String Duplication**: `StringDuplicate` duplicates a given string.
- **String Length**: `StringLength` calculates the length of a string.
- **String to Integer**: `StringToInteger` converts a numeric string to an integer.

### Utils

A set of utility functions and helper code used across exercises, including:
- **Test Case Management**: Functions for managing test cases for various exercises.
- **Memory Allocation Testing**: Includes utilities for testing memory allocation.
- **Math Utils**: Utility functions for mathematical operations.

## Testing

Each exercise includes test cases in test.c files to verify outputs and edge cases.  
Utility functions are used for test case management and error handling.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.