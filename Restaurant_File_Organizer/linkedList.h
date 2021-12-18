#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Node {
	char* data;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct LinkedList {
	int size;

	Node* head;
	Node* tail;
} LinkedList;

/**
* Initializes a linked list
* @return LinkedList*
*/
extern LinkedList* createLinkedList();

/**
* Inserts a new node to the provided linked list with the provided data.
* @param LinkedList* to insert into
* @param char* - data to insert
*/
extern void insertLinkedList(LinkedList* list, char* data);

/**
* Finds if the provided categor(ies) are in the provided linked list.
* @param LinkedList* of categories to compare to.
* @param char* - String of categor(ies) to compare.
* @return True if the provided categor(ies) are all within the list,
* false if any one is not.
*/
extern bool findCategory(LinkedList* list, char* find);

extern bool findCategoryOR(LinkedList* list, char* find);

extern char *trimwhitespace(char *str);

/**
* Prints the provided linked list.
* @param LinkedList* to print.
*/
extern void printLinkedList(LinkedList* list);

/**
* Turns the provided linked list into a string, each node's data seperated by commas.
* @param LinkedList* of strings to turn into a string.
* @return char* - String created from linked list data.
*/
extern char* linkedListToStr(LinkedList* list);

/** 
* Converts a linked list to an unsperated string.
* @param LinkedList* of strings to turn into a string.
* @return char* - String created from linked list data.
*/
extern char* linkedListToStrJoined(LinkedList* list);

/**
* Frees the given linked list and all it's contents.
* @param LinkedList* to free.
* @return char* - String created from linked list data.
*/
extern void freeLinkedList(LinkedList* list);

#endif // !LINKEDLIST