#ifndef INTRUSIVE_DOUBLY_LIST
#define INTRUSIVE_DOUBLY_LIST

#include "utils.h"

/* single node */
typedef struct ListNode list_node_type;

struct ListNode
{
	list_node_type* next;
	list_node_type* prev;
};

/* List control struct */
typedef struct List
{
    /* A standalone (dummy) node; doesn't have data */
    list_node_type head;
} list_type;

/* Match function signature. Used in ListFind API. */
typedef int(*list_isequal_type)(const list_node_type*,const void*);

void ListConstruct(list_type* list);

void ListInsert(list_node_type* position, list_node_type* node);

void ListRemove(list_node_type* node);

/* Return 1 (true) or 0 (false), if the list is empty or not, respectively. */
int ListIsEmpty(const list_type* list);

/* Find and return a node which has data that matches the given data parameter.
 * The match is determined by calling the 'isequal' function. */
list_node_type* ListFind(const list_type* list, list_isequal_type isequal, const void* data);

#endif 
