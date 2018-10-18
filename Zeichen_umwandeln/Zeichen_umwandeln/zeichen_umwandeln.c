/*
PRP2-1 Aufgabe 1.3

Name: Malte Müller, Fabian Liebold
Date: 18.10.2018
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//Prototypen:
void eingabe(char* ptr);
void umwandeln(char* ptr);
void ausgabe(char* ptr);

char eingabe_v(char ptr);
char umwandeln_v(char ptr);
void ausgabe_v(char ptr);

int main(void) {
	char zeichen = ' ';

	eingabe(&zeichen);	
	fseek(stdin, 0, SEEK_END);
	ausgabe_v(umwandeln_v(eingabe_v(zeichen)));

	system("PAUSE");

	return 0;
}

void eingabe(char* ptr) {
	printf("Bitte geben Sie einen Buchstaben ein: ");
	scanf("%c", ptr);	// Abfrage des Zeichens
	ausgabe(ptr);

	if (*ptr < 122 && *ptr > 96) {	// Falls KLeinbuchstabe -> Umwandeln in Großbuchstabe
		umwandeln(ptr);
	}
	else ausgabe(ptr);
}

void umwandeln(char* ptr) {
	*ptr = *ptr - 32;
	ausgabe(ptr);
}

void ausgabe(char* ptr) {
	printf("Das Zeichen ist: %c\n", *ptr);
	if (*ptr < 122 && *ptr > 96) {
		printf("Umwandlung des Zeichens!\n");
	}
}

char eingabe_v(char ptr) {
	printf("Bitte geben Sie einen Buchstaben ein: ");
	scanf("%c", &ptr);	// Abfrage des Zeichens

	ausgabe_v(ptr);

	return ptr;
}

char umwandeln_v(char ptr) {
	if (ptr < 122 && ptr > 96) {
		printf("Umwandlung des Zeichens!\n");
		ptr = ptr - 32;
	}

	return ptr;
}

void ausgabe_v(char ptr) {
	printf("Das Zeichen ist: %c\n", ptr);	
}

