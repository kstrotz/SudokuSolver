/*
 * Test program for the crow(...) function.
 *
 * K. Strotz
 * 11 Oct 2018
 */

#include "../src/solver.h"

int main(int argc, char** argv){
	int row = 0;
	struct grid* Grid = ngrid();
	for (int j = 0; j < (COLUMNS-1); j++){
		Grid->values[0][j] = (j+1);
	}
	struct tgrid* tGrid = ntgrid();
	ftgrid(Grid, tGrid);
	pgrid(Grid);
	crow(Grid, tGrid, row);
	pgrid(Grid);

	return 0;	
}
