/*
 * Test program for the crow(...) function.
 *
 * K. Strotz
 * 11 Oct 2018
 */

#include "tsolver.h"

int main(int argc, char** argv){
	int row = 0;
	struct row* Row = nrow();
	for (int j = 0; j < (COLUMNS-1); j++){
		Grid->values[0][j] = (j+1);
	}
	struct trow* tRow = ntrow();
	prow(Row);

	free(Row);
	free(tRow);

	return 0;	
}
