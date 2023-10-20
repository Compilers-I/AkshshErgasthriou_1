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
	int index = 0;
	int state = 0;


	while ((lexeme[index] = fgetc(fpointer)) != EOF) {
		switch (state) {
		// State 0
		case 0: {
			if (isalpha(lexeme[index])) {

			}

			else if (isdigit(lexeme[index])) {

			}

			else {

			}

			break;
		}

		// State 1
		case 1: {

			break;
		}

		// State 2
		case 2: {

			break;
		}

		}
	}

	return 1;
}