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

// Basic error message function
void error(string message) {
	cout << endl << " :> ERROR : " << message << endl;
}


int strCounter = 0, numCounter = 0;

void showStats() {
		cout
		<< endl << "---------------------------------------------------" << endl << endl
		<< " :> Numbers Counter : " << numCounter
		<< " | String Counter : " << strCounter 
		<< endl << endl << "---------------------------------------------------" << endl;
}

// main of program
void main(int argc , char *argv[]) {
	FILE *fp = NULL;
	// Return values come here
	union semantic_info sem;

	// Open file and check for validation
	if ( (fopen_s(&fp, argv[1], "r"))) { error("Opening of file"); exit(1); }

	int tokentype = 0;

	// While the are fiel data left
	while ((tokentype = yylex(fp, &sem)) != 0) {
		// If is string
		if (tokentype == 1) {
			// Action 1
			strCounter++;
			printf("\n :> String : %s\n" , sem.s);
		}

		// If is number
		else if (tokentype == 2) {
			// Action 2
			numCounter++;
			cout << "\n :> Number : " << (sem.i) << endl;
		}
	}

	showStats();
	
	// Close file
	fclose(fp);

}