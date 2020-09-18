//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        Fall is here
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include<stdio.h>

#define NUMS 3

int main(void)
{
	printf("---=== IPC Temperature Analyzer ===---\n");

	int i = 0, low, high;

	for (i=0 ; i < NUMS; i++)
	{
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &high);

		printf("\nEnter the low value for day %d: ", i + 1);
		scanf("%d", &low);

		printf("\n");

		while (low <= -41 || high >= 41 || low > high)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &low);

			printf("\n");
		}


	}

	return 0;
}