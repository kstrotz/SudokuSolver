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
	struct grid *Grid = nGrid();
	if (Grid == NULL){
		fprintf(stderr, "Unable to create new grid.\n");
		return 2;
	}
	pGrid(Grid);

/*
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			for (int k = 1; k < (COLUMNS+1); k++){
			}
		}
	}
*/

	return 0;
}
