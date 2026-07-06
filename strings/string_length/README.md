# String Length Calculation

## Overview

The `StringLength` function calculates the length of a null-terminated string.  
It handles various string inputs and edge cases to ensure reliable results.

## Features

- Converts a string into its length, excluding the null-terminated ('\0') character.
- Handles invalid inputs, such as `NULL` strings.
- Accounts for special cases like empty strings and whitespace-only strings.

## Files

- **main.c**: Entry point for running `StringLength` tests.
- **string_length.c**: Implementation of the `StringLength` function.
- **string_length.h**: Declares functions and a struct for `StringLength` testing.
- **test.c**: Test suite for the `StringLength` function.
- **Makefile**: Automates the build process. 

## Usage

**Build**:

   ```bash
   make
   ```
**Run**:

   ```bash
   ./string_length  # For Linux/macOS
   string_length    # For Windows
   ```