#include "string_compare.h"

int StringCompare(const char* str1, const char* str2) {
   if (str1 == NULL || str2 == NULL) {
       return INT_MIN;
   }

   while (*str1 == *str2 && *str1 != '\0') {
       ++ str1; 
       ++ str2;
   }

   return *str1 - *str2;
}