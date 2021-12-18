#ifndef READIN
#define READIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"
#include "linkedList.h"
#include "arrayList.h"
#include "bt.h"

/** 
* Reads the given file of correctly formatted restaurants into an arraylist.
* @param char* - Name of the file to read in.
* @return RestaurantArrayList* - Arraylist of all restaurants read in.
*/
void readIn(char* fileName, BinaryTree *resListName, BinaryTree *resListCity);

/**
* Parses foodTypes input into substrings and inserts them into given restaurant.
* @param Restuarant* to insert substring categories into.
* @param char* - foodTypes to be parsed, categories seperated by commas.
*/
void parseFoodTypes(Restaurant* res, char* foodTypes);

/**
* Parses cost input into the given restaurant based on input size.
* @param Restuarant* to insert cost into.
* @param char* - Cost to be parsed, in solely any number of '$'s.
*/
void parseCost(Restaurant* res, char* cost);

extern void writeFile(char *fileName, BinaryTree *resListName, BinaryTree *resListCity);

#endif //!READIN