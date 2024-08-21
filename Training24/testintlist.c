// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Program on A2 branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "intlist.h"

//Print all element of the list
void PrintList (const LinkList* list) {
   struct Node* currentNode = list->head;
   while (currentNode != NULL) {
      printf ("%d -> ", currentNode->data);
      currentNode = currentNode->link;
   }
   printf ("NULL\n");
}

//Prints the value at a specific index in the list or an error if the index is out of bounds
void CheckGet (const LinkList* list, int index) {
   int value;
   int result = Get (list, index, &value);
   if (result == ERROR_OUT_OF_BOUNDS) {
      printf ("Error: list is empty.\n", index);
   }
   else {
      printf ("Element at index %d: %d\n", index, value);
   }
}

//Test program
int main () {
   LinkList list;
   //Create an empty linked list
   Create (&list);

   // Add elements to the end of the list
   Add (&list, 10);
   Add (&list, 20);
   Add (&list, 30);
   Add (&list, 40);
   Add (&list, 20);
   printf ("List before inserting elements: ");
   PrintList (&list);

   //Insert element at specific indexes
   Insert (&list, 1, 15);
   Insert (&list, 3, 90);
   printf ("List after inserting elements: ");
   PrintList (&list);

   //Remove an element at a specific index
   RemoveAt (&list, 1);
   printf ("List after removing the element at index 1: ");
   PrintList (&list);

   //Remove the first occurrence of a specific element
   Remove (&list, 20);
   printf ("List after removing the first occurrence of 20: ");
   PrintList (&list);

   //Count the number of elements in the list
   printf ("The number of elements in the list: %d\n", Count (&list));

   //Get an element at a specific index
   int value;
   Get (&list, 1, &value);
   printf ("Element at index 1: %d\n", value);

   //Delete the entire list
   DeleteList (&list);
   printf ("List is deleted\n");

   //Count the element after deleting the list
   printf ("The number of elements in the list: %d\n", Count (&list));

   CheckGet (&list, 0);

   // Print list after deletion to ensure it's empty
   PrintList (&list);
  
   return 0;
}