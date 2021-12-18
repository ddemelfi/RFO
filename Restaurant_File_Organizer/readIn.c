#include "readIn.h"

//RestaurantArrayList* readIn(char* fileName)
void readIn(char* fileName, BinaryTree *resListName, BinaryTree *resListCity) {
	//printf("Entered readIn()\n");

	FILE* file = fopen(fileName, "r");
	size_t length = 0;

	if(file == NULL) {
		printf("Error with file.\n");
		// NULL
		return;
	} else {
		//RestaurantArrayList* resList = createArrayList();
		Restaurant* res = initRestaurant();
		char* nextLine;
		int i = 0;
		getline(&nextLine, &length, file); //Get first line

		//Returns a NULL for falsely formatted files
		if(strlen(nextLine) <= 1) {
			// NULL
			return;
		}

		//Runs until end of fil
		while(!feof(file)) {
			if(strlen(nextLine) <= 1) {
				insertInBinaryTree(resListName, res->name, res);
				insertInBinaryTree(resListCity, res->city, res);
				//insertArrayList(resList, res);
				free(res);
				res = 0; //Fully reset res pointer
				res = initRestaurant();
				i = -1; //Skips one line of switch to deal with empty line in file
			}

			//printf("%s", nextLine);
			switch(i) {
				case 0: strncpy(res->name, nextLine, strlen(nextLine) - 1); break;       //Name
				case 1: strncpy(res->city, nextLine, strlen(nextLine) - 1); break;       //City
				case 2: parseFoodTypes(res, nextLine); break;                            //Food Categories
				case 3: setOpenTimes(res->daysHoursOpen, nextLine); break;               //Hours/Days Open
				case 4: parseCost(res, nextLine); break;                                 //Cost
				case 5: strncpy(res->rank, nextLine, strlen(nextLine) - 1); break;       //Rank
				case 6: strncpy(res->numReviews, nextLine, strlen(nextLine) - 1); break; //# Reviews
			}
			i++;

			getline(&nextLine, &length, file);
		}
		//insertArrayList(resList, res);
		insertInBinaryTree(resListName, res->name, res);
		insertInBinaryTree(resListCity, res->city, res);
		free(res);
	}
	fclose(file);
}

void parseFoodTypes(Restaurant* res, char* foodTypes) {
	//printf("Entered parseFoodTypes()\n");
	//If string has no commas, immediately insert and return
	if(strchr(foodTypes, ',') == NULL) {
		insertLinkedList(res->foodTypes, foodTypes);
		return;
	}

	char* substr;
	char* delim = ",";
	substr = strtok(foodTypes, delim);
	while(substr != NULL) {
		while(*substr == ' ') { substr++; }
		insertLinkedList(res->foodTypes, substr);
		substr = strtok(NULL, delim);
	}
}

void parseCost(Restaurant* res, char* cost) {
	//printf("Entered parseCost()\n");
	char* dollar = "$";
	for(int i = 0; i < strlen(cost) - 1; i++) {
		insertLinkedList(res->cost, dollar);
	}
}

void writeFile(char *fileName, BinaryTree *resListName, BinaryTree *resListCity){
	FILE* file = fopen(fileName, "w");
	size_t length = 0;
	if(file == NULL) {
		printf("Error with file.\n");
		// NULL
		return;
	}
	writeBinaryTree(resListName->root, file);
	fclose(file);
}