#include <stdio.h>
#include "intrusive_doubly_list.h"

void ListConstruct(list_type* list)
{
    list->head.next = &list->head;
    list->head.prev = &list->head;
}

void ListInsert(list_node_type* position, list_node_type* node)
{
    node->next = position->next;
    node->prev = position;

    if (position->next != NULL)
    {
        position->next->prev = node;
    }
    position->next = node;

}

list_node_type* ListFind(const list_type* list, list_isequal_type isequal, const void* data)
{
    list_node_type* current = list->head.next;
    while (current != &list->head)
    {
        if (isequal(current, data))
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void ListRemove(list_node_type* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
}

int ListIsEmpty(const list_type* list)
{
    return (list->head.next == &list->head && list->head.prev == &list->head);
}
