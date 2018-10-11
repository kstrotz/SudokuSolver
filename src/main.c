/*
 * Main function for Sudoku Solver.
 * 
 * K. Strotz
 * 4 Oct 2018
 */

#include "solver.h"

int main(int argc, char **argv){
	if (argc > 1){
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return 1;
	}

	struct grid* Grid = ngrid();
	if (Grid == NULL){
		fprintf(stderr, "Unable to create new grid.\n");
		return 2;
	}

#ifndef TEST
	fgrid(Grid);
#else
	fgridtst(Grid);
#endif

	struct tgrid* tGrid = ntgrid();
	if (tGrid == NULL){
		fprintf(stderr, "Unable to create new temp grid.\n");
		return 3;
	}

	ftgrid(Grid, tGrid);

	pgrid(Grid);
	ptgrid(tGrid);
	free(Grid);
	free(tGrid);
	return 0;
}
