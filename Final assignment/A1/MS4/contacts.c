//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Date:           2019.11.07
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name) {
	char answer;
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &answer);
	if (answer == 'n' || answer == 'N') {
		printf("Please enter the contact's last name: ");
		scanf(" %35[^\n]", name->lastName);
	}
	else {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);

		printf("Please enter the contact's last name: ");
		scanf(" %35[^\n]", name->lastName);
	}
}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *address) {
	char answer;

	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);
	while (address->streetNumber <= 0)
	{
		printf("Please enter the contact's street number: ");
		scanf("%d", &address->streetNumber);
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &answer);
	if (answer == 'n' || answer == 'N') {
		printf("Please enter the contact's postal code: ");
		scanf(" 7%[^\n]", address->postalCode);
	}
	else {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);

		while (address->apartmentNumber <= 0)
		{
			printf("Please enter the contact's apartment number: ");
			scanf("%d", &address->apartmentNumber);
		}
		printf("Please enter the contact's postal code: ");
		scanf(" %7[^\n]", address->postalCode);
	}

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers) {
	char answer;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &answer);
	if (answer == 'n' || answer == 'N') {
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &answer);
	}
	else {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %10s", numbers->cell);

		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &answer);
	}

	if (answer == 'n' || answer == 'N') {
		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &answer);
	}
	else {
		printf("Please enter the contact's home phone number: ");
		scanf(" %10s", numbers->home);

		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &answer);
	}

	if (answer == 'n' || answer == 'N') {

	}
	else
	{
		printf("Please enter the contact's business phone number: ");
		scanf(" %10s", numbers->business);
	}
}

