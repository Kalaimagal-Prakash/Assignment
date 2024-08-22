// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// intlist.c
// Program on A2 branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include "intlist.h"

void Create (LinkList* list) {
   list->head = NULL;
   list->size = 0;
}

void DeleteList (LinkList* list) {
   struct Node* current = list->head;  // Start from the head of the list
   struct Node* nextNode;
   while (current != NULL) {          //Traverse the list and free each node
      nextNode = current->link;
      free (current);
      current = nextNode;
   }
   list->head = NULL;
   list->size = 0;
}

void Add (LinkList* list, int value) {
   if (list == NULL) return;
   struct Node* newNode = (struct Node*)malloc (sizeof (struct Node));
   if (newNode == NULL) return ERROR_MEMORY_ALLOCATION;
   newNode->data = value;
   newNode->link = NULL;
   if (list->head == NULL) list->head = newNode;                   // If the list is empty the new node becomes the head
   else {
      struct Node* lastNode = list->head;
      while (lastNode->link != NULL) lastNode = lastNode->link;  // Traverse to the end of the list
      lastNode->link = newNode;
   }
   list->size++;
}

void Insert (LinkList* list, int index, int value) {
   if (index < 0 || index > list->size) return ERROR_OUT_OF_BOUNDS;
   struct Node* newNode = (struct Node*)malloc (sizeof (struct Node));
   newNode->data = value;
   if (index == 0) {
      newNode->link = list->head;
      list->head = newNode;
   }
   else {
      struct Node* currentNode = list->head;
      for (int i = 0; i < index - 1; i++) currentNode = currentNode->link;    // Traverse to the node before the insertion
      newNode->link = currentNode->link;
      currentNode->link = newNode;
   }
   list->size++;
}

void RemoveAt (LinkList* list, int index) {
   if (list == NULL || list->head == NULL || index < 0 || index > list->size) return ERROR_OUT_OF_BOUNDS;
   struct Node* currentNode = list->head;
   if (index == 0) {
      list->head = currentNode->link;
      free (currentNode);
   }
   else {
      struct Node* previousNode = NULL;
      for (int i = 0; i < index; i++) {         // Traverse to the node before the removal
         previousNode = currentNode;
         currentNode = currentNode->link;
      }
      previousNode->link = currentNode->link;
      free (currentNode);
   }
   list->size--;
}

void Remove (LinkList* list, int value) {
   struct Node* currentNode = list->head;
   struct Node* previousNode = NULL;
   if (currentNode == NULL) return ERROR_ELEMENT_NOT_FOUND;
   while (currentNode->data != value) {  // Traverse the list to find the node with the specified value
      previousNode = currentNode;
      currentNode = currentNode->link;
   }
   if (previousNode == NULL) list->head = currentNode->link;
   else previousNode->link = currentNode->link;
   free (currentNode);
   list->size--;
}

int Count (LinkList* list) {
   return list->size;
}

int Get (const LinkList* list, int index, int* value) {
   if (index < 0 || index >= list->size) return ERROR_OUT_OF_BOUNDS;
   if (list->head == NULL) return ERROR_OUT_OF_BOUNDS;
   struct Node* currentNode = list->head;
   for (int i = 0; i < index; i++) currentNode = currentNode->link;    // Traverse to the desired index
   *value = currentNode->data;
   return 0;
}


