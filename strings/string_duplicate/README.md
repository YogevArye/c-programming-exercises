# String Duplication

## Overview
The `StringDuplicate` function creates a duplicate of a given null-terminated string.  
It handles various scenarios, including valid strings, `NULL` input, and memory allocation failures.

## Features
- **Duplicates a String:** Creates an exact copy of the input string, including the null-terminator.
- **Handles Invalid Inputs:** Returns `NULL` when provided with a `NULL` input.
- **Simulates Allocation Failure:** Includes a test case to validate behavior under a simulated allocation failure condition.

## Files
- **`main.c`:** Entry point for running `StringDuplicate` tests.
- **`duplication.c`:** Implementation of the `StringDuplicate` function.
- **`duplication.h`:** Declares the `StringDuplicate` function and related utilities.
- **`test.c`:** Test suite for the `StringDuplicate` function.
- **`test_alloc_fail.c`:** Tests `StringDuplicate` behavior under simulated memory allocation failure.
- **`Makefile`:** Automates the build process.

## Usage

### Build
```bash
make
```

### Run
```bash
./string_duplication  # For Linux/macOS
  string_duplication  # For Windows
```