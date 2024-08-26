// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// // intlist.h
// Program on A2 branch.
// -------------------------------------------------------------------------------------------
/// <summary>
/// Implement a linked list data structure to handle integer elements. The implementation will consist of three files:
/// intlist.h - the header file
/// intlist.c - the code.
/// testintlist.c - the program that tests the implementation.
///
/// The following functions have to be implemented:
/// a) Create – this will create a new linked list.
/// b) Delete – this will delete the list and all the linked elements.
/// c) Add – this will add an element to the end of the list.
/// d) Insert – this will insert an element at a particular index(zero based).For example, if the linked list has 4 elements.Calling Insert with an index of 2 will insert the new element between that at index 1 and that at index 2.
/// e) RemoveAt – this will remove the element at a particular index(zero based).
/// f) Remove – removes the first occurrence of a specific element.
/// g) Count – number of elements in the list.
/// h) Get – gets the element at a particular index.
/// </summary>
// ------------------------------------------------------------------------------------------------

#ifndef INTLIST_H
#define INTLIST_H

//define error messages
#define SUCCESS 0
#define ERROR_OUT_OF_BOUNDS 1
#define ERROR_MEMORY_ALLOCATION 2 
#define ERROR_ELEMENT_NOT_FOUND 3
#define ERROR_NULL_LIST -1

//Define the structure of the node
struct Node {
   int data;
   struct Node* link;
};

//Define the structure of the linked list
typedef struct LinkList {
   struct Node* head;
   int size;
}LinkList;

/// <summary>Initialize an empty linked list.</summary>
LinkList* Create ();

/// <summary>Delete all nodes in the linked list and free allocated memory.</summary>
void DeleteList (LinkList* list);

/// <summary>Add a new element to the end of the linked list.</summary>
int Add (LinkList* list, int value);

/// <summary>Insert an element at a specific index in the linked list.</summary>
int Insert (LinkList* list, int index, int value);

/// <summary>Remove the element at a specific index from the linked list.</summary>
int RemoveAt (LinkList* list, int index);

/// <summary>Remove the first occurrence of the node with a specific value.</summary>
int Remove (LinkList* list, int value);

/// <summary>Return the number of element in the linked list.</summary>
int Count (LinkList* list);

/// <summary>Get the element at a specific index and store it in the provided pointer./summary>
int Get (const LinkList* list, int index, int* value);

/// <summary>Print the elements of the linked list to the standard output./summary>
void PrintList (LinkList* list);

/// <summary>Check the value at a specific index in the linked list and print it.
/// If the index is out of bounds, prints an error message.</summary>
void CheckGet (const LinkList* list, int index);

#endif INTLIST_H;
