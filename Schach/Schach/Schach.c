/*
PRP2-1 Aufgabe 1.2

Name: Malte Müller
Datum: 17.10.2018
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 100		//define max lenght of command string

#include <stdio.h>
#include <string.h>

// Prototypes:
void init_playground(char playground[8][8]);
void print_playground(char playground[8][8]);
void play_str(char playground[8][8], char partie_copy[MAX]);
void update_playground(int counter, char playground[8][8], char figure, char old_x, char old_y, char new_x, char new_y);
int mapping(char input);
void play_input(char playground[8][8]);

int main(void) {
	
	char partie[MAX] = "e2-e4/e7-e5/Sg1-f3/Sb8-c6/Lf1-c4/Lf8-c5/Sf3xe5/Sc6xe5/De1-e3/Lc5-e3/";	// given partie string
	char partie_copy[MAX];
	strcpy(partie_copy, partie);	// Create copy for strtok


	//Print to console:
	printf("*** Schach - Nachspielen einer Partie ***\n\n");
	printf("Folgende Parite wird gespielt:\n");
	printf("%s\n", partie);
	printf("Die Zuege sind beginnend mit weiss abwechselt notiert.\nDie weissen Figuren im Spielfeld mit Grossbuchstaben bezeichnet.\n");


	//Initialize playground array and print it to console
	char playground[8][8];
	init_playground(playground);
	print_playground(playground);

	play_str(playground, partie_copy);	// play the commands from the string 
	
	char flag = 'N';	
	printf("Wollen Sie die Partie weiterspielen? [J/N]:");
	scanf("%c", &flag);
	if(flag == 'j' || flag == 'J') play_input(playground);	// check if user wants to play further
	
	printf("\nSpiel beendet.\n");

	system("PAUSE");
	return 1;
}

// ---------------------------------------------------------------------------------------------------------------

void init_playground(char playground[8][8]) {
	/*
		Function initializes playground array:
		
	  { { 'T','S','L','K','D','L','S','T' },
		{ 'B','B','B','B','B','B','B','B' },
		{ ' ',177,' ',177,' ',177,' ',177 },
		{ 177,' ',177,' ',177,' ',177,' ' },
		{ ' ',177,' ',177,' ',177,' ',177 },
		{ 177,' ',177,' ',177,' ',177,' ' },
		{ 't','s','l','k','d','l','s','t' },
		{ 'b','b','b','b','b','b','b','b' } };
	*/
	
	playground[0][0] = 'T';
	playground[0][1] = 'S';
	playground[0][2] = 'L';
	playground[0][3] = 'K';
	playground[0][4] = 'D';
	playground[0][5] = 'L';
	playground[0][6] = 'S';
	playground[0][7] = 'T';
	
	playground[7][0] = 't';
	playground[7][1] = 's';
	playground[7][2] = 'l';
	playground[7][3] = 'k';
	playground[7][4] = 'd';
	playground[7][5] = 'l';
	playground[7][6] = 's';
	playground[7][7] = 't';

	for (int i = 0; i < 8; i++) {
		playground[1][i] = 'B';
	}

	for (int i = 0; i < 8; i++) {
		playground[6][i] = 'b';
	}


	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0)|| i % 2 == 1 && j % 2 == 1) {
				playground[i][j] = ' ';
			}
			else playground[i][j] = 177;
		}
	}
}

// ---------------------------------------------------------------------------------------------------------------

void print_playground(char playground[8][8]) {
	/*
	Function prints the playground to the console.
	*/
	
	printf("\nSpielbrett\n    |\n");
	for (int i = 7; i >= 0; i--) {
		printf("  %i | %c %c %c %c %c %c %c %c \n",i+1, playground[i][0], playground[i][1], playground[i][2], playground[i][3], playground[i][4], playground[i][5], playground[i][6], playground[i][7]);
	}
	printf("----+----------------\n    | a b c d e f g h\n\n");
}

// ---------------------------------------------------------------------------------------------------------------

void play_str(char playground[8][8], char partie_copy[MAX]) {
	/*
	Function, which handles the commands of the given string.
	*/


	char delimiter[] = "/";	// set delimiter
	char* token_ptr = strtok(partie_copy, delimiter);		// Create pointer, which points on the beginning of each word https://tech.io/playgrounds/14213/how-to-play-with-strings-in-c/string-split
	char fig = ' ';

	int counter = 1;
	int play_flag = 1;

	while (token_ptr != 0) {	// While a command is available

		system("PAUSE"); // Wait until the user presses 'return' to continue

		printf("\n%i.Zug: %s\n",counter, token_ptr);	// Print current command
		
		if (strlen(token_ptr) == 5) {	// Check the length of the command
			if (token_ptr[2] == '-') {	// differentiate if it's "Setzzug" or "Schlagzug"
				printf("Dieser Zug ist ein Setzzug:\n");
			}
			else {
				printf("Dieser Zug ist ein Schlagzug:\n");
			}
			
			if (counter % 2 == 1) fig = 'B';
			else fig = 'b';
			
			update_playground(counter, playground, fig, token_ptr[0], token_ptr[1], token_ptr[3], token_ptr[4]);	// update playground
		}
		else if (strlen(token_ptr) == 6) {
			if (token_ptr[3] == '-') {
				printf("Dieser Zug ist ein Setzzug:\n");
			}
			else {
				printf("Dieser Zug ist ein Schlagzug:\n");
			}
			if (counter % 2 == 1) fig = token_ptr[0];
			else fig = token_ptr[0] + 32;		// If counter is odd -> get small character by adding 32 to the ascii value
			
			update_playground(counter, playground, fig, token_ptr[1], token_ptr[2], token_ptr[4], token_ptr[5]);	// update playground
		}	
	
		print_playground(playground);	// Print updated playground-array to console

		token_ptr = strtok(NULL, delimiter); // reset token pointer
		counter++;	// Increase counter
	}
}

// ---------------------------------------------------------------------------------------------------------------

void update_playground(int counter, char playground[8][8], char figure, char old_x, char old_y, char new_x, char new_y) {
	/*
	Function updates the playground-array.
	*/

	playground[(int)new_y - 49][mapping(new_x)] = figure;	// Get the current figure of the start-position (-49 because Number is a character and has to be converted to int)

	if ((mapping(old_x) % 2 == 0 && ((int)old_y - 49) % 2 == 0) || (mapping(old_x) % 2 == 1 && ((int)old_y - 49) % 2 == 1)) { // check the pattern
		playground[(int)old_y - 49][mapping(old_x)] = ' ';
	}
	else playground[(int)old_y - 49][mapping(old_x)] = 177;

}

// ---------------------------------------------------------------------------------------------------------------

int mapping(char input) {
	/*
	Function maps the characters a to h to its corresponding numbers
	*/
	
	int v = 0;	// ?

	switch (input)
	{
	case 'a':
		v = 0;
		break;
	case 'b':
		v = 1;
		break;
	case 'c':
		v = 2;
		break;
	case 'd':
		v = 3;
		break;
	case 'e':
		v = 4;
		break;
	case 'f':
		v = 5;
		break;
	case 'g':
		v = 6;
		break;
	case 'h':
		v = 7;
		break;
	default:
		break;
	}
	
	return v;

}

// ---------------------------------------------------------------------------------------------------------------

void play_input(char playground[8][8]) {
	/*
	Fuction handles user input.
	*/
	char old_value[3];	// Create String of length of 3 "XX\0"
	char new_value[3];	// Create String of length of 3 "XX\0"
	int counter = 1;
	char fig;
	int x, y;

	while (1) {	// Create a loop

		printf("Beenden der Partie durch Eingabe eines 00!\n");
		printf("Eingabe Ausgangsfeld [SpalteZeile]: ");
		scanf("%s", old_value);
		
		if (old_value[0] == '0' && old_value[1] == '0') return;	// Return to main, if user inputs "00"
		
		printf("Eingabe Zielfeld [SpalteZeile]: ");
		scanf("%s", new_value);

		x = (int)old_value[1] - 49;	// Get x value by converting the character to int and substract 49 from the ascii value
		y = mapping(old_value[0]);	// Get y value by mapping the character to its number
		
		fig = playground[x][y];		//get selected figure
		
		update_playground(counter, playground, fig, old_value[0], old_value[1], new_value[0], new_value[1]); // update playground

		print_playground(playground);	// print playground

		counter++;	// Increase counter
	}

}