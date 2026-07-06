#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "../utils.h"

/* Common structure for shared test cases */
typedef struct SharedTestCase shared_tc;
typedef void (*TestFunction)(shared_tc* s_tc);  /* Generic function pointer for test cases */

typedef union {    
    int i_val;
    unsigned int u_val;
    long l_val;
    unsigned long ul_val;
    unsigned long long ull_val;
    float f_val;
    double d_val;
    char* str_val;
    size_t st_val;  
} TestValue;      

typedef enum {
    TYPE_INT,
    TYPE_UNSIGNED_INT,
    TYPE_LONG,
    TYPE_UNSIGNED_LONG,
    TYPE_UNSIGNED_LONG_LONG,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING,
    TYPE_SIZE_T  
} ValueType;           

struct SharedTestCase {
    TestValue expected;
    TestValue actual;
    TestValue* expected_array;
    TestValue* actual_array;
    size_t ea_arrays_size;
    int test_case_num;
    const char *status;            /* Test status, e.g., "Pass" or "Fail" */
    ValueType type;          
    TestFunction test_func;        /* Generic function pointer for calling the function */
};                           

void PrintTCNum(const shared_tc* s_tc);
void RunAndValidateTest(shared_tc* s_tc);
void UpdateTestCaseStatus(shared_tc* s_tc);
void PrintSharedTC(const shared_tc* s_tc, const char** expected_labels, 
                   const char** actual_labels);
shared_tc CreateSharedTCValuesCase(TestValue expected, TestValue actual, 
                                         int test_case_num, ValueType type,
                                         TestFunction test_func);
shared_tc CreateSharedTCArraysCase(TestValue* expected_array, TestValue* actual_array, 
                                          size_t array_sizes, int test_case_num, 
                                          ValueType type, TestFunction test_func);
                                                                                    

#endif 
