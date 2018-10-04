/*
 * Header file for the Sudoku Solver.
 * 
 * K. Strotz
 * 4 Oct 2018
 */

#ifndef SOLVER_H
#define SOLVER_H

#define ROWS 9
#define COLUMNS 9
#define OPTIONS 9

#include <stdio.h>
#include <stdlib.h>

struct grid {
	int status;
	int values[ROWS][COLUMNS];
};

grid* nGrid(void);
void cRow(struct grid* Grid);
void cCol(struct grid* Grid);
void cBox(struct grid* Grid);
void pGrid(const struct grid* Grid);
void dGrid(struct grid Grid);

#endif


