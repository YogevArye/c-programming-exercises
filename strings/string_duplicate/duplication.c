#include "duplication.h"

char* StringDuplicate(const char* str) {
    char* copy = NULL;
     
    if (str == NULL) {
        return NULL;
    }
 
    copy =  malloc(strlen(str) + 1);
    
    if (copy == NULL) {
        return NULL;
    }
    
   return strcpy(copy, str);
}
 