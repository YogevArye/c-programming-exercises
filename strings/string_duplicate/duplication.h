#ifndef DUPLICATION_H
#define DUPLICATION_H

#include "../../utils/utils.h"
#include "../../utils/test_malloc/test_malloc.h"

/**
 * @brief Creates a duplicate of the given string.
 *
 * @param str The string to duplicate (may be NULL).
 * @return A duplicate of the given string, or NULL if the input is NULL 
 *         or allocation fails.
 */
char* StringDuplicate(const char* str);

/**
 * @brief Runs a set of StringDuplicate function test cases.
 */
void RunTests(void);

/**
 * @brief Runs a test case of allocation failure simulation for the StringDuplicate function.
 */       
void RunAllocFailTest(void); 

#endif 
