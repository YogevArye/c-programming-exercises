Intrusive Doubly Linked List Implementation

Overview
This project demonstrates an intrusive doubly linked list implementation in C.
An intrusive linked list is a type of data structure where the nodes of the list are embedded within user-defined data structures. 
This implementation includes functions for list construction, insertion, removal, and search.

Files
The project consists of the following files:
test.c: Demonstrates the usage of the intrusive doubly linked list with sample data.
intrusive_doubly_list.h: Header file containing definitions for the list node, list control structure, and function prototypes.
intrusive_doubly_list.c: Implementation file providing the definitions for the list operations.

Features
List Construction: Initialize a new list with a dummy head node.
Insertion: Insert nodes into the list at specified positions.
Removal: Remove nodes from the list.
Search: Find nodes in the list based on a custom equality function.

Usage
1. compiling the code:
gcc -o list_test test.c intrusive_doubly_list.c
2. run the executable:
  ./list_test (On Windows: list_test)

Example Output
The program demonstrates basic list operations:
- Initialization of an empty list.
- Insertion of data nodes.
- Searching for a specific data node.
- Removing a node.
- Displaying remaining items in the list.


