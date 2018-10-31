/*
 * Main function for Sudoku Solver.
 * 
 * K. Strotz
 * 4 Oct 2018
 */

/* Include solver header */
#include "solver.h"

int main(int argc, char** argv){
	
	/* This program accepts no command line arguments. */
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

/* Compile-time option for a pre-filled test grid. To use compile with '-D TEST' flag in gcc. */
#ifndef TEST
	fgrid(Grid);
#else
	fgridtst(Grid);
#endif

	/* Initialize temp grid and exit if failed. */
	struct tgrid* tGrid = ntgrid();
	if (tGrid == NULL){
		fprintf(stderr, "Unable to create new temp grid.\n");
		return TPTR_FAIL;
	}

	/* Fill temp grid based on grid status. */
	ftgrid(Grid, tGrid);
	int sum = 0;
	pgrid(Grid);
//	ptgrid(tGrid);
	while (sum != 405){
//	for (int y = 0; y < 3; y++){
		for (int i = 0; i < ROWS; i++){
			crow(Grid, tGrid, i);
		}
		sum = chkgrid(Grid);
//		printf("sum: %d\n", sum);
//		pgrid(Grid);
		for (int j = 0; j < COLUMNS; j++){
			ccol(Grid, tGrid, j);
		}
		sum = chkgrid(Grid);
//		printf("sum: %d\n", sum);
//		pgrid(Grid);
		for (int m = 1; m <= 9; m++){
			cbox(Grid, tGrid, m);
		}
		sum = chkgrid(Grid);
//		printf("sum: %d\n", sum);
//		pgrid(Grid);
//		updrctgrid(Grid, tGrid);
		for (int m = 1; m <= 9; m++){
			cbox(Grid, tGrid, m);
		}
		sum = chkgrid(Grid);
//		printf("sum: %d\n", sum);
//		pgrid(Grid);
		cgrid(Grid, tGrid);
//		pgrid(Grid);
		sum = chkgrid(Grid);
//		printf("sum: %d\n", sum);
//		pgrid(Grid);
//		ptgrid(tGrid);
		updrctgrid(Grid, tGrid);
		cgrid(Grid, tGrid);
		sum = chkgrid(Grid);
//		printf("sum: %d\n", sum);
//		ptgrid(tGrid);
//	}
	}
	printf("  |   |   |   |   |   |   |   |   |");
	printf("\n \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
	printf("\n  *   *   *   *   *   *   *   *   *\n\n");
	pgrid(Grid);
	free(Grid);
	free(tGrid);
	
	return SOLVED;
}
