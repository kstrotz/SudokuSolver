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

	/* Initialize grid and exit if failed. */
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


	/* Set intial sum to zero to ensure one loop runs */
	int sum = 0;
	int prvsum = 0;
	int guess = 0;
	struct grid* holdGrid = NULL;
	struct grid* tmpGrid = NULL;

	/* Initialize temp grid and exit if failed. */
	struct tgrid* tGrid = ntgrid();
	if (tGrid == NULL){
		fprintf(stderr, "Unable to create new temp grid.\n");
		return TPTR_FAIL;
	}

	/* Fill temp grid based on grid status and print grid. */
	ftgrid(Grid, tGrid);
	pgrid(Grid);

	/* Begin central loop */	
	while (sum != 405){
	
		/* Reset prvsum */	
		prvsum = sum;

		/* Update tGrid based on new grid status */
		updrctgrid(Grid, tGrid);
		for (int n = 1; n <= 9; n++){
			updbtgrid(Grid, tGrid, n);
		}

		/* Check each row */
		for (int i = 0; i < ROWS; i++){
			crow(Grid, tGrid, i);
		}

		/* Check each column */
		for (int j = 0; j < COLUMNS; j++){
			ccol(Grid, tGrid, j);
		}

		/* Check each box */
		for (int m = 1; m <= 9; m++){
			cbox(Grid, tGrid, m);
		}
		
		/* Check grid for single options */
		cgrid(Grid, tGrid);

		/* Calculate grid sum for comparison */
		sum = chkgrid(Grid);

		/* Check for lack of progress */
		if (sum == prvsum){
			if(!guess){
				holdGrid = Grid;
				tmpGrid = ngrid();
				for (int i = 0; i < ROWS; i++){
					for (int j = 0; j < COLUMNS; j++){
						tmpGrid->values[i][j] = Grid->values[i][j];
					}
				}
				guess = 1;
				frstguess(tmpGrid, tGrid);
				Grid = tmpGrid;
			} else {
				Grid = holdGrid;
				fprintf(stderr, "[  FAILED  ] No progress found!\n");
				fprintf(stderr, "This puzzle may require guessing.\n\n");
				break;
			}
		}
	}

	/* Print arrows and solved grid */
	printf("  |   |   |   |   |   |   |   |   |");
	printf("\n \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /");
	printf("\n  *   *   *   *   *   *   *   *   *\n\n");
	pgrid(Grid);

	/* Free grid and temporary grid */
	free(tmpGrid);
	free(holdGrid);
	free(tGrid);
	Grid = NULL;

	/* Return 0 */	
	return SOLVED;
}
