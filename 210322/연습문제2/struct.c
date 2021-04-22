#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 50

int mark = 0;

typedef struct AddBook {
	char name[20];
	char number[20];
	char birth[10];
	char address[100];
}Abook;

Abook book[NUM];

void info(void);
void input(void);
void delete(void);
void search(void);


int main() {

	int n;

	while (1) {
		printf("1. info 2.input 3.delete 4.search 0.exit");
		printf("\nEnter num:");
		scanf("%d", &n);

		switch (n) {
		case 1:
			info();
			break;

		case 2:
			input();
			break;
		case 3:
			delete();
			break;
		case 4:
			search();
			break;
		case 0:
			break;
		default:
			printf("Wrong number");
		}
	}

	return 0;
}

void info(void) {
	for (int i = 0; i < NUM; i++) {
		printf("%s \t %s \t %s \t %s\n", book[i].name, book[i].number, book[i].birth, book[i].address);
	}
}

void input(void) {
	if (mark == NUM) {
		printf("AddressBook is full");
		return;
	}
	else{
		printf("Enter name:");
	    gets(book[mark].name);
	    printf("Enter number:");
	    gets(book[mark].number);
	    printf("Enter birthday: ");
	    gets(book[mark].birth);
	    printf("Enter address: ");
	    gets(book[mark].address);

	    mark++;
	}
}

void delete(void) {
	int delMark;
	int delSelect;
	int check = 0;
	char delName[10];

	printf("Enter name to delete:");
	gets(delName);

	for (delMark = 0; delMark < mark; delMark++) {
		if (strcmp(delName, book[delMark].name) == 0) {
			int drive;
			check++;

			for (drive = delName; drive < (mark - 1); drive++) {
				strcpy(book[drive].name, book[drive + 1].name);
				strcpy(book[drive].birth, book[drive + 1].birth);
				strcpy(book[drive].number, book[drive + 1].number);
				strcpy(book[drive].address, book[drive + 1].address);
			}

			mark--;
		}
	}

	if (check == 0) {
		printf("Not found");
	}
	else {
		printf("deleted");
	}
	
}

void search(void) {
	int searchMark;
	int check = 0;
	int searchSelect;
	char searchName[10];

	printf("Enter name to search:");
	gets(searchName);

	for (searchMark = mark - 1; searchMark > -1; searchMark--) {
		if (strcmp(searchName, book[searchMark].name) == 0) {
			check++;
			printf("name: %s number : %s birthday : %s address : %d", book[searchMark].name, book[searchMark].number, book[searchMark].birth, book[searchMark].address);

		}
	}

	if (check == 0) {
		printf("Not found");
	}
	else {
		return;
	}
}