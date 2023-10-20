#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

extern int yylex(FILE* fpointer, union semantic_info* sem);

extern union semantic_info {
	char* s;
	int i;
} SEMANTIC_INFO;

void error(const char *message) {
	cout << endl << " :> Error : " << message << endl << endl;
}

// main of program
void main() {
	FILE *fp = NULL;
	// Return values come here
	union semantic_info sem;

	// Open file and check for validation
	if ( (fopen_s(&fp, "C:/University/Compilers I/Askhsh_Ergasthriou_1/data.txt", "r")) ) { error("Opening of file"); exit(1); }

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