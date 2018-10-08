/*
 * Functions for Sudoku Solver.
 *
 * K. Strotz
 * 4 Oct 2018
 */

#include "solver.h"

struct grid* ngrid(void){
	struct grid* Grid = (struct grid*) malloc(sizeof(struct grid));
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			Grid->values[i][j] = 0;
		}
	}
	return Grid;
}

struct tgrid* ntgrid(void){
	struct tgrid* tGrid = (struct tgrid*) malloc(sizeof(struct tgrid));
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			for (int k = 0; k < OPTIONS; k++){
				tGrid->tvalues[i][j][k] = 1;
			}
		}
	}
	return tGrid;
}

void pgrid(const struct grid* Grid){
	printf("+---+---+---+---+---+---+---+---+---+\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			printf("| %d ", Grid->values[i][j]);
		}
		printf("|\n");
		printf("+---+---+---+---+---+---+---+---+---+\n");
	}
}

void ptgrid(const struct tgrid* tGrid){
	printf("Displaying grid status: \n\n");
	for (int k = 0; k < OPTIONS; k++){
		printf("Layer %d:\n", k+1);
		printf("+---+---+---+---+---+---+---+---+---+\n");
		for (int i = 0; i < ROWS; i++){
			for (int j = 0; j < COLUMNS; j++){
				printf("| %d ", tGrid->tvalues[i][j][k]);
			}
			printf("|\n");
			printf("+---+---+---+---+---+---+---+---+---+\n");
		}
		printf("\n");
	}
}

