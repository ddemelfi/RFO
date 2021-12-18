#ifndef RESTAURANT
#define RESTAURANT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

typedef struct OpenTimes {
	char** days; //Array of days of the week open
	char** hoursOpen; //Array of hours each restaurant opens, each element corresponds to days array
	char** hoursClose; //Array of hours each restaurant closes, each element corresponds to days array
	int numDays; //Number of days open, num of elements in both lists
} OpenTimes;

typedef struct Restaurant {
	char* name;
	char* city;
	LinkedList* foodTypes;
	OpenTimes* daysHoursOpen;
	LinkedList* cost;
	char* rank;
	char* numReviews;
} Restaurant;

/**
* Initializes a Restaurant struct
* @return Restaurant* struct
*/
Restaurant* initRestaurant();

/**
* Initializes an OpenTimes struct
* @return OpenTimes* struct
*/
OpenTimes* initOpenTimes();

/**
* @param OpenTimes* - an EMPTY OpenTimes struct pointer.
* @param char* - a formatted string to be broken into data for the struct. This string will be destroyed in the process.
*/
void setOpenTimes(OpenTimes* resOpen, char* daysHoursOpen);

/**
* Prints given restaurant in multi-line format.
* @param Restaurant* - struct to print.
*/
void printRestaurant(Restaurant* res);

/**
* @param OpenTimes* struct to make a string of
* @return char* - string of OpenTimes struct, must be freed
*/
char* openTimesToStr(OpenTimes* resOpen);

/**
* Finds if the provided time is within the open hours of the struct.
* @param OpenTimes* - struct to compare input time to.
* @param char* - Provided formatted time.
*/
bool checkTime(OpenTimes* resOpen, char* findTime);

/**
* Frees the given restaurant and all it's contents.
* @param Restaurant* - struct to free.
*/
void freeRestaurant(Restaurant* res);

/**
* Frees the given OpenTimes struct and all it's contents.
* @param OpenTimes* - struct to free.
*/
void freeOpenTimes(OpenTimes* resOpen);

char* restaurantToStr(Restaurant *rest);

#endif // !RESTAURANT