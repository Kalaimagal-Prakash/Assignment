// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Program on Testing Linked List Functions.
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
