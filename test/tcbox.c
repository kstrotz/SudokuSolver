/*
 * Test program for the crow(...) function.
 *
 * K. Strotz
 * 11 Oct 2018
 */

#include "tsolver.h"

int main(int argc, char** argv){

	struct box* Box = nbox();
	for (int i = 0; i < (ROWS-6); i++){
		for (int j = 0; j < (COLUMNS-6); j++){
			Box->bvalues[i][j] = i*(j+1);
		}
	}

	struct tbox* tBox = ntbox();
	pbox(Box);
	ptbox(tBox);

	ftbox(Box, tBox);
	ptbox(tBox);

	tcbox(Box, tBox);
	ptbox(tBox);

	pBox(Box);

	free(Box);
	free(tBox);

	return 0;	
}
