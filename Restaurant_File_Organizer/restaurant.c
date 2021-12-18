#include "restaurant.h"

Restaurant* initRestaurant() {
	//printf("Entered initRestaurant()\n");
	Restaurant* res = (Restaurant*)malloc(sizeof(Restaurant));
	res->name = (char*)malloc(sizeof(char) * 200);
	res->city = (char*)malloc(sizeof(char) * 200);
	res->rank = (char*)malloc(sizeof(char) * 200);
	res->numReviews = (char*)malloc(sizeof(char) * 200);

	res->daysHoursOpen = initOpenTimes();
	res->foodTypes = createLinkedList();
	res->cost = createLinkedList();
	return res;
}

OpenTimes* initOpenTimes() {
	OpenTimes* openTimes = (OpenTimes*)malloc(sizeof(OpenTimes));
	openTimes->days = (char**)malloc(sizeof(char*) * 7);
	openTimes->hoursOpen = (char**)malloc(sizeof(char*) * 7);
	openTimes->hoursClose = (char**)malloc(sizeof(char*) * 7);
	for(int i = 0; i < 7; i++) {
		*(openTimes->days + i) = (char*)malloc(sizeof(char) * 200);
		*(openTimes->hoursOpen + i) = (char*)malloc(sizeof(char) * 200);
		*(openTimes->hoursClose + i) = (char*)malloc(sizeof(char) * 200);
	}
	openTimes->numDays = 0;
	return openTimes;
}

void setOpenTimes(OpenTimes* resOpen, char* daysHoursOpen) {
	int i = 0;
	char* day; //Will hold each day/hour combination (e.g. "Monday 11:00 14:00")
	day = strtok(daysHoursOpen, ",");
	//Iterates through all days provided
	while(day != NULL) {
		while(*day == ' ') { day++; } //Removes excess whitespace

		char* hours; //Will hold the hours for each day (e.g. "11:00 14:00")
		hours = strchr(day, ' '); //Creates substring of hours
		hours++;

		//Finds length of day name
		int dayLen = 0;
		while(*(day + dayLen) != ' ') {
			dayLen++;
		}

		strncpy(*(resOpen->days + i), day, dayLen);

		//Finds length of first time
		int hoursLen = 0;
		while(*(hours + hoursLen) != ' ') {
			hoursLen++;
		}
		strncpy(*(resOpen->hoursOpen + i), hours, hoursLen); //Copies first time from hours string as opening time (e.g. "11:00")
		
		hours = strchr(hours, ' '); //Finds second time in hours string
		hours++;

		//Removes \n character from last instance of hours
		if(strchr(hours, '\n') != NULL) {
			strncpy(*(resOpen->hoursClose + i), hours, strlen(hours) - 1); //Copies second time from hours string (e.g. "14:00")
		} else {
			strcpy(*(resOpen->hoursClose + i), hours);
		}
		resOpen->numDays++;

		day = strtok(NULL, ",");
		i++;
	}
}

void printRestaurant(Restaurant* res) {
	//printf("Entered printRestaurant()\n");
	char* foodTypes = linkedListToStr(res->foodTypes);
	char* cost = linkedListToStrJoined(res->cost);
	char* daysHoursOpen = openTimesToStr(res->daysHoursOpen);
	printf("Name: %s\nCity: %s\nCategories: %s\nOpen Hours: %s\nPrice: %s\nRank: %s\nReviewers: %s\n\n",
		   res->name, res->city, foodTypes, daysHoursOpen, cost, res->rank, res->numReviews);
	free(foodTypes);
	free(cost);
	free(daysHoursOpen);
}

char* openTimesToStr(OpenTimes* resOpen) {
	char* str = (char*)malloc(sizeof(char) * 200); //String to return
	for(int i = 0; i < resOpen->numDays; i++) {
		strcat(str, *(resOpen->days + i));
		strcat(str, " ");
		strcat(str, *(resOpen->hoursOpen + i));
		strcat(str, " ");
		strcat(str, *(resOpen->hoursClose + i));
		//If on last day, don't add a comma to end of string
		if(i < resOpen->numDays - 1) {
			strcat(str, ", ");
		}
	}
	return str;
}

bool checkTime(OpenTimes* resOpen, char* findTime) {
	//Create copy of given string so as to preserve passed string's integrity
	char* temp = (char*)malloc(sizeof(char) * strlen(findTime));  
	strcpy(temp, findTime);
	char* day = strtok(temp, " ");
	char* time = strtok(NULL, " ");
	//If time == NULL, the time parameter was not inputted and thus the input was invalid
	if(time == NULL) {
		return false;
	}

	for(int i = 0; i < resOpen->numDays; i++) {
		//In order, checks days are equal, res opening time is less than time, res closing time is greater than time
		//strlen() comparisons included to handle cases of strcmp considering "8:00" > "12:00"
		if(strcmp(resOpen->days[i], day) == 0
		   && (strlen(time) > strlen(resOpen->hoursOpen[i])  || strcmp(resOpen->hoursOpen[i], time) <= 0)
		   && (strlen(time) < strlen(resOpen->hoursClose[i]) || strcmp(resOpen->hoursClose[i], time) >= 0)) {
					free(temp);
					return true;
		}
	}
	free(temp);
	return false;
}

void freeRestaurant(Restaurant* res) {
	free(res->name);
	free(res->city);
	free(res->rank);
	free(res->numReviews);

	freeOpenTimes(res->daysHoursOpen);
	freeLinkedList(res->foodTypes);
	freeLinkedList(res->cost);
}

void freeOpenTimes(OpenTimes* resOpen) {
	for(int i = 0; i < resOpen->numDays; i++) {
		free(resOpen->days[i]);
		free(resOpen->hoursOpen[i]);
		free(resOpen->hoursClose[i]);
	}
	free(resOpen->days);
	free(resOpen->hoursOpen);
	free(resOpen->hoursClose);
	free(resOpen);
}

char* restaurantToStr(Restaurant *rest){
	char *restptr;
	restptr = (char *)malloc(sizeof(char)*300);
	strcat(restptr, rest->name);
	strcat(restptr, "\n");
	strcat(restptr, rest->city);
	strcat(restptr, "\n");
	strcat(restptr, linkedListToStr(rest->foodTypes));
	strcat(restptr, "\n");
	strcat(restptr, openTimesToStr(rest->daysHoursOpen));
	strcat(restptr, "\n");
	strcat(restptr, linkedListToStrJoined(rest->cost));
	strcat(restptr, "\n");
	strcat(restptr, rest->rank);
	strcat(restptr, "\n");
	strcat(restptr, rest->numReviews);
	strcat(restptr, "\n");
	return restptr;
}