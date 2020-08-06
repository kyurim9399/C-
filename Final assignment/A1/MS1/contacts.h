//==============================================
// Name:           kyurim kim
// Student Number: 168819183
// Email:          kkim125@myseneca.ca
// Section:        NQQ
// Date:           2019.10.29
//==============================================
// Assignment:     1
// Milestone:      1
//==============================================

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...

struct Address
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCod[8];
	char city[41];
};


// Structure type Numbers declaration
// Place your code here...

struct Numbers
{
	char cell[11];
	char home[11];
	char business[11];
};