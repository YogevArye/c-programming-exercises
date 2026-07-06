Contact Management System

Overview
This project demonstrates a simple contact management system implemented in C. 
It allows for the creation and destruction of contacts, 
with built-in test cases to verify the correctness of the functions. 
The system uses dynamic memory allocation and provides test cases for validation.

Features
- Create and destroy contacts
- Store name and telephone number
- Dynamic memory management
- Unit testing using predefined test cases

Files
contact.h - Header file with contact structure and function declarations.
contact.c - Implementation of contact creation and destruction functions.
test.c - Contains unit tests for validating the contact management functions.

Usage
Compile and Link:
gcc -o contact_test contact.c test.c main.c
Run:
./contact_test (On Windows:contact_test)
