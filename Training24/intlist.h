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
#define ERROR_OUT_OF_BOUNDS "Index out of bounds"
#define ERROR_MEMORY_ALLOCATION "Memory allocation failed"
#define ERROR_ELEMENT_NOT_FOUND "Element not found"

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
 
//Function operations
void Create (LinkList* list);
void DeleteList (LinkList* list);
void Add (LinkList* list, int value);
void Insert (LinkList* list, int index, int value);
void RemoveAt (LinkList* list, int index);
void Remove (LinkList* list, int value);
int Count (LinkList* list);
int Get (const LinkList* list, int index, int* value);
void PrintList (LinkList* list);
void CheckGet (const LinkList* list, int index);

#endif //INTLIST_H
