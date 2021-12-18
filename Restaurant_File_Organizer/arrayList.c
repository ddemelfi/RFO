#include "arrayList.h"

RestaurantArrayList* createArrayList() {
	//printf("Entered createArrayList()\n");
	RestaurantArrayList* arrayList = (RestaurantArrayList*)malloc(sizeof(RestaurantArrayList));
	arrayList->numElements = 0;

	arrayList->restaurants = (Restaurant**)malloc(sizeof(Restaurant) * 10);
	arrayList->maxLength = 10;
	return(arrayList);
}

void growArray(RestaurantArrayList* arrayList) {
	//printf("Entered growArray()\n");
	//Mallocs new array of double size of old array
	Restaurant** newArray = (Restaurant**)malloc(sizeof(Restaurant) * arrayList->maxLength * 2);
	for(int i = 0; i < arrayList->numElements; i++) {
		newArray[i] = arrayList->restaurants[i];
	}
	free(arrayList->restaurants);
	arrayList->restaurants = 0;
	arrayList->restaurants = newArray;
	arrayList->maxLength *= 2;
}

void insertArrayList(RestaurantArrayList* arrayList, Restaurant* restaurant) {
	//printf("Entered insertArrayList()\n");
	//If ran out of space, grow the array
	if(arrayList->numElements >= arrayList->maxLength) {
		growArray(arrayList);
	}
	//Initializes new restaurant
	arrayList->restaurants[arrayList->numElements] = initRestaurant();
	//Copies passed restaurant to new one
	*(arrayList->restaurants[arrayList->numElements]) = *restaurant;
	arrayList->numElements++;
}

bool removeFromArrayList( RestaurantArrayList* al, int index ) {
	//finds index of the restaurant to be deleted
    //int index = indexOfAL(al, s1, s2);
	//if the index is not found, return false
	if(index < 0 || index >= al-> numElements){
		return false;
	}
	int count = 0;
	//copy each element of the array to the index before it starting at the index of the element to be removed
	for(int i = index; i < al->numElements-1; i++){
        al->restaurants[i] = al->restaurants[i+1];
		count++;
	}
	//gets rid of the last element, but mallocs it so it can be added to again. 
	al->restaurants[count+1] = NULL;
	al->restaurants[count+1] = (Restaurant*)malloc(sizeof(Restaurant));
    al->numElements--;
    
    return true;
}

int indexOfAL(RestaurantArrayList* al, char *s1, char *s2){
	//iterate through the array 
	for(int i = 0; i < al->numElements; i++){
		//compare the array list of restaurants to the restaurant being searched for
		if(strcmp(al->restaurants[i]->name, s1) == 0 && strcmp(al->restaurants[i]->city, s2) == 0 ||
			strcmp(al->restaurants[i]->name, s2) == 0 && strcmp(al->restaurants[i]->city, s1) == 0){
			//returns the index
			return i;
		}
	}
	//if not found, returns -1
	return -1;
}

void printArrayList(RestaurantArrayList* arrayList) {
	//printf("Entered printArrayList()\n");
	if(arrayList->maxLength > 0) {
		for(int i = 0; i < arrayList->numElements; i++) {
			printRestaurant(arrayList->restaurants[i]);
		}
	} else {
		printf("Empty array\n");
	}
}

void queryArrayList(RestaurantArrayList* arrayList, char* city, char* category, char* cost, char* time) {
	for(int i = 0; i < arrayList->numElements; i++) {
		//Compares all user inputs to current restaurant. Includes don't cares, i.e. an input is "*".
		if((strcmp(city, "*") == 0 || strcmp(arrayList->restaurants[i]->city, city) == 0)
		   && (strcmp(category, "*") == 0 || findCategory(arrayList->restaurants[i]->foodTypes, category)
										  || findCategoryOR(arrayList->restaurants[i]->foodTypes, category))
		   && (strcmp(cost, "*") == 0 || arrayList->restaurants[i]->cost->size <= strlen(cost))
		   && (strcmp(time, "*") == 0 || checkTime(arrayList->restaurants[i]->daysHoursOpen, time))) {
			printRestaurant(arrayList->restaurants[i]);
			
		}
	}
}

void queryArrayListNL(RestaurantArrayList* arrayList, char *name, char* city){
	for(int i = 0; i < arrayList->numElements; i++){
		if((strcmp(arrayList->restaurants[i]->name, name) == 0) &&
		   (strcmp(arrayList->restaurants[i]->city, city) == 0)){
			 printRestaurant(arrayList->restaurants[i]);
		}
	}
}

void modifyArrayList(RestaurantArrayList* arrayList, char *name, char* city, Restaurant *rest){
	for(int i = 0; i < arrayList->numElements; i++){
		if((strcmp(arrayList->restaurants[i]->name, name) == 0) &&
		   (strcmp(arrayList->restaurants[i]->city, city) == 0)){
			 free(arrayList->restaurants[i]);
			 arrayList->restaurants[i] = initRestaurant();
			 arrayList->restaurants[i] = rest;
		}
	}
}

char* arrayListToString(RestaurantArrayList *list){
	char *restaurants;
	restaurants = (char *)malloc(sizeof(char) * 300 * list->numElements);
	for(int i = 0; i < list->numElements; i++){
		strcat(restaurants, restaurantToStr(list->restaurants[i]));
		strcat(restaurants, "\n");
	}
	return restaurants;
}

void freeArrayList(RestaurantArrayList* resList) {
	for(int i = 0; i < resList->numElements; i++) {
		freeRestaurant(resList->restaurants[i]);
	}
	free(resList);
}