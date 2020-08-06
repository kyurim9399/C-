//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Date:           2019.11.19
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"



// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name* name) {
	int answer;
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	answer = yes();
	if (answer == 0)
	{
		printf("Please enter the contact's last name: ");
		scanf(" %35[^\n]", name->lastName);
		clearKeyboard();
	}
	else
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearKeyboard();

		printf("Please enter the contact's last name: ");
		scanf(" %35[^\n]", name->lastName);
		clearKeyboard();
	}
}


// getAddress:
void getAddress(struct Address* address) {
	int answer;
	int streetNum;
	int apartmentNum;

	printf("Please enter the contact's street number: ");
	do {
		streetNum = getInt();
		if (streetNum <= 0) {
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
	} while (streetNum <= 0);

	address->streetNumber = streetNum;

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	answer = yes();
	if (answer == 0)
	{
		printf("Please enter the contact's postal code: ");
		scanf(" 7%[^\n]", address->postalCode);
		clearKeyboard();
	}
	else
	{
		printf("Please enter the contact's apartment number: ");
		do {
			apartmentNum = getInt();

			if (apartmentNum <= 0) {
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			}
		} while (apartmentNum <= 0);
		address->apartmentNumber = apartmentNum;

		printf("Please enter the contact's postal code: ");
		scanf(" %7[^\n]", address->postalCode);
		clearKeyboard();
	}

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();
}



// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers* numbers) {
	int answer;
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	clearKeyboard();

	printf("Do you want to enter a home phone number? (y or n): ");
	answer = yes();
	if (answer == 0) {
		printf("Do you want to enter a business phone number? (y or n): ");
		answer = yes();
	}
	else {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		clearKeyboard();

		printf("Do you want to enter a business phone number? (y or n): ");
		answer = yes();
	}

	if (answer == 0) {

	}
	else
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
		clearKeyboard();
	}

}


// getContact
void getContact(struct Contact* contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
