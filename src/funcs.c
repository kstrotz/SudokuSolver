/*
 * Functions for Sudoku Solver.
 *
 * K. Strotz
 * 4 Oct 2018
 */

#include "solver.h"

struct grid* nGrid(void){
	struct grid* Grid = (struct grid*) malloc(sizeof(struct grid));
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			Grid->values[i][j] = 0;
		}
	}
	return Grid;
}

void pGrid(const struct grid* Grid){
	printf("+---+---+---+---+---+---+---+---+---+\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			printf("| %d ", Grid->values[i][j]);
			}
		printf("|\n");
		printf("+---+---+---+---+---+---+---+---+---+\n");
	}
}

