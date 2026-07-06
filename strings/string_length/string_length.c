#include "string_length.h"

size_t StringLength(const char* str) {
    if (str == NULL) {
        return INT_MIN;
    }

   const char* strlen;
   strlen = str;
   
   while (*strlen != '\0') {
       strlen ++;
   }

   return strlen - str;
}