//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Date:           2019.11.21
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>
#include <ctype.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int Value;
	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &Value, &NL);
		}
	}
	return Value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int Value = getInt();
	while (Value < min || Value > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}

	return Value;
}

// yes:
int yes(void)
{
	int Value = 0;
	char answer;
	char nl = 'x';
	int roop = 0;

	while (nl != '\n' || roop != 0)
	{
		scanf(" %c%c", &answer, &nl);
		if (nl != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else
		{
			switch (answer)
			{
			case 'Y':
			case 'y':
				Value = 1;
				roop = 0;
				break;
			case 'N':
			case 'n':
				Value = 0;
				roop = 0;
				break;
			default:
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
				roop = 1;
			}
		}
	}

	return Value;
}


// menu:
int menu(void)
{
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	return option;

}

// contactManagerSystem:
void contactManagerSystem(void)
{
	int option;
	int end = 0;

	struct Contact contacts[MAXCONTACTS] = { {{ "Rick", {'\0'}, "Grimes" },
											{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
											{ "4161112222", "4162223333", "4163334444" }},

										{{ "Maggie", "R.", "Greene" },
											{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
											{ "9051112222", "9052223333", "9053334444" }},

										{{ "Morgan", "A.", "Jones" },
											{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
											{ "7051112222", "7052223333", "7053334444" }},

										{{ "Sasha", {'\0'}, "Williams" },
											{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
											{ "9052223333", "9052223333", "9054445555" } }, };



	do {
		option = menu();
		switch (option) {
		case 1:
			printf("\n");
			displayContacts(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n");
			addContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 3:
			printf("\n");
			updateContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n");
			deleteContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 5:
			printf("\n");
			searchContacts(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n");
			sortContacts(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1) {
				end = 1;
			}
			printf("\n");
			break;

		default:
			break;
		}


	} while (end != 1);
	printf("Contact Management System: terminated\n");
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i;

	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			for (i = 0; i < 10; i++)
			{
				if ((isdigit(phoneNum[i])) == 0)
				{
					printf("Enter a 10-digit phone number: ");
					needInput = 1;
					break;
				}
				else needInput = 0;
			}
		}
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	int index = -1;

	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", count);
}


// displayContact:
void displayContact(const struct Contact* contact)
{

	if (strcmp((*contact).name.middleInitial, "") == 0)
	{
		printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
	}
	else
	{
		printf(" %s %s %s\n", (*contact).name.firstName, (*contact).name.middleInitial, (*contact).name.lastName);
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business);

	if ((*contact).address.apartmentNumber > 0)
	{
		printf("       %d %s, ", (*contact).address.streetNumber, (*contact).address.street);
		printf("Apt# %d, ", (*contact).address.apartmentNumber);
		printf("%s, %s\n", (*contact).address.city, (*contact).address.postalCode);
	}
	else
	{
		printf("       %d %s, ", (*contact).address.streetNumber, (*contact).address.street);
		printf("%s, %s\n", (*contact).address.city, (*contact).address.postalCode);
	}
}


// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {

	int i;
	int count = 0;

	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char number[11];
	int index = -1;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	index = findContactIndex(contacts, size, number);

	if (index == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\n");
		displayContact(&contacts[index]);
	}
}
// addContact:
void addContact(struct Contact contacts[], int size)
{
	int available = -1;
	available = findContactIndex(contacts, size, "");

	if (available == -1)
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
	else
	{
		getContact(&contacts[available]);
		printf("--- New contact added! ---\n");
	}
}


// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char number[11];
	int index = -1;
	int answer;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	index = findContactIndex(contacts, size, number);

	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		answer = yes();

		if (answer == 1) {
			getName(&contacts[index].name);
		}
		printf("Do you want to update the address? (y or n): ");
		answer = yes();
		if (answer == 1) {
			getAddress(&contacts[index].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		answer = yes();
		if (answer == 1) {
			getNumbers(&contacts[index].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
}
// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char number[11];
	int index = -1;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	index = findContactIndex(contacts, size, number);

	if (index == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");

		if (yes())
		{
			contacts[index].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	int count = 0;
	struct Contact temp;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			count++;
		}
	}

	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0)
			{
				temp = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}