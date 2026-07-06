#include "fibonacci.h"

unsigned long long Fibonacci(size_t index) {
    unsigned long long prev_fib_1 = 0;
    unsigned long long prev_fib_2 = 1;
    size_t i;

    if (index == 0) return 0;
    if (index == 1) return 1;
  
    for (i = 2; i <= index; ++i) {
        prev_fib_2 += prev_fib_1; 
        prev_fib_1 = prev_fib_2 - prev_fib_1;
    }
    
    return prev_fib_2;
}
