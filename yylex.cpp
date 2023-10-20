#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

union semantic_info {
	char* s;
	int i;
} SEMANTIC_INFO;

// yylex Function gia anagnwrish lexewn
int yylex(FILE *fpointer, union semantic_info *sem ) {
	char lexeme[100] = {0};
	int index = -1;
	int state = 0;


	while ((lexeme[++index] = fgetc(fpointer)) != EOF) {
		switch (state) {
		// State 0
		case 0: {
			if (isalpha(lexeme[index])) {
				state = 1;
			}

			else if (isdigit(lexeme[index])) {
				state = 2;
			}

			break;
		}

		// State 1
		case 1: {
			if ( !isalnum(lexeme[index]) ) {
				sem -> s = lexeme;
				return state;
			}
			
			break;
		}

		// State 2
		case 2: {
			if (!isdigit(lexeme[index])) {
				sem -> i = atoi(lexeme);
				return state;
			}
			
			break;
		}

		}
	}

	return 0;
}