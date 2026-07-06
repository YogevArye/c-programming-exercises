#include "duplication.h"

void RunAllocFailTest(void) {
    allocation_fail = 1;   
    char* actual = StringDuplicate("test");
    char* status = "Fail";

    printf("Test Case: Allocation Failure Simulation\n");
    printf("Expected: NULL\n"); 

    if (actual == NULL) {
        status = "Pass";
        printf("Actual: NULL\n");
    } else {
        printf("Actual: %s\n", actual);
    }
    
    printf("%s\n", status);
    allocation_fail = 0;  
}