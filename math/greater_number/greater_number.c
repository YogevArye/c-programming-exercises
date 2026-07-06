#include "greater_number.h"

int Maximum(int first_number, int second_number) {
   int result;
   
   result = (first_number > second_number) ? first_number : second_number;
   
   return  result;
}