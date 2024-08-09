// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Implement a linked list data structure to handle integer elements. The implementation will consist of three files:
// intlist.h - the header file
// intlist.c - the code.
// testintlist.c - the program that tests the implementation.
// -------------------------------------------------------------------
// The following functions have to be implemented:
// a)	Create – this will create a new linked list.
// b)	Delete – this will delete the list and all the linked elements.
// c)	Add – this will add an element to the end of the list.
// d)	Insert – this will insert an element at a particular index(zero based).For example, 
// if the linked list has 4 elements.Calling Insert with an index of 2 will insert the new element between
// that at index 1 and that at index 2.
// e)	RemoveAt – this will remove the element at a particular index(zero based).
// f)	Remove – removes the first occurrence of a specific element.
// g)	Count – number of elements in the list.
// h)	Get – gets the element at a particular index.
// ------------------------------------------------------------------------------------------------
// testintlist.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "intlist.h"

//Test program
int main() {
   LinkList list;

   //Create an empty linked list
   Create(&list);

   //Add elements to the end of the list
   Add(&list, 10);
   Add(&list, 20);
   Add(&list, 30);
   Add(&list, 40);
   Add(&list, 20);
   printf("List before adding elements:");
   PrintList(&list);

   //Insert element at specific indexes
   Insert(&list, 1, 15);
   Insert(&list, 3, 90);
   printf("List after inserting elements: ");
   PrintList(&list);

   //Remove an element at a specific index
   RemoveAt(&list, 1);
   printf("List after removing the element at index 1: ");
   PrintList(&list);

   //Remove the first occurrence of a specific element
   Remove(&list, 20);
   printf("List after removing the first occurrence of 20:");
   PrintList(&list);

   //Count the number of elements in the list
   printf("The Number of elements in the list: %d\n", Count(&list));

   //Get an element at a specific index
   printf("Element at index 1: %d\n", Get(&list, 1));

   //Delete the entire list
   DeleteList(&list);

   return 0;
}
