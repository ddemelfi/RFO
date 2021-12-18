#include "linkedList.h"

LinkedList* createLinkedList() {
	//printf("Entered createLinkedList()\n");
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->size = 0;
	return list;
}

void insertLinkedList(LinkedList* list, char* data) {
	//printf("Entered insertLinkedList()\n");
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(sizeof(char) * strlen(data));
	if(strchr(data, '\n') == NULL) {
		strcpy(newNode->data, data);
	} else {
		strncpy(newNode->data, data, strlen(data) - 1);
	}

	//If list is empty
	if(list->size <= 0) {
		list->head = newNode;
		list->tail = newNode;
		list->size = 1;
		return;
	}
	list->tail->next = newNode;  //Sets previous last node's next pointer to new student node
	newNode->prev = list->tail; //Sets new student node's prev pointer to old tail
	list->tail = newNode;      //Sets tail pointer to new last student
	list->size++;
}

bool findCategory(LinkedList* list, char* find) {
	Node* nodePtr;

	char* substr = (char*)malloc(sizeof(char) * strlen(find));
	strcpy(substr, find);
	char* delim = ",";
	substr = strtok(substr, delim);
	//Runs until out of categories to look for
	while(substr != NULL) {
		//Removes whitespace before category name
		while(*substr == ' ') { substr++; }

		//Iterates through Linked List
		nodePtr = list->head;
		for(int i = 0; i < list->size; i++) {
			//If category ever matches one of the restaurant's, break and start again with next category
			if(strcmp(nodePtr->data, substr) == 0) {
				break;
			//If category has not matched with any of the restaurant's, return false
			} else if(i == list->size - 1) {
				free(substr);
				return false;
			}
			nodePtr = nodePtr->next;
		}

		substr = strtok(NULL, delim);
	}
	free(substr);
	return true;
}

// list -> restaurant categories, spearated into a linked list. 
// find -> the string, separated by the OR that will be searched for, if either one match the linked list. 
bool findCategoryOR(LinkedList* list, char* find) {
	Node* nodePtr;

	char* substr = (char*)malloc(sizeof(char) * strlen(find));
	strcpy(substr, find);
	char* delim = "OR";
	substr = strtok(substr, delim);
	//Runs until out of categories to look for
	while(substr != NULL) {
		//Removes whitespace before and after category name
		/*while(*substr == ' ') { substr++; }
		while(substr[strlen(substr)+1] == ' ') { substr--; }*/
		substr = trimwhitespace(substr);

		//Iterates through Linked List
		nodePtr = list->head;
		for(int i = 0; i < list->size; i++) {
			//If category ever matches one of the restaurant's, return true and print the restaurant. Otherwise, keep checking with the next category
			if(strcmp(nodePtr->data, substr) == 0) {
				return true;
			} 
			nodePtr = nodePtr->next;
		}
		substr = strtok(NULL, delim);
	}
	free(substr);
	return false;
}

char *trimwhitespace(char *str){
	char *end;

	// Trim leading space
	while(isspace((unsigned char)*str)) str++;

	if(*str == 0)  // All spaces?
	return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end)) end--;

	// Write new null terminator character
	end[1] = '\0';

	return str;
}

void printLinkedList(LinkedList* list) {
	//printf("Entered printLinkedList()\n");

	Node* nodePtr = list->head;
	//Iterates through Linked List
	for(int i = 0; i < list->size; i++) {
		printf("%s", nodePtr->data);
		nodePtr = nodePtr->next;
	}
}

char* linkedListToStr(LinkedList* list) {
	//printf("Entered linkedListToStr()\n");
	if(list->size == 0) { 
		return ""; 
	}

	char* str = (char*)malloc(sizeof(char) * 100);
	Node* nodePtr = list->head;
	//Iterates through Linked List
	for(int i = 0; i < list->size; i++) {
		if(i > 0) {
			strcat(str, ", "); //Adds a comma after each node data
		}
		strcat(str, nodePtr->data); //Appends node's data to end of return string
		nodePtr = nodePtr->next;
	}
	return str;
}

char* linkedListToStrJoined(LinkedList* list) {
	//printf("Entered linkedListToStr()\n");
	if(list->size == 0) {
		return "";
	}

	char* str = (char*)malloc(sizeof(char) * 3);
	Node* nodePtr = list->head;
	//Iterates through Linked List
	for(int i = 0; i < list->size; i++) {
		strcat(str, nodePtr->data); //Appends node's data to end of return string
		nodePtr = nodePtr->next;
	}
	return str;
}

void freeLinkedList(LinkedList* list) {
	//printf("Entered freeLinkedList()\n");
	Node* nodePtr = list->head;
	for(int i = 0; i < list->size - 1; i++) {
		free(nodePtr->data);
		nodePtr = nodePtr->next;
		free(nodePtr->prev);
	}
	free(nodePtr->data);
	free(nodePtr);
	free(list);
}