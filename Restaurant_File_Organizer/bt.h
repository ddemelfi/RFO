#ifndef BINARYTREE
#define BINARYTREE

#define MAXPRINTBUFFER 500

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "arrayList.h"

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
} TreeOrder;

typedef struct node {
	RestaurantArrayList *list;
	char *key; //either location or name of restaurant
	struct node *left;
	struct node *right;
} node;

typedef struct BinaryTree {
	node *root; 
	int size;
} BinaryTree;

/** 
* Create and make space for a new binary tree
* @return a pointer to the newly created Binary Tree.
*/
extern BinaryTree* createBinaryTree();

/** 
* Inserts a restaurant into the binary tree and inserts a key, which can either be the name or city or the binary tree. It creates 
* a node, then adds that node to the tree. 
* @param bt -> the Binary Tree being added to.
* @param key -> either the name or the city of the restaurant that will be put into the node being created
* @param r -> the restaurant being added to the binary tree
*/
extern void insertInBinaryTree( BinaryTree* bt, char *key, Restaurant* r);

/** 
* Finds the minumum value and returns the node that will replace the removed node for the delete node function
* @param node -> the node where the recursive method will start before trying to find the smallest node after it. 
* @return the smallest value of the node that was found.
*/
extern node* replace(node *node);

/** 
* Deletes a node from the tree, recursively, if the city and name of the restaurants in the node match the params
* @param root -> the Binary Tree root that will be deleted 
* @param name -> the name that will be searched for in each node to delete
* @param city -> the city that will be searched for in each node to delete 
* @return the node that was deleted from the tree
*/
extern node* deleteNode(node *root, char *name, char *city);

/** 
* Calls ArrayListQuery on each node in order to find a match of the parameters. 
* @param root -> the Binary Tree root that will start the search
* @param city -> the city that will be searched for in each node 
* @param category -> the category that will be searched for in each node 
* @param cost -> the cost that will be searched for in each node 
* @param time -> the time that will be searched for in each node 
*/
extern void searchNode(node *root, char *city, char *category, char *cost, char *time);

/** 
* Calls ArrayListQuery on each node in order to find a match of the parameters. 
* @param root -> the Binary Tree root that will start the search
* @param name -> the name that will be searched for in each node 
* @param city -> the city that will be searched for in each node 
*/
extern void searchNodeNL(node *root, char *name, char *city);

/** 
* Calls ArrayListQuery on each node to see if the parameters match the node an if they do, the restaurants get modified.
* @param root -> the Binary Tree root that will start the search
* @param name -> the name that will be searched for in each node 
* @param city -> the city that will be searched for in each node 
* @param rest -> the modified restaurant that will replace the old one
*/
extern void modifyNode(node *root, char *name, char *city, Restaurant* rest);

/** 
* Writes the current Binary Tree to the file specified 
* @param root -> the Binary Tree root that will be written to the file
* @param file -> the FILE that will be written to if a match is found
*/
extern void writeBinaryTree(node *root, FILE *file);

/** 
* Prints the Binary Tree in Order, the only order that was needed for the purposes of this project. 
* @param node -> the starting node of the tree that will be printed out in order
*/
extern void BinaryTreeInOrder(node* node);

/** 
* Shorter way to comapre the two keys of the nodes using strcmp
* @param t1 -> the first node being comapred
* @param t2 -> the second node being compared
* @return the result of the comparison
*/
extern int keystrcmp(node *t1, node *t2);

/**
* Frees the tree completely by starting at the node
* @param root -> the starting node for the tree
*/
extern void freeTree(node *root);

#endif