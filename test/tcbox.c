/*
 * Test program for the crow(...) function.
 *
 * K. Strotz
 * 11 Oct 2018
 */

#include "tsolver.h"

int main(int argc, char** argv){

	struct box* Box = nbox();
	Box->bvalues[0][0] = 1;
	Box->bvalues[0][1] = 2;
	Box->bvalues[0][2] = 3;
	Box->bvalues[1][0] = 4;
	Box->bvalues[1][1] = 5;
	Box->bvalues[1][2] = 6;
	Box->bvalues[2][0] = 7;
	Box->bvalues[2][1] = 8;
	Box->bvalues[2][2] = 0;

	struct tbox* tBox = ntbox();
	pbox(Box);
	ptbox(tBox);

	ftbox(Box, tBox);
	ptbox(tBox);

//	tcbox(Box, tBox);
//	ptbox(tBox);

//	pBox(Box);

	free(Box);
	free(tBox);

	return 0;	
}
