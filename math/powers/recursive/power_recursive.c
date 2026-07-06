#include "power_recursive.h" 

float PowerRecursive(float base, int exp) {
    if (base == 0.0f) {
        return HandleZeroBase(base, exp);
    } else if (exp == 0) {
        return 1.0f;
    } else if (exp > 0) {
        return base * PowerRecursive(base, exp - 1);
    } else {
        return 1.0f / PowerRecursive(base, -exp);
    }
}
