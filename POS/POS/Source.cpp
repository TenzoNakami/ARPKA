// KINNOTORIKARA Point of Sale System
// Made with love for Bina Nusantara University's Algorithm
// Binus Festival's GSLC Assignment.
//
// ARPKA v1 - Tested at December 2nd, 2016
// +Initial setup
//
// ARPKA v2 - Tested and Released at December 3rd, 2016
// +Function Prototype (Declare function ahead of time)
// +Revised getDB, initDB, and main
// +Added pos
// +Replaced fflush() with getchar()
// -Following the latest C99 Rules where fflush() is not
// recommended anymore for the input part, removing fflush()
//
// ARPKA v3 - Tested and Released at December 11st, 2016
// +Struct (Replacing previous so called Global Variables)
// +File Handling (Replacing previous memory-consuming and buggy File Handling)
// +Revised pos and getDB
// +Added reviewCart and addCart

// Another ridiculous fact about VS2015 is most syntax that was
// available and good to go in previous VS version is broken or
// being forbidden by the VS2015 itself, thus defining this
// will force VS2015 to allow everything.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

// Please don't blame me, I'm just too lazy
// to set up Pointers here and there
int productCount = 0, init = 0;

// Please don't blame me, I'm just too lazy
// to set up Pointers here and there and
// that's the reason I used Struct.
struct theDB {
	char productName[100];
	int productPrice;
	int productStock;
	int productSelected;
} database[100];

// Thanks to Matthew for the advice on setting this up foretold.
void header();
void addCart(int selection);
void printReceipt(int totalPrice, int totalPayment);
void paymentCash(int totalPrice);
void paymentCard(int totalPrice);
void reviewCart();
void purchase();
void pos();
void addProducts();
void removeProducts();
void updateProducts();
void getDB();
void initDB();
void writeDB();
void menu();

int main() {
	initDB();

	// The program should never go back to this
	// point at all cost. Use this to check for
	// any possible memory leaks and bugs.
	printf("\n\n\tBack to main");

	writeDB();

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	main();
	return 0;
}

void header() {
	// ucode stands for Unicode which will be used to print the symbol.
	// The array consist of magic formulas.
	// The first alphabet of each row is calculated as j (0, 1, 4 ,5).
	// The middle alphabet of each row is calculated with if function and
	// therefore the result will vary.
	// The last alphabet of each row is calculated as (j + 6) which means
	// they are calculated as (6, 7, 10, 11).
	int ucode[20] = { 201, 186, 205, 32, 186, 200, 187, 186, 186, 186, 186, 188 };

	for (int j = 0; j < 6; j++) {
		// if j equals to this or j equals to that
		if (j == 0 || j == 1 || j == 4 || j == 5) {
			for (int i = 0; i < 100; i++) {
				// First alphabet
				if (i == 0) {
					printf("%c", ucode[j]);
				}
				// Last alphabet
				else if (i == 99) {
					printf("%c\n", ucode[j + 6]);
				}
				// Middle alphabet, calculated using if's as warned
				else if (j == 0 || j == 5) {
					printf("%c", ucode[2]);
				}
				// Middle alphabet, calculated using if's as warned
				else if (j == 1 || j == 4) {
					printf("%c", ucode[3]);
				}
			}
		}

		// The last two j==2 and j==3 is pretty self-explanatory
		// When it comes to third and fourth row the for loop will
		// call for this function which is just a printf.
		if (j == 2) {
			printf("%c\t\t\t\t\tKIN NO TORI KARA\t\t\t\t\t   %c\n", ucode[1], ucode[1]);
		}

		if (j == 3) {
			printf("%c\t\t\t\t      Point of Sale System\t\t\t\t\t   %c\n", ucode[1], ucode[1]);
		}
	}
}

void addCart(int selection) {
	int input;
	
	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t%s\n\n", database[selection - 1].productName);

	printf("\tEnter desired amount to buy (Equal or less than %d): ", database[selection - 1].productStock - database[selection - 1].productSelected);
	scanf("%d", &input);

	if (selection == 0) {
		addCart(selection);
	}
	else if (input == '\0') {
		addCart(selection);
	}
	else if (input > database[selection - 1].productStock - database[selection - 1].productSelected) {
		addCart(selection);
	}
	else {
		database[selection - 1].productSelected = database[selection - 1].productSelected + input;
		pos();
	}

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

// PLS DONT BLAME ME FOR THIS PART T_T
void printReceipt(int totalPrice, int totalPayment, char paymentMode[100], char cardNumber[100]) {
	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\tNUL. Receipt Printer\n\n");

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			for (int j = 0; j < 54; j++) {
				if (j == 0) {
					printf("\t%c", 201);
				}
				else if (j != 53) {
					printf("%c", 205);
				}
				else (printf("%c\n", 187));
			}
		}
		if (i == 1) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) {
					printf("\t%c", 186);
				}
				else if (j == 1) {
					printf("\t\t     KINNOTORIKARA\t\t     ");
				}
				else (printf("%c\n", 186));
			}
		}
		if (i == 2) {
			for (int j = 0; j < 54; j++) {
				if (j == 0) {
					printf("\t%c", 204);
				}
				else if (j != 53) {
					printf("%c", 205);
				}
				else (printf("%c\n", 185));
			}
		}
	}

	for (int i = 0; i < productCount; i++) {
		if (database[i].productSelected != 0) {
			printf("\t%c   %-25s x%-6d Rp. %-11d%c\n", 186, database[i].productName, database[i].productSelected, database[i].productPrice * database[i].productSelected, 186);
		}
	}
	
	// Separator
	for (int j = 0; j < 54; j++) {
		if (j == 0) {
			printf("\t%c", 204);
		}
		else if (j != 53) {
			printf("%c", 205);
		}
		else (printf("%c\n", 185));
	}

	// Total
	for (int j = 0; j < 3; j++) {
		if (j == 0) {
			printf("\t%c", 186);
		}
		else if (j == 1) {
			printf("   Total:                            Rp. %-11d", totalPrice);
		}
		else (printf("%c\n", 186));
	}

	// Bill
	if (paymentMode == "CARD") {
		// Card Number
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				printf("\t%c", 186);
			}
			else if (j == 1) {
				printf("   Card Number:                      %-15d", cardNumber);
			}
			else (printf("%c\n", 186));
		}

		// Separator
		for (int j = 0; j < 54; j++) {
			if (j == 0) {
				printf("\t%c", 204);
			}
			else if (j != 53) {
				printf("%c", 205);
			}
			else (printf("%c\n", 185));
		}

		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				printf("\t%c", 186);
			}
			else if (j == 1) {
				printf("     %-47s", "The bill has been sent to your Credit Card.");
			}
			else (printf("%c\n", 186));
		}
	}

	// Change
	if (paymentMode == "CASH") {
		// Payment
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				printf("\t%c", 186);
			}
			else if (j == 1) {
				printf("   Payment:                  %-6s  Rp. %-11d", paymentMode, totalPayment);
			}
			else (printf("%c\n", 186));
		}

		// Change
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				printf("\t%c", 186);
			}
			else if (j == 1) {
				printf("   Change:                           Rp. %-11d", totalPayment - totalPrice);
			}
			else (printf("%c\n", 186));
		}
	}

	// Separator
	for (int j = 0; j < 54; j++) {
		if (j == 0) {
			printf("\t%c", 204);
		}
		else if (j != 53) {
			printf("%c", 205);
		}
		else (printf("%c\n", 185));
	}

	for (int j = 0; j < 3; j++) {
		if (j == 0) {
			printf("\t%c", 186);
		}
		else if (j == 1) {
			printf("           %-41s", "Thank you for buying from us :)");
		}
		else (printf("%c\n", 186));
	}

	for (int j = 0; j < 54; j++) {
		if (j == 0) {
			printf("\t%c", 200);
		}
		else if (j != 53) {
			printf("%c", 205);
		}
		else (printf("%c\n", 188));
	}

	for (int i = 0; i < productCount; i++) {
		if (database[i].productSelected > 0) {
			database[i].productStock = database[i].productStock - database[i].productSelected;
			database[i].productSelected = 0;
		}
	}

	writeDB();

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void paymentCash(int totalPrice) {
	int selection;

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t103. Cash Payment\n\n");

	printf("\tTotal Price: Rp. %d\n\n\t0.    Return to POS\n\n\tInput Money: Rp. ", totalPrice);
	scanf("%d", &selection);

	// A lot of if's here and there.. I wonder why not to use switch instead.
	// I wonder if switch can check for condition's like if's ^^
	if (selection == 0) {
		pos();
	}
	else if (selection < totalPrice) {
		paymentCash(totalPrice);
	}
	else if (selection >= totalPrice) {
		printReceipt(totalPrice, selection, "CASH", 0);
	}
	else {
		paymentCash(totalPrice);
	}
}

void paymentCard(int totalPrice) {
	char selection[100];

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t104. Card Payment\n\n");

	printf("\tTotal Price: Rp. %d\n\n\t0.    Return to POS\n\n\tInput Card Number (12 digits): ", totalPrice);
	scanf("%s", &selection);

	// A lot of if's here and there.. I wonder why not to use switch instead.
	// I wonder if switch can check for condition's like if's ^^
	if (selection == 0) {
		pos();
	}
	else if (strlen(selection) == 12) {
		printReceipt(totalPrice, 0, "CARD", selection);
	}
	else {
		paymentCard(totalPrice);
	}
}

void reviewCart() {
	int selection;

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t101. Shopping Cart\n\n");

	printf("\t%-5s %-25s %-15s %-10s %-10s %s\n", "No.", "Product Name", "Price", "Stock", "Selected", "Total Price");

	// Pretty self-explanatory, baka.
	int j = 1, k = 0;
	for (int i = 0; i < productCount; i++) {
		if (database[i].productSelected != 0) {
			char si[10];
			snprintf(si, sizeof(si), "%d.", j);
			printf("\t%-5s %-25s Rp. %-11d %-10d %-10d Rp. %d\n", si, database[i].productName, database[i].productPrice, database[i].productStock, database[i].productSelected, database[i].productSelected * database[i].productPrice);
			k = k + (database[i].productSelected * database[i].productPrice);
			j++;
		}
	}
	if (k == 0) {
		printf("\n%60s\n", "YOUR SHOPPING CART IS EMPTY");
		printf("\n\n\tPress enter to continue..");
		while (getchar() != '\n');
		getchar();
		pos();
	}
	else {
		printf("\n\n\tTotal Price: Rp. %d\n\n\t0.    Return to POS\n\t102.  Purchase selected items\n\n\tEnter menu selection: ", k);

	}
	scanf("%d", &selection);

	// A lot of if's here and there.. I wonder why not to use switch instead.
	// I wonder if switch can check for condition's like if's ^^
	if (selection == 0) {
		pos();
	}
	else if (selection == 102) {
		purchase();
	}
	else {
		reviewCart();
	}

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void purchase() {
	int selection;

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t102. Checkout Shopping Cart\n\n");

	printf("\t%-5s %-25s %-15s %-10s %-10s %s\n", "No.", "Product Name", "Price", "Stock", "Selected", "Total Price");

	// Pretty self-explanatory, baka.
	int j = 1, k = 0;
	for (int i = 0; i < productCount; i++) {
		if (database[i].productSelected != 0) {
			char si[10];
			snprintf(si, sizeof(si), "%d.", j);
			printf("\t%-5s %-25s Rp. %-11d %-10d %-10d Rp. %d\n", si, database[i].productName, database[i].productPrice, database[i].productStock, database[i].productSelected, database[i].productSelected * database[i].productPrice);
			k = k + (database[i].productSelected * database[i].productPrice);
			j++;
		}
	}
	if (k == 0) {
		printf("\n%60s\n", "YOUR SHOPPING CART IS EMPTY");
		printf("\n\n\tPress enter to continue..");
		while (getchar() != '\n');
		getchar();
		pos();
	}
	else {
		printf("\n\n\tTotal Price: Rp. %d\n\n\t0.    Return to POS\n\t103.  Pay by Cash\n\t104.  Pay by Debit or Credit Card\n\n\tEnter menu selection: ", k);
		
	}
	scanf("%d", &selection);

	// A lot of if's here and there.. I wonder why not to use switch instead.
	// I wonder if switch can check for condition's like if's ^^
	if (selection == 0) {
		pos();
	}
	else if (selection == 103) {
		paymentCash(k);
	}
	else if (selection == 104) {
		paymentCard(k);
	}
	else {
		purchase();
	}

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void pos() {
	int selection;

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t1. POS Menu\n\n");

	printf("\t%-5s %-25s %-15s %-10s %-10s %s\n", "No.", "Product Name", "Price", "Stock", "Selected", "Total Price");
	
	// Pretty self-explanatory, baka.
	for (int i = 0; i < productCount; i++) {
		char si[10];
		snprintf(si, sizeof(si), "%d.", i + 1);
		printf("\t%-5s %-25s Rp. %-11d %-10d %-10d Rp. %d\n", si, database[i].productName, database[i].productPrice, database[i].productStock, database[i].productSelected, database[i].productSelected * database[i].productPrice);
	}

	printf("\n\n\t0.    Return to Menu\n\t101.  Shopping Cart\n\t102.  Purchase selected items\n\n\tEnter product number to select: ");
	scanf("%d", &selection);

	// A lot of if's here and there.. I wonder why not to use switch instead.
	// I wonder if switch can check for condition's like if's ^^
	if (selection == 0) {
		menu();
	}
	else if (selection == 101) {
		reviewCart();
	}
	else if (selection == 102) {
		purchase();
	} // This part checks if the selected products is valid or not.
	else if (database[selection - 1].productName == '\0') {
		pos();
	} // This part checks if the selected products is still in stock.
	else if ((database[selection - 1].productStock - database[selection - 1].productSelected) <= 0) {
		pos();
	}
	else {
		addCart(selection);
	}

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void addProducts() {
	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t2. Add Products\n\n\tInput Product Name: ");
	scanf(" %[^\n]", database[productCount].productName);
	printf("\n\n\tInput Product Price: ");
	scanf("%d", &database[productCount].productPrice);
	printf("\n\n\tInput Product Stock: ");
	scanf("%d", &database[productCount].productStock);
	productCount++;
	printf("\n\n\tProduct Name: %s\n\tProduct Price: %d\n\tProduct Stock: %d\n\n\tYour product has been added.\n\tPress enter to continue..", database[productCount - 1].productName, database[productCount - 1].productPrice, database[productCount - 1].productStock);

	writeDB();

	// In VS2015 each end of function need to have getchar();
	// or it will break, which seems ridiculous.
	while (getchar() != '\n');
	getchar();
	menu();
}

void removeProducts() {
	char temp2[100];
	int selection;

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t5. Remove Products\n\n");

	printf("\t%-5s %-25s %-15s %s\n", "No.", "Product Name", "Price", "Stock");

	// Pretty self-explanatory, baka.
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < productCount; i++) {
		char si[10];
		snprintf(si, sizeof(si), "%d.", i + 1);
		printf("\t%-5s %-25s Rp. %-11d %d\n", si, database[i].productName, database[i].productPrice, database[i].productStock);
		x = x + database[i].productStock;
		y++;
		z = z + (database[i].productStock * database[i].productPrice);
	}

	printf("\n\n\tInput product number to be removed: ");
	scanf("%d", &selection);

	if (database[(selection - 1)].productName == 0) {
		removeProducts();
	}
	else if (database[selection - 1].productName != 0) {
		strcpy(temp2, database[selection - 1].productName);
		for (int i = selection - 1; i < productCount; i++) {
			char temp[100];
			int a, b;
			strcpy(temp, database[i + 1].productName);
			a = database[i + 1].productPrice;
			b = database[i + 1].productStock;
			strcpy(database[i].productName, temp);
			database[i].productPrice = a;
			database[i].productStock = b;
		}
		productCount--;
	}

	printf("\n\n\t%s has been successfully removed from the Database.\n\tPress enter to continue..", temp2);

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void updateProducts() {
	int selection;

	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t6. Update Products\n\n");

	printf("\t%-5s %-25s %-15s %s\n", "No.", "Product Name", "Price", "Stock");

	// Pretty self-explanatory, baka.
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < productCount; i++) {
		char si[10];
		snprintf(si, sizeof(si), "%d.", i + 1);
		printf("\t%-5s %-25s Rp. %-11d %d\n", si, database[i].productName, database[i].productPrice, database[i].productStock);
		x = x + database[i].productStock;
		y++;
		z = z + (database[i].productStock * database[i].productPrice);
	}

	printf("\n\n\tInput product number to be altered: ");
	scanf("%d", &selection);

	if (database[(selection - 1)].productName == 0) {
		removeProducts();
	}
	else if (database[selection - 1].productName != 0) {
		int selection2;
		printf("\n\n\t1. Alter Product Name\n\t2. Alter Product Price\n\t3. Alter Product Stock\n\tInput: ");
		scanf("%d", &selection2);
		if (selection2 == 1) {
			printf("\n\n\tPlease enter new product name (was %s): ", database[selection - 1].productName); scanf(" %[^\n]", database[selection - 1].productName);
		}
		else if (selection2 == 2) {
			printf("\n\n\tPlease enter new product price (was %d): ", database[selection - 1].productPrice); scanf("%d", &database[selection - 1].productPrice);
		}
		else if (selection2 == 3) {
			printf("\n\n\tPlease enter new product stock (was %d): ", database[selection - 1].productStock); scanf("%d", &database[selection - 1].productStock);
		}
		else updateProducts();
	}

	printf("\n\n\tPress enter to continue..");

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void getDB() {
	// To ensure the design is uniform and tidy,
	// we always call this function along with
	// the header() to make the header part.
	system("CLS");
	header();
	printf("\n\t4. Database List\n\n");

	printf("\t%-5s %-25s %-15s %s\n", "No.", "Product Name", "Price", "Stock");

	// Pretty self-explanatory, baka.
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < productCount; i++) {
		char si[10];
		snprintf(si, sizeof(si), "%d.", i + 1);
		printf("\t%-5s %-25s Rp. %-11d %d\n", si, database[i].productName, database[i].productPrice, database[i].productStock);
		x = x + database[i].productStock;
		y++;
		z = z + (database[i].productStock * database[i].productPrice);
	}

	printf("\n\n\tTotal Item Stocks:\t%d\n\tTotal Unique Items:\t%d\n\tTotal Net Worth:\tRp. %d\n\n\tPress enter to continue..", x, y, z);

	// I don't know why, but VS2015 really sucks
	// that it don't even take fflush(stdin)
	// anymore. Yeah, it sucks.
	while (getchar() != '\n');
	getchar();
	menu();
}

void initDB() {
	// For the sake of Visual Design. Yes.
	// 100% Eye-candy. Useless piece of shit.
	// Remove at will. No harm intended.
	if (init == 0) {
		for (int b = 0; b < 100; b++) {
			system("CLS");

			printf("\n\n\t");

			for (int c = 0; c < b; c++) {
				printf("*");
			}

			printf("\n\n");

			if (b < 50) {
				printf("%60s", "INITIALIZING CODE");
				Sleep(20);
			}
			else if (b < 80) {
				printf("%60s", "INITIALIZING DATABASE");
				Sleep(100);
			}
			else if (b < 100) {
				printf("%60s", "TIDYING UP");
				Sleep(100);
			}
		}
	}
	if (init == 1) {
		for (int b = 0; b < 100; b++) {
			system("CLS");

			printf("\n\n\t");

			for (int c = 0; c < b; c++) {
				printf("*");
			}

			printf("\n\n");

			if (b < 40) {
				printf("%60s", "CLEANING UP");
				Sleep(100);
			}
			else if (b < 70) {
				printf("%60s", "RE-INITIALIZING DATABASE");
				Sleep(20);
			}
			else if (b < 100) {
				printf("%60s", "TIDYING UP");
				Sleep(100);
			}
		}
	}

	// Preventing memory leak from the first DB,
	// since they always happen in the first
	// revisions of the program. This function set
	// the productName and productPrice char array
	// back to NULL along with the productCount
	// therefore it is to be called as re-initialize.
	memset(&database, 0, sizeof(database));
	productCount = 0;

	// This part is all about file handling.
	FILE *pp = fopen("products.dat", "ab+");
	// Set the file pointer to 0, they mostly stay
	// on the last word you scanned if not reset.
	fseek(pp, 0, SEEK_CUR);
	while (!feof(pp)) {
		fscanf(pp, "%[^|]|%d|%d\n", database[productCount].productName, &database[productCount].productPrice, &database[productCount].productStock);
		productCount++;
	}
	// Don't forget to close the file after use ^^
	fclose(pp);

	init = 1;
	menu();
}

void writeDB() {
	// This part is all about file handling.
	FILE *pp = fopen("products.dat", "w");
	// Set the file pointer to 0, they mostly stay
	// on the last word you scanned if not reset.
	fseek(pp, 0, SEEK_CUR);
	for (int i = 0; i < productCount; i++) {
		fprintf(pp, "%s|%d|%d\n", database[i].productName, database[i].productPrice, database[i].productStock);
	}

	// Don't forget to close the file after use ^^
	fclose(pp);

	return;
}

void menu() {
	// Erase the screen, leaving it blank.
	system("CLS");
	// It seems like switch only works with char type variable.
	char selection;
	// Calls the header function.
	header();

	// The art is the menu itself.
	printf("\n\n\t1. Point of Sale\n\t2. Add Products\n\t3. Remove Products\n\t4. Update Products\n\t5. Database List\n\t6. Reinitialize DB\n\t9. Exit Program\n\n\n\tInput: ");
	scanf("%c", &selection);

	// The main part, check what is the user input.
	switch (selection) {
	case '0': break;
	case '1': pos(); break;
	case '2': addProducts();  break;
	case '3': removeProducts();  break;
	case '4': updateProducts();  break;
	case '5': getDB();  break;
	case '6': initDB(); break;
	case '9': writeDB(); exit(0);
	default: menu();
	}

	writeDB();

	// In VS2015 each end of function need to have getchar();
	// or it will break, which seems ridiculous.
	while (getchar() != '\n');
	getchar();
}