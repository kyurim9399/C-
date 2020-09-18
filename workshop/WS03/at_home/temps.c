//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include<stdio.h>

#define NUMS 4

int main(void)
{
	printf("---=== IPC Temperature Analyzer ===---\n");

	int i = 0, low, high, highest = -41, lowest = 41, highestday = 1, lowestday = 1;
	double LOW = 0.0, HIGH = 0.0;

	for (i = 0; i < NUMS; i++)
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

		LOW += low;
		HIGH += high;

	
		while (high > highest)
		{
			highest = high;
			highestday = i + 1;
		}

		while (low < lowest)
		{
			lowest = low;
			lowestday = i + 1;
		}

	}

	printf("The average (mean) LOW temperature was: %2.2lf\n", (double)LOW / NUMS);

	printf("The average (mean) HIGH temperature was: %2.2lf\n", (double)HIGH / NUMS);

	printf("The average (mean) temperature was: %2.2lf\n", (double) (LOW+HIGH) / NUMS / 2);

	printf("The highest temperature was %d, on day %d\n", highest, highestday);

	printf("The lowest temperature was %d, on day %d\n", lowest, lowestday);

	return 0;

}
