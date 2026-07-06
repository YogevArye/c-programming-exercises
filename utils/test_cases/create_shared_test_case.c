#include "test_cases.h"  

static void AssignTestValues(TestValue* asign_value, TestValue* input_value, ValueType type,
                             size_t index, size_t array_sizes) {
    if (array_sizes > 0) { 
        switch (type) {
            case TYPE_INT:
                asign_value[index].i_val = input_value[index].i_val;
                break;
            case TYPE_UNSIGNED_INT:
                asign_value[index].u_val = input_value[index].u_val;
                break;
            case TYPE_LONG:
                asign_value[index].l_val = input_value[index].l_val;
                break;
            case TYPE_UNSIGNED_LONG:
                asign_value[index].ul_val = input_value[index].ul_val;
                break;
            case TYPE_UNSIGNED_LONG_LONG:
                asign_value[index].ull_val = input_value[index].ull_val;
                break;
            case TYPE_FLOAT:
                asign_value[index].f_val = input_value[index].f_val;
                break;
            case TYPE_DOUBLE:
                asign_value[index].d_val = input_value[index].d_val;
                break;
            case TYPE_STRING:
                if (input_value[index].str_val != NULL) {
                    asign_value[index].str_val = malloc(strlen(input_value[index].str_val) + 1);
                    if (asign_value[index].str_val == NULL) {
                        fprintf(stderr, "Memory allocation failed for string in array\n");
                    } else {
                        strcpy(asign_value[index].str_val, input_value[index].str_val);
                    }
                } else {
                    asign_value[index].str_val = NULL; 
                }
                break;
            case TYPE_SIZE_T:
                asign_value[index].st_val = input_value[index].st_val;
                break;
            default:
                fprintf(stderr, "ERROR: Unexpected ValueType: %d\n", type);
                break;
        }
    } else {
        switch (type) {
            case TYPE_INT:
                asign_value->i_val = input_value->i_val;
                break;
            case TYPE_UNSIGNED_INT:
                asign_value->u_val = input_value->u_val;
                break;
            case TYPE_LONG:
                asign_value->l_val = input_value->l_val;
                break;
            case TYPE_UNSIGNED_LONG:
                asign_value->ul_val = input_value->ul_val;
                break;
            case TYPE_UNSIGNED_LONG_LONG:
                asign_value->ull_val = input_value->ull_val;
                break;
            case TYPE_FLOAT:
                asign_value->f_val = input_value->f_val;
                break;
            case TYPE_DOUBLE:
                asign_value->d_val = input_value->d_val;
                break;
            case TYPE_STRING:
                if (input_value->str_val != NULL) {
                    asign_value->str_val = malloc(strlen(input_value->str_val) + 1);
                    if (asign_value->str_val == NULL) {
                        fprintf(stderr, "Memory allocation failed for string\n");
                    } else {
                        strcpy(asign_value->str_val, input_value->str_val);
                    }
                } else {
                    asign_value->str_val = NULL; 
                }
                break;
            case TYPE_SIZE_T:
                asign_value->st_val = input_value->st_val;
                break;
            default:
                fprintf(stderr, "ERROR: Unexpected ValueType: %d\n", type);
                break;
        }
    }
}
static void AssertValidInput(const TestValue expected, const TestValue actual,
                             const TestValue* expected_array, const TestValue* actual_array,
                             size_t array_sizes) {

    if (array_sizes > 0) {
        assert(expected_array != NULL);
        assert(actual_array != NULL);
        assert(expected.i_val == 0 && actual.i_val == 0);

    } else {
        assert(expected_array == NULL);
        assert(actual_array == NULL);
    }
}

static shared_tc CreateSharedTC(TestValue expected, TestValue actual,
                                       TestValue* expected_array, 
                                       TestValue* actual_array, 
                                       size_t array_sizes, int test_case_num,
                                       ValueType type, TestFunction test_func) {
    AssertValidInput(expected, actual, expected_array, actual_array, array_sizes);

    size_t i;

    shared_tc s_tc = {0}; 

    if (array_sizes > 0) {
        s_tc.expected_array = malloc(array_sizes * sizeof(TestValue));
        s_tc.actual_array = malloc(array_sizes * sizeof(TestValue));

        for (i = 0; i < array_sizes; ++i) {
            AssignTestValues(s_tc.expected_array, expected_array, type, i, array_sizes);
            AssignTestValues(s_tc.actual_array, actual_array, type, i, array_sizes); 
        }
        } else {
        AssignTestValues(&s_tc.expected, &expected, type, 0, array_sizes);
        AssignTestValues(&s_tc.actual, &actual, type, 0, array_sizes);
    }

    s_tc.ea_arrays_size = array_sizes;
    s_tc.test_case_num = test_case_num;
    s_tc.status = "Fail";
    s_tc.type = type;
    s_tc.test_func = test_func;

    return s_tc;
}

shared_tc CreateSharedTCValuesCase(TestValue expected, TestValue actual, 
                                         int test_case_num, ValueType type,
                                         TestFunction test_func) {
    return CreateSharedTC(expected, actual, NULL, NULL, 0, test_case_num, type, test_func);
}

shared_tc CreateSharedTCArraysCase(TestValue* expected_array, TestValue* actual_array, 
                                          size_t array_sizes, int test_case_num, 
                                          ValueType type, TestFunction test_func) {
    TestValue empty_value = { .i_val = 0 };

    return CreateSharedTC(empty_value, empty_value, expected_array,
                          actual_array, array_sizes, test_case_num,
                          type, test_func);
}

