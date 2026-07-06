void PrintTestResult(int test_case_number, int expected, int actual)
{
    printf("Test Case %d:\n", test_case_number);
    printf("Expected: %d, Actual: %d, ", expected, actual);
    
    if (EXPECT_EQ(expected, actual))
    {
        printf("Pass\n");
    }
    else
    {
        printf("Fail\n");
    }
}