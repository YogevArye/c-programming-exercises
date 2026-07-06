#include <inttypes.h>
#include "test_cases.h"  

static void PrintTestValueWithLabel(const char* label, const TestValue* value, ValueType type) {
    printf("%s: ", label);
    switch (type) {
        case TYPE_INT:
            printf("%d\n", value->i_val);  
            break;
        case TYPE_UNSIGNED_INT:
            printf("%u\n", value->u_val);  
            break;
        case TYPE_LONG:
            printf("%ld\n", value->l_val);  
            break;
        case TYPE_UNSIGNED_LONG:
            printf("%lu\n", value->ul_val);  
            break;
        case TYPE_UNSIGNED_LONG_LONG:
           printf("%" PRIu64 "\n", (uint64_t)value->ull_val);  
            break;
        case TYPE_FLOAT:
            printf("%f\n", value->f_val);  
            break;
        case TYPE_DOUBLE:
            printf("%lf\n", value->d_val);  
            break;
        case TYPE_STRING:
            printf("%s\n", value->str_val ? value->str_val : "NULL");  
            break;
        case TYPE_SIZE_T:
            printf("%" PRIuMAX "\n", (uintmax_t)value->st_val);
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}
static void AssertValidInput(const shared_tc* s_tc, const char** expected_labels, 
                                const char** actual_labels) {
    assert(s_tc != NULL);
    assert(expected_labels != NULL);
    assert(actual_labels != NULL);

    if (s_tc->ea_arrays_size > 0) {
        assert(s_tc->expected_array != NULL);
        assert(s_tc->actual_array != NULL);  
    }
}

void PrintSharedTC(const shared_tc* s_tc, const char** expected_labels, 
                   const char** actual_labels) {
    AssertValidInput(s_tc, expected_labels, actual_labels);

    size_t i;

    if (s_tc->ea_arrays_size > 0) {
        
        for (i = 0; i < s_tc->ea_arrays_size; ++i) {
            PrintTestValueWithLabel(expected_labels[i], &s_tc->expected_array[i], s_tc->type);
            PrintTestValueWithLabel(actual_labels[i], &s_tc->actual_array[i], s_tc->type);
        }    
    } else {
           PrintTestValueWithLabel(expected_labels[0], &s_tc->expected, s_tc->type);
           PrintTestValueWithLabel(actual_labels[0], &s_tc->actual, s_tc->type);   
    }
        printf("Status: %s\n\n", s_tc->status);
}