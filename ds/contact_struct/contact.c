#include "contact.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

contact_type* CreateContact(const char* name, unsigned tel_num)
{
    contact_type* contact;
    
    assert(name != NULL);
    contact = malloc(sizeof(contact_type));

    if (contact == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strncpy(contact->name, name, NAME_LEN);
    contact->name[NAME_LEN] = '\0';
    
    contact->tel_num = tel_num;    
    
    return contact;
}

void DestroyContact(contact_type* contact)
{
  free(contact);
}
