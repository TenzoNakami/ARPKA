// Another ridiculous fact about VS2015 is most syntax that was
// available and good to go in previous VS version is broken or
// being forbidden by the VS2015 itself, thus defining this
// will force VS2015 to allow everything.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

char productName[100][100], productPrice[100][100];
int productCount = 0;

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

void pos() {

}

void addProducts() {
	system("CLS");
	char prodname[100], str[4][100];
	header();
	printf("\n\t2. Add Products\n\n\tInput Product Name: ");
	scanf(" %[^\n]", prodname);
	printf("%s", prodname);
}

void getDB() {
	system("CLS");
	header();
	printf("\n\t4. Database List\n\n");

	for (int i = 0; i < productCount; i++) {
		printf("\t%d. %s\t%s\n", i + 1, productName[i], productPrice[i]);
	}
}

void initDB() {
	int i = 0, j = 0;
	FILE *pp = fopen("products.dat", "ab+");
	fseek(pp, 0, SEEK_CUR);
	while (fscanf(pp, "%s", productName[i]) != EOF) {
		printf("%s", productName[i]);
		i++;
		productCount++;
	}
	fclose(pp);

	FILE *pq = fopen("prices.dat", "ab+");
	fseek(pq, 0, SEEK_CUR);
	while (fscanf(pq, "%s", productPrice[j]) != EOF) {
		printf("%s", productPrice[j]);
		j++;
	}
	fclose(pq);
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
	printf("\n\n\t1. Point of Sale\n\t2. Add Products\n\t3. Add Toppings\n\t4. Database List\n\t5. Reinitialize DB\n\n\n\tInput: ");
	scanf("%c", &selection);

	// The main part, check what is the user input.
	switch (selection) {
	case '0': break;
	case '1': pos(); break;
	case '2': addProducts();  break;
	case '3': break;
	case '4': getDB();  break;
	case '5': initDB();  break;
	default: menu();
	}

	// In VS2015 each end of function need to have getchar();
	// or it will break, which seems ridiculous.
	getchar();
	return;
}

int main() {
	initDB();
	menu();

	printf("\n\n\tBack to main");
	fflush(stdin);
	getchar();
	return 0;
}