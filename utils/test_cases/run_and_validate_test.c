#include "test_cases.h"  

 void RunAndValidateTest(shared_tc* s_tc) {
    assert(s_tc != NULL);

    if (s_tc->test_func) {
        s_tc->test_func(s_tc);  
        UpdateTestCaseStatus(s_tc);  
    } else {
        printf("No test function provided for test case %d\n", s_tc->test_case_num);
    }
}