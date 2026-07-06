#ifndef UTILS_H
#define UTILS_H
#define EPSILON 1e-4 /* Epsilon value of 1 × 10^-4 = 0.0001 */

#include <stdio.h>
#include <stddef.h>  /*For size_t and NULL*/
#include <math.h>
#include <limits.h> 
#include <assert.h> 
#include <string.h>  /*For the strcpy and strlen functions.*/
#include <stdlib.h>  /* For: malloc and free functions, NULL */
#include <stdbool.h> 
#include "test_cases/test_cases.h"

extern const char* expected_label;
extern const char* actual_label;

#endif 