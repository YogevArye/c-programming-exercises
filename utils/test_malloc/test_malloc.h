#ifndef TEST_MALLOC_H
#define TEST_MALLOC_H

/* Override malloc for testing */
#define malloc(size) test_malloc(size)

#include "../utils.h"

extern int allocation_fail;

void* test_malloc(size_t size);

#endif 