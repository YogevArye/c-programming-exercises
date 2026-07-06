#ifndef FLOAT_COMPARISONS_H
#define FLOAT_COMPARISONS_H

#include "../utils.h"

static inline int IsEqualFloat(float a, float b) {
    if (isnan(a) && isnan(b)) {
        return 1; /* Consider NaN equal to NaN */
    } else if (isinf(a) && isinf(b)) {
        return 1; /* Consider INFINITY equal to INFINITY */
    } else if (isinf(a) || isinf(b)) {
        return 0; /* INFINITY is not equal to any finite value */
    } else {
        return fabs(a - b) <= EPSILON;
    }
}

static inline int IsEqualDouble(double a, double b) {
     if (isnan(a) && isnan(b)) {
        return 1;
    } else if (isinf(a) && isinf(b) && a == b) {
        return 1;
    } else if (isinf(a) || isinf(b)) {
        return 0;
    } else {
       return fabs(a - b) <= EPSILON;
    }
}

#endif 


