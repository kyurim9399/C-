//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include<stdio.h>

int main(void)
{
	double amount = 0.0, GST = 0.0, total = 0.0;
	int loonies = 0, quarters = 0, remaining = 0, dimes = 0, nickels = 0,
		remaining25 = 0, remaining10 = 0, remaining5 = 0, remaining1 = 0;


	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	GST = amount * .13 + .005;
	total = amount + GST;
	loonies = (int)total;
	amount = total - (double)loonies;
	remaining = (int)((amount * 100) + .005);
	quarters = remaining / 25;
	remaining25 = remaining % 25;
	dimes = remaining25 / 10;
	remaining10 = remaining25 % 10;
	nickels = remaining10 / 5;
	remaining5 = remaining10 % 5;
	remaining1 = remaining5 % 1;




	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", total);
	printf("Loonies required: %d", loonies);
	printf(", balance owing $%.2lf\n", amount);
	printf("Quarters required: %d", quarters);
	printf(", balance owing $%1.2f\n", (float)remaining25 / 100);
	printf("Dimes required: %d, ", dimes);
	printf("balance owing $%1.2f\n", (float)remaining10 / 100);
	printf("Nickels required: %d, ", nickels);
	printf("balance owing $%1.2f\n", (float)remaining5 / 100);
	printf("Pennies required: %d, ", remaining5);
	printf("balance owing $%1.2f\n", (float)remaining1 / 100);

	return 0;

}