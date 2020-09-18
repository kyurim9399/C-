//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        Learn to learn
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>

int main(void)
{
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	int day, i = 0, High[10], Low[10];

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);

	printf("\n");
	
	while (day < 3 || day>10)
	{
		
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);

		printf("\n");
	}


	while (i < day)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &High[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &Low[i]);

		i++;

	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < day; i++)
	{
		printf("%-5d%-5d%d\n", i + 1, High[i], Low[i]);
	}

	return 0;

}
