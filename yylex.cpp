#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

union semantic_info {
	char* s;
	int i;
} SEMANTIC_INFO;

extern void error(string message);

int getNumber(union semantic_info* sem, char data[]) {
	sem -> i = atoi(data);
	return 2;
}

int getString(union semantic_info* sem, char data[]) {
	sem -> s = data;
	return 1;
}

// yylex Function gia anagnwrish lexewn
int yylex(FILE *fpointer, union semantic_info *sem ) {
	static char lexeme[100]; memset(lexeme, 0, sizeof(lexeme));
	int index = -1 , state = 0;


	while ((lexeme[++index] = fgetc(fpointer)) != EOF) {
		switch (state) {
		// State 0
		case 0: {
			// Set the right state
			if (isalpha(lexeme[index])) { state = 1; }

			else if (isdigit(lexeme[index])) { state = 2; }

			// If not digit nor alpha then overwrite this character
			else { error(std::string(" :> : '") + lexeme[index] + std::string("' : Nor alphaphetic nor number input. ") );  index--; }

			break;
		}

		// State 1
		case 1: {
			// Get the rest of the string characters then return
			if (!isalnum(lexeme[index])) {
				return getString(sem, lexeme);
			}
			
			break;
		}

		// State 2
		case 2: {
			// Get all digits then return
			if (!isdigit(lexeme[index])) {
				return getNumber(sem, lexeme);
			}
			
			break;
		}

		}
	}
	
	// If there is only 1 word in the file
	if (lexeme[0] != EOF) {
		if (state == 1) { return getString(sem, lexeme); }
		else { return getNumber(sem, lexeme); }
	}

	return 0;
}

