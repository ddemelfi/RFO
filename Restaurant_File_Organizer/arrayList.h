#ifndef ARRAYLIST
#define ARRAYLIST
#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"
#include "linkedList.h"

typedef struct RestaurantArrayList {
	Restaurant** restaurants; //Array of restaurants
	int maxLength; //Total length, including empty slots
	int numElements; //Num of filled slots
} RestaurantArrayList;

/** 
* Create new ArrayList with 0 elements and 10 length.
* @return: a pointer to the newly created ArrayList.
*/
RestaurantArrayList* createArrayList();

/** 
* Double the size of given array in an RestaurantArrayList struct.
* @param RestuarantArrayList struct.
*/
void growArray(RestaurantArrayList* arrayList);

/** 
* Inserts a new element into the provided RestaurantArrayList.
* @param RestuarantArrayList struct.
* @param Restaurant to insert.
*/
void insertArrayList(RestaurantArrayList* arrayList, Restaurant* restaurant);

/**
* Removes a restaurant from the arraylist (unused)
* @param RestuarantArrayList struct to search through.
* @param int - index that will be removed
* @return whether it was successfully removed
*/
bool removeFromArrayList( RestaurantArrayList* al, int index );

/**
* Returns the index of the AL for the matching Restaurant of the given strings 
* @param char - s1 the first string to be searched for either name or city
* @param char - s2 the second string to be searched for either name or city
* @return the inde of the found restaurant
*/ 
int indexOfAL(RestaurantArrayList* al, char *s1, char *s2);

/** 
* Prints the contents of the arraylist in a list.
* @param RestuarantArrayList struct to print.
*/
void printArrayList(RestaurantArrayList* arrayList);

/**
* Prints all restaurants in given arraylist whose information matches that given in the parameters.
* @param RestuarantArrayList struct to search through.
* @param char* - City to search for.
* @param char* - Categor(ies) to search for.
* @param char* - Cost to search for.
* @param char* - Time to search for.
*/
void queryArrayList(RestaurantArrayList* arrayList, char* city, char* category, char* cost, char* time);

/**
* Prints all restaurants in given arraylist whose information matches that given in the parameters.
* @param RestuarantArrayList struct to search through.
* @param char* - Name to search for.
* @param char* - City
*/
extern void queryArrayListNL(RestaurantArrayList* arrayList, char *name, char* city);

/**
* Modifies a restaurant that will be searched for using the parameters and replaces the restaurant with the one given
* @param RestuarantArrayList struct to search through.
* @param char* - Name to search for.
* @param char* - City) to search for.
* @param Restaurant* - The modified restaurant
*/
extern void modifyArrayList(RestaurantArrayList* arrayList, char *name, char* city, Restaurant *rest);

/**
* Creates a string of the entire arraylist with each Restaurant inside
* @param list the ArrayList that will be turned into a string
* @return the char * to the new string
*/
extern char* arrayListToString(RestaurantArrayList *list);

/**
* Frees the given arraylist and all it's contents.
* @param RestaurantArrayList* - Arraylist to free.
*/
void freeArrayList(RestaurantArrayList* resList);

#endif // !ARRAYLIST