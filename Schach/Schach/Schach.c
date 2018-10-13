#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100

void init_playground(char playground[8][8]);
void print_playground(char playground[8][8]);
void play_str(char playground[8][8], char partie_copy[MAX]);
void update_playground(int counter, char playground[8][8], char figure, char old_x, char old_y, char new_x, char new_y);
int mapping(char input);
void play_input(char playground[8][8]);

int main(void) {
	
	char partie[MAX] = "e2-e4/e7-e5/Sg1-f3/Sb8-c6/Lf1-c4/Lf8-c5/Sf3xe5/Sc6xe5/De1-e3/Lc5-e3/";	// Partie String
	char partie_copy[MAX];
	strcpy(partie_copy, partie);	// Create copy for strtok


	//Print to console:
	printf("*** Schach - Nachspielen einer Partie ***\n\n");
	printf("Folgende Parite wird gespielt:\n");
	printf("%s\n", partie);
	printf("Die Zuege sind beginnend mit weiss abwechselt notiert.\nDie weissen Figuren im Spielfeld mit Grossbuchstaben bezeichnet.\n");


	//Initialize playground array
	char playground[8][8];
	init_playground(playground);
	print_playground(playground);

	play_str(playground, partie_copy);
	
	char flag = 'N';
	printf("Wollen Sie die Partie weiterspielen? [J/N]:");
	scanf("%c", &flag);
	if(flag == 'j' || flag == 'J') play_input(playground);
	

	system("PAUSE");
	return 1;
}

// ---------------------------------------------------------------------------------------------------------------

void init_playground(char playground[8][8]) {
	
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



	/*
	 playground[][] = { { 'T','S','L','K','D','L','S','T' },
						{ 'B','B','B','B','B','B','B','B' },
						{ ' ',177,' ',177,' ',177,' ',177 },
						{ 177,' ',177,' ',177,' ',177,' ' }, 
						{ ' ',177,' ',177,' ',177,' ',177 },
						{ 177,' ',177,' ',177,' ',177,' ' },
						{ 't','s','l','k','d','l','s','t' },
						{ 'b','b','b','b','b','b','b','b' } };
	 */
}

// ---------------------------------------------------------------------------------------------------------------

void print_playground(char playground[8][8]) {

	printf("\nSpielbrett\n    |\n");
	for (int i = 7; i >= 0; i--) {
		printf("  %i | %c %c %c %c %c %c %c %c \n",i+1, playground[i][0], playground[i][1], playground[i][2], playground[i][3], playground[i][4], playground[i][5], playground[i][6], playground[i][7]);
	}
	printf("----+----------------\n    | a b c d e f g h\n\n");
}

// ---------------------------------------------------------------------------------------------------------------

void play_str(char playground[8][8], char partie_copy[MAX]) {

	char delimiter[] = "/";	// set delimiter
	char* token_ptr = strtok(partie_copy, delimiter);		// Create pointer, which points on the beginning of each word https://tech.io/playgrounds/14213/how-to-play-with-strings-in-c/string-split

	int counter = 1;
	int play_flag = 1;

	while (token_ptr != 0) {

		system("PAUSE"); //DEBUG

		printf("%i.Zug: %s\n",counter, token_ptr);
		printf("Test: %i", strlen(token_ptr));	//DEBUG
		
		if (strlen(token_ptr) == 5) {
			if (token_ptr[2] == '-') {
				printf("Dieser Zug ist ein Setzzug:\n");
			}
			else {
				printf("Dieser Zug ist ein Schlagzug:\n");
			}
			update_playground(counter, playground, 'B', token_ptr[0], token_ptr[1], token_ptr[3], token_ptr[4]);
		}
		else if (strlen(token_ptr) == 6) {
			if (token_ptr[3] == '-') {
				printf("Dieser Zug ist ein Setzzug:\n");
			}
			else {
				printf("Dieser Zug ist ein Schlagzug:\n");
			}
			update_playground(counter, playground, token_ptr[0], token_ptr[1], token_ptr[2], token_ptr[4], token_ptr[5]);
		}

		print_playground(playground);

		token_ptr = strtok(NULL, delimiter);
		counter++;
	}
}

// ---------------------------------------------------------------------------------------------------------------

void update_playground(int counter, char playground[8][8], char figure, char old_x, char old_y, char new_x, char new_y) {

	char fig = 'F';	//To get failure

	if (figure != 'T' && figure != 'S' && figure != 'L' && figure != 'K' && figure != 'D') { // TODO: unterscheiden klein groﬂ. bug!
		if (counter % 2 == 1) fig = 'B';
		else fig = 'b';
		
	}
	else {
		if (counter % 2 == 1) fig = figure;
		else fig = figure + 56; // small character when it's the opposites turn
	}
	printf("x=%i, y=%i",  (int)new_y-49, mapping(new_x)); // DEBUG 49 because of ascii and extra -1 because it starts at 1
	playground[(int)new_y - 49][mapping(new_x)] = fig;

	if ((mapping(old_x) % 2 == 0 && ((int)old_y - 49) % 2 == 0) || (mapping(old_x) % 2 == 1 && ((int)old_y - 49) % 2 == 1)) { // check karo
		playground[(int)old_y - 49][mapping(old_x)] = ' ';
	}
	else playground[(int)old_y - 49][mapping(old_x)] = 177;

}

// ---------------------------------------------------------------------------------------------------------------

int mapping(char input) {
	int v = 22;

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
	char old_value[] = " ";
	char new_value[] = " ";
	int counter = 1;
	char fig;
	int x, y;

	while (!(old_value[0] == '0' && old_value[1] == '0')) {

		printf("Beenden der Partie durch Eingabe eines 00!\n");
		printf("Eingabe Ausgangsfeld [SpalteZeile]: ");
		scanf("%s", old_value);
		printf("\ntest: %s\n", old_value);	//DEBUG
		printf("Eingabe Zielfeld [SpalteZeile]: ");
		scanf("%s", new_value);

		x = (int)old_value[1] - 49;
		y = mapping(old_value);
		
		fig = playground[x][y];		//get selcted figure

		update_playground(counter, playground, fig, old_value[0], old_value[1], new_value[0], new_value[1]);

		print_playground(playground); 

		counter++;
	}

}