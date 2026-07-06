#include "test_loop.h" 

void TestLoop(void) {
    size_t num_power_funcs;
    size_t i;
    
    PowerFunction power_funcs[] = {
        PowerIterative,
        PowerRecursive,
        PowerOptimizedRecursive,
        Power  
    };

    num_power_funcs = sizeof(power_funcs) / sizeof(power_funcs[0]);

    const char *names[] = {
        "PowerIterative",
        "PowerRecursive",
        "PowerOptimizedRecursive",
        "Power" 
    };

    for (i = 0; i < num_power_funcs; i++) {
      TestPowerUtils(power_funcs[i], names[i]);
    }
}