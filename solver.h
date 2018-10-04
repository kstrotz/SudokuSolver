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
	int values[9][9];
};

grid* nGrid(void);
void cRow(void);
void cCol(void);
void cBox(void);
void pGrid(void);
void dGrid(void);

#endif


