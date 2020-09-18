//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>

int main(void)
{
	double amount = 0.0;
	int loonies = 0, quarters = 0, remaining = 0, remaining2 = 0;


	printf("Please enter the amount to be paid: $");

	scanf("%lf", &amount);
	
	loonies = (int)amount;
	amount -= (double)loonies;
	remaining = (int)((amount * 100) + .005);
	quarters = remaining / 25;
	remaining2 = remaining - (quarters * 25);

	printf("Loonies required: %d", loonies);  
	printf(", balance owing $%.2lf\n", amount);
	printf("Quarters required: %d", quarters);
	printf(", balance owing $0.%d\n", remaining2);

	return 0;

}

