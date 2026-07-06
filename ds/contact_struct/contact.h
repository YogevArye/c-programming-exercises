#ifndef CONTACT_H
#define CONTACT_H
#define NAME_LEN 30

#include "utils.h"

typedef struct Contact
{
    char name[NAME_LEN+1];
    unsigned tel_num;
} contact_type;

contact_type* CreateContact(const char* name, unsigned tel_num);
void DestroyContact(contact_type* contact);
void RunTests();

#endif 
