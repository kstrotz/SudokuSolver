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

struct tgrid {
	int tstatus;
	int tvalues[ROWS][COLUMNS][OPTIONS];
};

struct grid* ngrid(void);
struct tgrid* ntgrid(void);
void fgrid(struct grid* Grid);
void ftgrid(const struct grid* Grid, struct tgrid* tGrid);
void crow(struct grid* Grid);
void ccol(struct grid* Grid);
void cbox(struct grid* Grid);
void pgrid(const struct grid* Grid);
void dgrid(struct grid* Grid);
void dtgrid(struct tgrid* tGrid);
void ptgrid(const struct tgrid* tGrid);

#endif


