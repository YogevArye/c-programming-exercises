# String to Integer Conversion
## Overview

The `StringToInteger` function converts a string representing an integer into an actual integer value.  
It is designed to handle various input types and edge cases for reliable parsing in diverse applications.

## Features

- Converts a string of digits into an integer.
- Handles invalid inputs like `NULL` and non-numeric characters.
- Accounts for edge cases such as empty strings and leading/trailing whitespace.
- Manages overflow and underflow scenarios.

## Files
- **main.c**: Entry point for running `StringToInteger` tests.
- **string_to_integer.c**: The implementation of the `StringToInteger`.
- **string_to_integer.h**: Declares functions and a struct for `StringToInteger`  testing.
- **test.c**: Test suite for the `StringToInteger` function.
- **Makefile**: Automates the build process.

## Usage
 **Build:**   

   ```bash
   make
   ```
 **Run:**  

   ```bash
   ./string_to_integer  # For Linux/macOS
   string_to_integer    # For Windows
   ```
 



