#include "test_cases.h"  
#include "../math/float_comparisons.h"

void UpdateTestCaseStatus(shared_tc* s_tc) {
    assert(s_tc != NULL);

    size_t i;
    bool all_equal = true;

    if (s_tc->ea_arrays_size > 0) {

        for (i = 0; i < s_tc->ea_arrays_size; ++i) {
            switch (s_tc->type) {
                case TYPE_INT:
                    if (s_tc->actual_array[i].i_val != s_tc->expected_array[i].i_val) {
                        all_equal = false;
                    }
                    break;
                case TYPE_UNSIGNED_INT:
                    if (s_tc->actual_array[i].u_val != s_tc->expected_array[i].u_val) {
                        all_equal = false;
                    }
                    break;
                case TYPE_LONG:
                    if (s_tc->actual_array[i].l_val != s_tc->expected_array[i].l_val) {
                        all_equal = false;
                    }
                    break;
                case TYPE_UNSIGNED_LONG:
                    if (s_tc->actual_array[i].ul_val != s_tc->expected_array[i].ul_val) {
                        all_equal = false;
                    }
                    break;
                case TYPE_UNSIGNED_LONG_LONG:
                    if (s_tc->actual_array[i].ull_val != s_tc->expected_array[i].ull_val) {
                        all_equal = false;
                    }
                    break;
                case TYPE_FLOAT:
                    if (!IsEqualFloat(s_tc->actual_array[i].f_val, s_tc->expected_array[i].f_val)) {
                        all_equal = false;
                    }
                    break;
                case TYPE_DOUBLE:
                    if (!IsEqualDouble(s_tc->actual_array[i].d_val, s_tc->expected_array[i].d_val)) {
                        all_equal = false;
                    }
                    break;
                case TYPE_STRING:
                    if (s_tc->actual_array[i].str_val != NULL && s_tc->expected_array[i].str_val != NULL) {
                        if (strcmp(s_tc->actual_array[i].str_val, s_tc->expected_array[i].str_val) != 0) {
                            all_equal = false;
                      }
                    } else if (s_tc->actual_array[i].str_val != s_tc->expected_array[i].str_val) {
                            all_equal = false;
                    }
                    break;
                case TYPE_SIZE_T:
                    if (s_tc->actual_array[i].st_val != s_tc->expected_array[i].st_val) {
                        all_equal = false;
                    }
                    break;
                default:
                    s_tc->status = "Unknown Type"; 
                    return;
            }
        }

        s_tc->status = all_equal ? "Pass" : "Fail";

    } else {

        switch (s_tc->type) {
            case TYPE_INT:
                s_tc->status = (s_tc->actual.i_val == s_tc->expected.i_val) ? "Pass" : "Fail";
                break;
            case TYPE_UNSIGNED_INT:
                s_tc->status = (s_tc->actual.u_val == s_tc->expected.u_val) ? "Pass" : "Fail";
                break;
            case TYPE_LONG:
                s_tc->status = (s_tc->actual.l_val == s_tc->expected.l_val) ? "Pass" : "Fail";
                break;
            case TYPE_UNSIGNED_LONG:
                s_tc->status = (s_tc->actual.ul_val == s_tc->expected.ul_val) ? "Pass" : "Fail";
                break;
            case TYPE_UNSIGNED_LONG_LONG:
                s_tc->status = (s_tc->actual.ull_val == s_tc->expected.ull_val) ? "Pass" : "Fail";
                break;
            case TYPE_FLOAT:
                s_tc->status = IsEqualFloat(s_tc->actual.f_val, s_tc->expected.f_val) ? "Pass" : "Fail";
                break;
            case TYPE_DOUBLE:
                s_tc->status = IsEqualDouble(s_tc->actual.d_val, s_tc->expected.d_val) ? "Pass" : "Fail";
                break;
            case TYPE_STRING:
                if (s_tc->actual.str_val != NULL && s_tc->expected.str_val != NULL) {
                    s_tc->status = (strcmp(s_tc->actual.str_val, s_tc->expected.str_val) == 0) ?
                    "Pass" : "Fail";
                } else if (s_tc->actual.str_val == NULL && s_tc->expected.str_val == NULL) {
                           s_tc->status = "Pass"; 
                }
                break;
            case TYPE_SIZE_T:
                s_tc->status = (s_tc->actual.st_val == s_tc->expected.st_val) ? "Pass" : "Fail";
                break;
            default:
                s_tc->status = "Unknown Type"; 
                break;
        }
    }
}