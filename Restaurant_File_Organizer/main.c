#include "main.h"

int main() {
	//String to hold command user inputs
	char* command = (char*)malloc(sizeof(char) * 200);

	BinaryTree *resListName = createBinaryTree();
	BinaryTree *resListCity = createBinaryTree();
	//RestaurantArrayList* resList = readIn("restaurants.txt");
	readIn("restaurants.txt", resListName, resListCity);
	if(resListName == NULL) {
		printf("Error opening file. You cannot print or search until a valid file is provided.\n");
	}

	printf("%s", KWHT);
    printf("Welcome to the database of Restaurants! Read in from a file, this is the restaurant interface!\n");
    printf("You can use these helpful commands to play with the restaurant database:\n");
	//Runs until user exits program
	while(runMenu(resListName, resListCity, command));
	//freeRestarants();
	printf("Exiting...\n");

	/*if(resList != NULL) {
		free(command);
		freeArrayList(resList);
	}*/
	if(resListName != NULL && resListCity != NULL){
		free(command);
		freeTree(resListName->root);
		freeTree(resListCity->root);
	}

	return 0;
}

// bool runMenu(RestaurantArrayList* resList, char* command)
bool runMenu(BinaryTree* resListName, BinaryTree* resListCity, char* command) {
	 printf("%s'p' --> prints out every restaurant.\n",KGRN);
	 printf("%s'w' --> writes the current restaurant tree to a new file.\n",KGRN);
     printf("%s's' --> searches for a restaurant with some specifications.\n",KCYN);
	 printf("%s'e' --> enumerates the restaurants with the specified name and location.\n",KCYN);
     printf("%s'a' --> adds a restaurant to the binary tree.\n",KBLU);
	 printf("%s'm' --> modifies the restaurants with the specified name and location.\n",KBLU);
	 printf("%s'r' --> removes the specified restaurant(s) from the tree.\n",KMAG);
	 printf("%s'x' --> exits the program.\n",KMAG);
     printf("%s", KNRM);

	scanf("%[^\n]", command); //Gets user input (multi-word allowed)
	while(getchar() != '\n'); //Clears input buffer
	//Cleans user input by making all letter lowercase
	for(int i = 0; i < strlen(command); i++) {
		*(command + i) = tolower(*(command + i));
	}

	//Exit
	if(strcmp(command, "exit") == 0 || strcmp(command, "x") == 0) {
		return false;
	//Print
	} else if((strcmp(command, "print") == 0 || strcmp(command, "p") == 0) && resListName != NULL) {
		BinaryTreeInOrder(resListName->root);
		//printArrayList(resList);
	//Search
	} else if((strcmp(command, "search") == 0 || strcmp(command, "s") == 0) && resListName != NULL) {
		searchRestaurant(resListName, resListCity);
	//add adds to the binary tree, not the file. Needs to write to the file to save. 
	} else if((strcmp(command, "a") == 0)){
		addRestaurant(resListName, resListCity);
	//Search for restaurant with name and Location only.
	} else if((strcmp(command, "e") == 0)){
		searchRestaurantNL(resListName, resListCity);
	//Modifies the Restaurant, with the name and location and changes everything else that is specified. 
	} else if((strcmp(command, "m") == 0)){
		modifyRestaurant(resListName, resListCity);
	//Writes the current binary tree to a new file
	} else if((strcmp(command, "w") == 0)){
		printf("Enter the File Destination:\n");
		char* qryFile = (char*)malloc(sizeof(char) * 200); //Name
		scanf("%[^\n]", qryFile);
		while(getchar() != '\n');
		writeFile(qryFile, resListName, resListCity);
	//removes a restaurant from the binary tree (not saved until it writes to the new file
	} else if((strcmp(command, "r") == 0)){
		removeRestaurant(resListName, resListCity);
	//Easter Eggs :D
	} else if(strcmp(command, "turn to page 2") == 0 || strcmp(command, "turn to page two") == 0) {
		printf("You arrive in a dark woods. Wind howls overhead. You see an long forgotten scroll on the ground.\n"
			   "On it are written the names of many mystical locations and the enticing foodstuffs within.\n"
			   "At the bottom of the page is an ancient scrawl which states:\n");
		return true;
	} else if(strcmp(command, "pesky specter moment") == 0 || strcmp(command, "code ghost") == 0 || strcmp(command, "hi fred") == 0) {
		printf(". - .\n(o o) boo!\n| O \\\n \\   \\\n  `~~~'\n");
	} else {
		printf("\nPlease enter a valid command\n");
	}

	return true;
}

void addRestaurant(BinaryTree *resListName, BinaryTree *resListCity){
	printf("To add a restaurant, please enter the following information:\n");
	printf("(Please do not leave trailing spaces)\n");
	char* qryName = (char*)malloc(sizeof(char) * 200); //Name
	printf("Name:\n");
	scanf("%[^\n]", qryName);
	while(getchar() != '\n');
	
	char* qryCity = (char*)malloc(sizeof(char) * 200); //City
	printf("City:\n");
	scanf("%[^\n]", qryCity);
	while(getchar() != '\n');

	char* qryCategory = (char*)malloc(sizeof(char) * 200); //Category
	printf("Categor(ies) (seperated by commas):\n");
	scanf("%[^\n]", qryCategory);
	while(getchar() != '\n');

	char* qryTime = (char*)malloc(sizeof(char) * 200); //Time
	printf("Hours Open (in the form: Someday 00:00 12:00, Someday 00:00 12:00, etc.) Only accepts 24-hour time:\n");
	scanf("%[^\n]", qryTime);
	while(getchar() != '\n');
	
	char* qryCost = (char*)malloc(sizeof(char) * 200); //Cost
	printf("Cost:\n");
	scanf("%[^\n]", qryCost);
	while(getchar() != '\n');
	
	char* qryRank = (char*)malloc(sizeof(char) * 200); //Rank
	printf("Rank:\n");
	scanf("%[^\n]", qryRank);
	while(getchar() != '\n');
	
	char* qryReviewers = (char*)malloc(sizeof(char) * 200); //Reviewers
	printf("Reviewers:\n");
	scanf("%[^\n]", qryReviewers);
	while(getchar() != '\n');
	
	Restaurant *rest = initRestaurant();
	strncpy(rest->name, qryName, strlen(qryName));
	strncpy(rest->city, qryCity, strlen(qryCity));
	parseFoodTypes(rest, qryCategory);
	setOpenTimes(rest->daysHoursOpen, qryTime);
	parseCost(rest, qryCost);
	strncpy(rest->rank, qryRank, strlen(qryRank));
	strncpy(rest->rank, qryReviewers, strlen(qryReviewers));
	insertInBinaryTree(resListName, rest->name, rest);
	insertInBinaryTree(resListCity, rest->city, rest);
	free(qryCategory); free(qryCity); free(qryCost); free(qryTime); free(qryName); free(qryRank); free(qryReviewers);
}

void searchRestaurant(BinaryTree *resListName, BinaryTree *resListCity){
	printf("To look for a restaurant, please enter the following information\n(To ignore a category, enter a \"*\")\n");
	char* qryCity = (char*)malloc(sizeof(char) * 200); //City
	printf("City:\n");
	scanf("%[^\n]", qryCity);
	while(getchar() != '\n');

	char* qryCategory = (char*)malloc(sizeof(char) * 200); //Category
	printf("Categor(ies) (seperated by commas, or the OR separator):\n");
	scanf("%[^\n]", qryCategory);
	while(getchar() != '\n');

	char* qryCost = (char*)malloc(sizeof(char) * 200); //Cost
	printf("Cost:\n");
	scanf("%[^\n]", qryCost);
	while(getchar() != '\n');

	char* qryTime = (char*)malloc(sizeof(char) * 200); //Time
	printf("Hour Open (in the form: Someday 00:00) Only accepts 24-hour time:\n");
	scanf("%[^\n]", qryTime);
	while(getchar() != '\n');

	//queryArrayList(resList, qryCity, qryCategory, qryCost, qryTime);
	printf("\n");
	searchNode(resListName->root, qryCity, qryCategory, qryCost, qryTime);
	free(qryCategory); free(qryCity); free(qryCost); free(qryTime);
}

void searchRestaurantNL(BinaryTree *resListName, BinaryTree *resListCity){
	printf("Type in the Name and City to find all restaurants that match them!:\n");
	char* qryName = (char*)malloc(sizeof(char) * 200); //Name
	printf("Name:\n");
	scanf("%[^\n]", qryName);
	while(getchar() != '\n');
	
	char* qryCity = (char*)malloc(sizeof(char) * 200); //City
	printf("City:\n");
	scanf("%[^\n]", qryCity);
	while(getchar() != '\n');
	
	printf("\n");
	searchNodeNL(resListName->root, qryName, qryCity);
	free(qryName); free(qryCity);
}

void modifyRestaurant(BinaryTree *resListName, BinaryTree *resListCity){
	printf("To Modify a Restaurant, search for the name and city below:\n");
	char* qryName = (char*)malloc(sizeof(char) * 200); //Name
	printf("Name:\n");
	scanf("%[^\n]", qryName);
	while(getchar() != '\n');
	
	char* qryCity = (char*)malloc(sizeof(char) * 200); //City
	printf("City:\n");
	scanf("%[^\n]", qryCity);
	while(getchar() != '\n');
	
	printf("Please Enter the Changes for the Restaurant:\n");

	char* qryCategory = (char*)malloc(sizeof(char) * 200); //Category
	printf("Categor(ies) (seperated by commas):\n");
	scanf("%[^\n]", qryCategory);
	while(getchar() != '\n');

	char* qryTime = (char*)malloc(sizeof(char) * 200); //Time
	printf("Hour Open (in the form: Someday 00:00 12:00, Someday 00:00 12:00, etc.) Only accepts 24-hour time:\n");
	scanf("%[^\n]", qryTime);
	while(getchar() != '\n');
	
	char* qryCost = (char*)malloc(sizeof(char) * 200); //Cost
	printf("Cost:\n");
	scanf("%[^\n]", qryCost);
	while(getchar() != '\n');
	
	char* qryRank = (char*)malloc(sizeof(char) * 200); //Rank
	printf("Rank:\n");
	scanf("%[^\n]", qryRank);
	while(getchar() != '\n');
	
	char* qryReviewers = (char*)malloc(sizeof(char) * 200); //Reviewers
	printf("Reviewers:\n");
	scanf("%[^\n]", qryReviewers);
	while(getchar() != '\n');
	
	Restaurant *rest = initRestaurant();
	strncpy(rest->name, qryName, strlen(qryName));
	strncpy(rest->city, qryCity, strlen(qryCity));
	parseFoodTypes(rest, qryCategory);
	setOpenTimes(rest->daysHoursOpen, qryTime);
	parseCost(rest, qryCost);
	strncpy(rest->rank, qryRank, strlen(qryRank));
	strncpy(rest->numReviews, qryReviewers, strlen(qryReviewers));
	modifyNode(resListName->root, qryName, qryCity, rest);
	free(qryCategory); free(qryCity); free(qryCost); free(qryTime); free(qryName); free(qryRank); free(qryReviewers);
}

void removeRestaurant(BinaryTree *resListName, BinaryTree *resListCity){
	printf("To Remove a Restaurant, enter the name and city below:\n");
	char* qryName = (char*)malloc(sizeof(char) * 200); //Name
	printf("Name:\n");
	scanf("%[^\n]", qryName);
	while(getchar() != '\n');
	
	char* qryCity = (char*)malloc(sizeof(char) * 200); //City
	printf("City:\n");
	scanf("%[^\n]", qryCity);
	while(getchar() != '\n');
	
	deleteNode(resListName->root, qryName, qryCity);
}