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
	
	// Aufgabe 1:
	eingabe(&zeichen);
	ausgabe(&zeichen);
	umwandeln(&zeichen);
	ausgabe(&zeichen);

	fseek(stdin, 0, SEEK_END);	// Puffer leeren
	
	ausgabe_v(umwandeln_v(eingabe_v(zeichen)));

	system("PAUSE");

	return 0;
}

/**************************************************************************************************
Eingabe des Buchstabens.

Parameter:
	char *ptr - poiter which points on character.
Rückgabe:
	void.
*/
void eingabe(char* ptr) {
	printf("Bitte geben Sie einen Buchstaben ein: ");
	scanf("%c", ptr);	// Abfrage des Zeichens
}

/**************************************************************************************************
Umwandeln der Kleinbuchstaben in Großbuchstaben.

Parameter:
	char *ptr - poiter which points on character.
Rückgabe:
	void.
*/
void umwandeln(char* ptr) {
	if (*ptr < 123 && *ptr > 96) {	// Falls KLeinbuchstabe -> Umwandeln in Großbuchstabe
		printf("Umwandlung des Zeichens!\n");
		*ptr = *ptr - 32;
	}	
}

/**************************************************************************************************
Ausgabe des Buchstabens.

Parameter:
	char *ptr - poiter which points on character.
Rückgabe:
	void.
*/
void ausgabe(char* ptr) {
	printf("Das Zeichen ist: %c\n", *ptr);
}

//Aufgabe 2:
/**************************************************************************************************
Eingabe des Buchstabens.

Parameter:
	char zeichen - poiter which points on character.
Rückgabe:
	char zeichen
*/
char eingabe_v(char zeichen) {
	printf("Bitte geben Sie einen Buchstaben ein: ");
	scanf("%c", &zeichen);	// Abfrage des Zeichens

	ausgabe_v(zeichen);

	return zeichen;
}

/**************************************************************************************************
Umwandeln der Kleinbuchstaben in Großbuchstaben.

Parameter:
	char zeichen - poiter which points on character.
Rückgabe:
	char zeichen
*/
char umwandeln_v(char zeichen) {
	if (zeichen < 123 && zeichen > 96) {
		printf("Umwandlung des Zeichens!\n");
		zeichen = zeichen - 32;
	}

	return zeichen;
}

/**************************************************************************************************
Ausgabe des Buchstabens.

Parameter:
	char zeichen - poiter which points on character.
Rückgabe:
	void.
*/
void ausgabe_v(char zeichen) {
	printf("Das Zeichen ist: %c\n", zeichen);	
}

