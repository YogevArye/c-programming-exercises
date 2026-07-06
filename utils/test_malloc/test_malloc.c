#include <stdlib.h>
#include "test_malloc.h"

int allocation_fail = 0;

void* test_malloc(size_t size) {
    if (allocation_fail) {
        return NULL;  
    }
    
    #undef malloc  
    void* result = malloc(size);    

    return result;
}