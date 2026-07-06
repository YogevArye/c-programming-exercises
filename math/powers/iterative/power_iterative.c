#include "power_iterative.h" 

float PowerIterative(float base, int exp) {
    float result = 1.0f;

    if (base == 0.0f) {
        return HandleZeroBase(base, exp);
    } else if (exp == 0) {
        return 1.0f;
    } else if (exp < 0) {
        base = 1.0f / base;
        exp = -exp;
    }
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }
    
    return result;
}
