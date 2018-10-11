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
				tGrid->tvalues[i][j][k] = 0;
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

void fgrid(struct grid* Grid){
	printf("Filling the grid...\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			printf("Enter [%d][%d]: ", (i+1), (j+1));
			scanf("%d", &(Grid->values[i][j]));
			if (Grid->values[i][j] < 0 || Grid->values[i][j] > 9){
				fprintf(stderr, "[ ERROR ] Invalid numeric entry.\n");
			}
		}
	}
}

void fgridtst(struct grid* Grid){
	printf("Filling the grid...\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			Grid->values[i][j] = (i+1);
		}
	}
}

void ftgrid(const struct grid* Grid, struct tgrid* tGrid){
	printf("Populating temporary grid...");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			if (Grid->values[i][j] == 0){
				for (int k = 0; k < OPTIONS; k++){
					tGrid->tvalues[i][j][k] = 1;
				}
			} else {
				tGrid->tvalues[i][j][(Grid->values[i][j]-1)] = 1;
			}
		}
	}
	printf("DONE.\n");
}

void crow(struct grid* Grid, struct tgrid* tGrid, int row){
	for (int j = 0; j < COLUMNS; j++){
		if (Grid->values[row][j] != 0){
			for (int tj = 0; tj < COLUMNS; tj++){
				tGrid->tvalues[row][tj][((Grid->values[row][j])-1)] = 0;
			}
			tGrid->tvalues[row][j][((Grid->values[row][j])-1)] = 1;
		}
	}
}

