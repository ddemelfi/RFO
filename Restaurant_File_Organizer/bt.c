#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bt.h"

BinaryTree* createBinaryTree() {
	BinaryTree *bt = (BinaryTree*)malloc(sizeof(BinaryTree));
	return bt;
}

void insertInBinaryTree(BinaryTree* bt, char *key, Restaurant *r) {
	node *n = (node*)malloc(sizeof(node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->list = createArrayList();
	insertArrayList(n->list, r);
	if(bt->root == NULL){
		bt->root = n;
	} else{
		node *current = bt->root;
		while(true){
			if(keystrcmp(n, current) == 0){
				insertArrayList(current->list, r);
				bt->size++;
				return;
			}
			if(keystrcmp(n, current) < 0){
				if(current->left == NULL){
					current->left = n;
					bt->size++;
					return;
				} else{
					current = current->left;
				}
			} else{
				if(current->right == NULL){
					current->right = n;
					bt->size++;
					return;
				} else{
					current = current->right;
				}
			}
		}
	}
}

node* replace(node *current){
	while(current){
		if(current->left != NULL){
			return replace(current->left);
		} else if(current->right != NULL){
			return replace(current->right);
		}
	}
	return current;
}

node* deleteNode(node *root, char *name, char *city){
	int count = 0;
	if(root == NULL){
		return NULL;
	}
	if(strcmp(name, root->key) < 0){
		root->left = deleteNode(root->left, name, city);
	} else if(strcmp(name, root->key) > 0){
		root->right = deleteNode(root->right, name, city);
	} else{
		if(strcmp(root->list->restaurants[0]->city, city) == 0){
			if(root->left == NULL && root->right == NULL){
				free(root);
				return NULL;
			} else if (root->left == NULL) {
				struct node* temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL) {
				struct node* temp = root->left;
				free(root);
				return temp;
			} else {
				struct node *temp = replace(root->right);
				root->list = temp->list;
				root->key = temp->key;
				root->right = deleteNode(root->right, temp->key, temp->list->restaurants[0]->city);
			}
		}
	}
	return root;
}

void searchNode(node *root, char *city, char *category, char *cost, char *time){
	if(root == NULL){
		printf("\nTree is empty\n");
		return;
	}
	if(root->left != NULL){
		searchNode(root->left, city, category, cost, time);
	}
	queryArrayList(root->list, city, category, cost, time);
	if(root->right != NULL){
		searchNode(root->right, city, category, cost, time);
	}
}

void searchNodeNL(node *root, char *name, char *city){
	if(root == NULL){
		printf("\nTree is empty\n");
		return;
	}
	if(root->left != NULL){
		searchNodeNL(root->left, name, city);
	}
	queryArrayListNL(root->list, name, city);
	if(root->right != NULL){
		searchNodeNL(root->right, name, city);
	}
}

void modifyNode(node *root, char *name, char *city, Restaurant *rest){
	if(root == NULL){
		printf("\nTree is empty\n");
		return;
	}
	if(root->left != NULL){
		modifyNode(root->left, name, city, rest);
	}
	modifyArrayList(root->list, name, city, rest);
	if(root->right != NULL){
		modifyNode(root->right, name, city, rest);
	}
}

void writeBinaryTree(node *node, FILE *file) {
    if(node != NULL){
        if(node->left != NULL){
			writeBinaryTree(node->left, file);
		}
		fprintf(file, ("%s", arrayListToString(node->list)));
		if(node->right != NULL){
			writeBinaryTree(node->right, file);
		}
    }
    else
        return;
}

int keystrcmp(node *t1, node *t2){
	return strcmp(t1->key, t2->key);
}

void BinaryTreeInOrder(node* node) {
	if(node->left != NULL){
		BinaryTreeInOrder(node->left);
	}
	printArrayList(node->list);
	if(node->right != NULL){
		BinaryTreeInOrder(node->right);
	}
}

extern void freeTree(node *root){
	if( root != NULL ){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}