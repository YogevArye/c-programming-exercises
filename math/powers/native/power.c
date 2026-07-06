#include "power.h" 

float Power(float base, int exp) {
    float result = 1.0f;
    size_t i;
    
    if (base == 0.0f) {
        return HandleZeroBase(base, exp);
    } else if (exp == 0) {
        return 1.0f;
    } else if (exp < 0) {
        for (i = 0; i < -exp; ++i) {
            result *= base;
        }
        return 1 / result; 
    }

    for (i = 0; i < exp; ++i) {
        result *= base;
    }

    return result;
} 