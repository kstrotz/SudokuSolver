/*
 * Main function for Sudoku Solver.
 * 
 * K. Strotz
 * 4 Oct 2018
 */

#include "solver.h"

int main(int argc, char** argv){
	
	// This program accepts no command line arguments.
	if (argc > 1){
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return INV_ARGS;
	}

	// Initialize grid and exit if failed.
	struct grid* Grid = ngrid();
	if (Grid == NULL){
		fprintf(stderr, "Unable to create new grid.\n");
		return GPTR_FAIL;
	}

// Compile-time option for a pre-filled test grid.
#ifndef TEST
	fgrid(Grid);
#else
	fgridtst(Grid);
#endif

	// Initialize temp grid and exit if failed.
	struct tgrid* tGrid = ntgrid();
	if (tGrid == NULL){
		fprintf(stderr, "Unable to create new temp grid.\n");
		return TPTR_FAIL;
	}

	// Fill temp grid based on grid status.
	ftgrid(Grid, tGrid);
	int sum = 0;
	while (sum != 405){
		for (int i = 0; i < ROWS; i++){
			crow(Grid, tGrid, i);
		}
		for (int j = 0; j < COLUMNS; j++){
			ccol(Grid, tGrid, j);
		}
		for (int m = 1; m <= 9; m++){
			cbox(Grid, tGrid, m);
		}
		sum = chkgrid(Grid);
		printf("sum: %d\n", sum);
		pgrid(Grid);
	}
	pgrid(Grid);
	free(Grid);
	free(tGrid);
	
	return SOLVED;
}
