# String Comparison

## Overview
The `StringCompare` function compares two strings lexicographically and returns an  
integer indicating their order. It is designed to handle various input types and edge  
cases for reliable string comparisons in different applications.

## Features
- Compares two strings lexicographically.  
- Returns `0` if the strings are identical, a negative value if the first string is less  
  than the second, and a positive value if the first string is greater.  
- Handles invalid inputs like `NULL` pointers.  
- Accounts for edge cases such as identical strings and varying character order.  

## Files
- **`main.c`**: Entry point for running `StringCompare` tests.  
- **`string_compare.c`**: The implementation of `StringCompare`.  
- **`string_compare.h`**: Declares functions and a struct for `StringCompare` testing.  
- **`test.c`**: Test suite for the `StringCompare` function.  
- **`Makefile`**: Automates the build process.  

## Usage

### Build:
```sh
make
```
### Run:
```sh
./string_compare  # For Linux/macOS  
string_compare    # For Windows  
```
