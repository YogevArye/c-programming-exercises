#include <string.h> /*for memcmp*/
#include "move_elements.h"

typedef struct TestCase
{
    int input_array[5]; 
    int expected_array[5];
    size_t size;
    size_t shift_count;
    int test_case_num;
} TestCase;

int CompareArrays(int arr1[], int arr2[], size_t size)
{
    return memcmp(arr1, arr2, size * sizeof(int)) == 0;
}

void RunTestCases()
{
    TestCase test_cases[] =
    {
        {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 1}, 5, 1, 1},
        {{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 5, 2, 2},
        {{1, 2, 3, 4, 5}, {5, 1, 2, 3, 4}, 5, 4, 3},
        {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 1}, 5, 6, 4}
    };

    size_t num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    int actual_array[5]; 
    size_t i, j;

    for (i = 0; i < num_test_cases; ++i)
    {
        memcpy(actual_array, test_cases[i].input_array, test_cases[i].size * sizeof(int));

        MoveElements(actual_array, test_cases[i].size, test_cases[i].shift_count);

        printf("Test Case %d:\n", test_cases[i].test_case_num);

        printf("Expected: ");
        for (j = 0; j < test_cases[i].size; ++j) 
        {
            printf("%d ", test_cases[i].expected_array[j]);
        }
        printf("\n");

        printf("Actual:   ");
        for (j = 0; j < test_cases[i].size; ++j) 
        {
            printf("%d ", actual_array[j]);
        }
        printf("\n");

        if (CompareArrays(actual_array, test_cases[i].expected_array, test_cases[i].size))
        {printf("Result: Pass\n");}
        else {printf("Result: Fail\n");}
        printf("\n");
    }
}
