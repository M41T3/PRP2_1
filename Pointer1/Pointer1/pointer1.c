/* Testen von Zeigern */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXZEICHEN 100
int main(void)
{
	int i, *first_i_ptr, first_i;
	char feld_strptr[MAXZEICHEN] = "Hello World!";
	char *strptr = feld_strptr;
	char onechar;
	onechar = *strptr;
	first_i_ptr = &i;


	for (i = 0, first_i_ptr = &i; i < 5; i++)
	{
		printf("%c\n", *strptr);
		strptr++;
	}
	printf(" Erster Wert von i war %d! Korrekt ?\n", *first_i_ptr);
	for (i = 0, first_i = i; i < 5; i++)
	{
		printf("%c\n", onechar);
		onechar++;
	}
	printf(" Erster Wert von i war %i! Korrekt ? \n", first_i);


	//b)
	printf("i:\t\t%d\t%d\n", i, &i);
	printf("first_i:\t%d\t%d\n", first_i, &first_i);
	printf("first_i_ptr:\t%d\t%d\n", *first_i_ptr, first_i_ptr);
	printf("strptr:\t\t%s\t%i\n", strptr, strptr);
	printf("onechar:\t%c\t%d\n", onechar, &onechar);


	system("PAUSE");
	return 0;
}

/*
a) 
Ausgabe:

H
e
l
l
o
Erster Wert von i war 5! Korrekt ?
H
I
J
K
L
Erster Wert von i war 0! Korrekt ?

*/