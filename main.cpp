#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int yylex(FILE* fpointer, union semantic_info* sem);

extern union semantic_info {
	char* s;
	int i;
} SEMANTIC_INFO;

// main of program
void main() {
	FILE *fp = NULL;
	// Return values come here
	union semantic_info sem;

	// Open file
	fopen_s(&fp, "data.txt", "r");

	int tokentype = 0;


	while ((tokentype = yylex(fp, &sem)) != 0) {
		if (tokentype == 1) {
			// Action 1
		}

		else if (tokentype == 2) {
			// Action 2
		}
	}






}