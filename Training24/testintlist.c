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
void PrintList (LinkList* list) {
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
   if (result == ERROR_OUT_OF_BOUNDS) printf ("Error: list is empty.\n");
   else printf ("Element at index %d: %d\n", index, value);
}

//Test program
int main () {
   //Create an empty linked list
   LinkList* list = Create ();
   if (list == NULL) {
      printf ("Error creating the list.\n");
      return 1;
   }
   printf ("Initial List: ");
   PrintList (list);

   // Add elements to the end of the list
   Add (list, 10);
   Add (list, 20);
   Add (list, 30);
   Add (list, 40);
   Add (list, 20);
   printf ("List before inserting elements: ");
   PrintList (list);

   //Insert element at specific indexes
   Insert (list, 2, -2);
   Insert (list, 3, 90);
   printf ("List after inserting elements: ");
   PrintList (list);

   //Remove an element at a specific index
   RemoveAt (list, 3);
   printf ("List after removing the element at index 3: ");
   PrintList (list);

   //Remove the first occurrence of a specific element
   Remove (list, 20);
   printf ("List after removing the first occurrence of 20: ");
   PrintList (list);

   //Count the number of elements in the list
   printf ("The number of elements in the list: %d\n", Count (list));

   //Get an element at a specific index
   int value;
   Get (list, 1, &value);
   if (value != ERROR_OUT_OF_BOUNDS) printf ("Element at index 2: %d\n", value);
   else printf ("Invalid index\n");

   //Delete the entire list
   DeleteList (list);
   printf ("List is deleted\n");
   return 0;
}