 #include "power_optimized_recursive.h" 

float PowerOptimizedRecursive(float base, int exp) {
    float half;
    
    if (base == 0.0f) {
        return HandleZeroBase(base, exp);
    } else if (exp == 0) {
        return 1.0f;
    } else if (exp < 0) {
        base = 1.0f / base;
        exp = -exp;
    }
    
    half = PowerOptimizedRecursive(base, exp / 2);
    
    if (exp % 2 == 0) {
        return half * half;
    } else {
        return half * half * base;
    }
}
