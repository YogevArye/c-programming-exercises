gcc -o test_loop main.c test_loop.c ^
../handle_zero_base.c ../test_power_utils.c ^
../native/power.c ^
../iterative/power_iterative.c ^
../optimized_recursive/power_optimized_recursive.c ^
../recursive/power_recursive.c ^
../../../utils/test_cases/print_test_case_details.c ^
../../../utils/test_cases/update_test_case_status.c ^
../../../utils/test_cases/print_test_case_num.c ^
../../../utils/test_cases/run_and_validate_test.c ^
../../../utils/test_cases/create_shared_test_case.c ^
../../../utils/utils.c 
