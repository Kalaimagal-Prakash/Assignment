// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// intlist.c
// Program on Linked List Functions.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include "intlist.h"

//Create an empty linked list
void Create(LinkList* list) {
   list->head = NULL;
   list->size = 0;
   printf("An Empty List is Created.\n");
}

//Delete the linked list and all elements
void DeleteList(LinkList* list) {
   struct Node* current = list->head;
   struct Node* nextNode;
   while (current != NULL) {
      nextNode = current->link;
      free(current);
      current = nextNode;
   }
   list->head = NULL;
   list->size = 0;
   printf("The list has been deleted.\n");
}

//Add an element to the end of the list.
void Add(LinkList* list, int value) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   struct Node* lastNode = list->head;
   if (newNode == NULL) {
      printf("Memory allocation failed.\n");
      return;
   }
   newNode->data = value;
   newNode->link = NULL;
   if (list->head == NULL) {
      list->head = newNode;
   }
   else {
      while (lastNode->link != NULL) {
         lastNode = lastNode->link;
      }
      lastNode->link = newNode;
   }
   list->size++;
}

//Insert an element at a specific index
void Insert(LinkList* list, int index, int value) {
   if (index < 0 || index > list->size) {
      printf("Index are out of bounds\n");
      return;
   }
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   struct Node* currentNode = list->head;
   newNode->data = value;
   if (index == 0) {
      newNode->link = list->head;
      list->head = newNode;
   }
   else {
      for (int i = 0; i < index - 1; i++) {
         currentNode = currentNode->link;
      }
      newNode->link = currentNode->link;
      currentNode->link = newNode;
   }
   list->size++;
}

//Remove an element at a specific index
void RemoveAt(LinkList* list, int index) {
   if (index < 0 || index > list->size) {
      printf("Index are out of bounds\n");
      return;
   }
   struct Node* currentNode = list->head;
   struct Node* previousNode = NULL;
   if (index == 0) {
      list->head = currentNode->link;
      free(currentNode);
   }
   else {
      for (int i = 0; i < index; i++) {
         previousNode = currentNode;
         currentNode = currentNode->link;
      }
      previousNode->link = currentNode->link;
      free(currentNode);
   }
   list->size--;
}

// Remove the first occurrence of a node with specific value
void Remove(LinkList* list, int value) {
   struct Node* currentNode = list->head;
   struct Node* previousNode = NULL;
   // Traverse the list to find the node with the specified value
   while (currentNode != NULL && currentNode->data != value) {
      previousNode = currentNode;
      currentNode = currentNode->link;
   }
   if (currentNode == NULL) {
      printf("Element %d not found in the list.\n", value);
      return;
   }
   if (previousNode == NULL) {
      list->head = currentNode->link;
   }
   else {
      previousNode->link = currentNode->link;
   }
   free(currentNode);
   list->size--;
}

//Return the number of elements in the list
int Count(LinkList* list) {
   return list->size;
}

//Get the element at a specific index
int Get(const LinkList* list, int index) {
   if (index < 0 || index >= list->size) {
      printf("Index out of bounds.\n");
      return -1;
   }
   struct Node* currentNode = list->head;
   for (int i = 0; i < index; i++) {
      currentNode = currentNode->link;
   }
   return currentNode->data;
}

//Print all element of the list
void PrintList(LinkList* list) {
   struct Node* currentNode = list->head;
   while (currentNode != NULL) {
      printf("%d->", currentNode->data);
      currentNode = currentNode->link;
   }
   printf("Null\n");
}
