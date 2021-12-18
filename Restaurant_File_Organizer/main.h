#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "restaurant.h"
#include "arrayList.h"
#include "readIn.h"
#include "bt.h"

#include "main.h"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

/**
* main. Calls initial restaurant file read in and handles final frees.
*/
int main();

/**
* Runs the user-interface menu through once.
* @param RestaurantArrayList* - an array of restaurants to use in prints & searches.
* @param char* - String to hold the user input command in.
* @return bool - True if menu is to be run again, false if user exited.
*/
bool runMenu(BinaryTree* resListName, BinaryTree* resListCity, char* command);

extern void addRestaurant(BinaryTree *resListName, BinaryTree *resListCity);

extern void searchRestaurant(BinaryTree *resListName, BinaryTree *resListCity);

extern void searchRestaurantNL(BinaryTree *resListName, BinaryTree *resListCity);

extern void modifyRestaurant(BinaryTree *resListName, BinaryTree *resListCity);

extern void removeRestaurant(BinaryTree *resListName, BinaryTree *resListCity);

#endif // !MAIN
