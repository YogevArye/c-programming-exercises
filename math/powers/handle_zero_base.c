#include "powers.h"

float HandleZeroBase(float base, int exp) {
    /* Safeguard: Ensures base is zero, though only 0.0f is expected */
    if (base != 0.0f) {
        return NAN;  
    } else {
        if (exp == 0) {
            return 1.0f;
        } else if (exp > 0) {
            return 0.0f; 
        } else {
            return INFINITY;  
        }
   }
}