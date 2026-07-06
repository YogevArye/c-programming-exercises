#include "reverse_number.h"

unsigned ReverseNumber(unsigned number) {
    unsigned ones_digit, tens_digit, hundreds_digit, result;

     ones_digit = number % 10;
     number /= 10;
     tens_digit = number % 10;
     hundreds_digit = number / 10;
    
    result = ones_digit * 100 + tens_digit * 10 + hundreds_digit;

    return result;
}
