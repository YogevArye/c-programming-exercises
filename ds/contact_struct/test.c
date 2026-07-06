#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "contact.h"

typedef struct 
{
    char* name_input;
    unsigned tel_num_input;
    char* expected_name;
    unsigned expected_tel_num;
    char actual_name[NAME_LEN+1];
    unsigned actual_tel_num;
    unsigned test_case_num;
    char* status;
} TestCase;

void RunTests()
{   
    TestCase test_cases[] = 
    {
        {"Yogev", 123456789, "Yogev", 123456789, "", 0, 1, "Fail"},
        {"Yaron", 987654321, "Yaron", 987654321, "", 0, 2, "Fail"},
        {"Ido", 555666777, "Ido", 555666777, "", 0, 3, "Fail"},
        {"Shay", 111222333, "Shay", 111222333, "", 0, 4, "Fail"}
    };

    size_t i, num_test_cases;
    contact_type* contact;

    num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (i = 0; i < num_test_cases; ++i)
    {
        contact = CreateContact(test_cases[i].name_input, test_cases[i].tel_num_input);

        if (contact != NULL)
        {
            strncpy(test_cases[i].actual_name, contact->name, NAME_LEN);
            test_cases[i].actual_tel_num = contact->tel_num;

            if (strcmp(test_cases[i].actual_name, test_cases[i].expected_name) == 0 && 
                test_cases[i].actual_tel_num == test_cases[i].expected_tel_num)
            {
                test_cases[i].status = "Pass";
            }
        }

        printf("Test Case %d:\n", test_cases[i].test_case_num);
        printf("CreateContact:\n");
        printf("Input Name: %s, Input Tel: %u\n", test_cases[i].name_input, test_cases[i].tel_num_input);
        printf("Expected Name: %s, Expected Tel: %u\n", test_cases[i].expected_name, 
              test_cases[i].expected_tel_num);
        printf("Actual Name: %s, Actual Tel: %u\n", test_cases[i].actual_name, test_cases[i].actual_tel_num);
        printf("Status: %s\n\n", test_cases[i].status);
        
        DestroyContact(contact);
        contact = NULL;/*Set pointer to NULL after DestroyContact() to avoid using freed memory*/
    }
}
