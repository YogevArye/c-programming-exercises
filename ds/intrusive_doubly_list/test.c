#include <stdio.h>
#include <stdlib.h>
#include "intrusive_doubly_list.h"

/* A sample structure that contains a list node and some data */
typedef struct MyData
{
    list_node_type link;  
    int data;            
} my_data_type;

int IsEqual(const list_node_type* node, const void* data)
{
    const my_data_type* item = (const my_data_type*)node;
    return (item->data == *(const int*)data);
}

int main()
{
    list_type myList;
    ListConstruct(&myList);

    if (ListIsEmpty(&myList))
    {
        printf("The list is empty.\n");
    }

    my_data_type item1 = { .data = 10 };
    my_data_type item2 = { .data = 20 };
    my_data_type item3 = { .data = 30 };

    ListInsert(&myList.head, &item1.link);
    ListInsert(&myList.head, &item2.link);
    ListInsert(&myList.head, &item3.link);

    if (!ListIsEmpty(&myList))
    {
        printf("The list is no longer empty.\n");
    }

    int searchValue = 20;
    list_node_type* foundNode = ListFind(&myList, IsEqual, &searchValue);
    if (foundNode != NULL)
    {
        my_data_type* foundItem = (my_data_type*)foundNode;
        printf("Found item with data: %d\n", foundItem->data);
    }
    else
    {
        printf("Item with data %d not found.\n", searchValue);
    }

    ListRemove(&item2.link);
    printf("Removed item with data: 20\n");

    foundNode = ListFind(&myList, IsEqual, &searchValue);
    if (foundNode == NULL)
    {
        printf("Item with data %d successfully removed.\n", searchValue);
    }

    printf("Remaining items in the list: ");
    list_node_type* current = myList.head.next;
    while (current != &myList.head)
    {
        my_data_type* item = (my_data_type*)current;
        printf("%d ", item->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
