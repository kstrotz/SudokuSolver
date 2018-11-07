/*
 * Header file for the Sudoku Solver.
 * 
 * K. Strotz
 * 4 Oct 2018
 */

/* Header guard */
#ifndef SOLVER_H
#define SOLVER_H

/* Define for ease of reading code */
#define ROWS 9
#define COLUMNS 9
#define OPTIONS 9

/* Include necessary headers */
#include <stdio.h>
#include <stdlib.h>

/* Set possible return values */
enum results {
	SOLVED,
	INV_ARGS,
	GPTR_FAIL,
	TPTR_FAIL,
	NO_PROG
};

/* Set grid and temporary grid structures */
struct grid {
	int status;
	int values[ROWS][COLUMNS];
};

struct tgrid {
	int tstatus;
	int tvalues[ROWS][COLUMNS][OPTIONS];
};

/* Function prototypes. See funcs.c */
struct grid* ngrid(void);
struct tgrid* ntgrid(void);
void fgrid(struct grid* Grid);
void fgridtst(struct grid* Grid);
void ftgrid(const struct grid* Grid, struct tgrid* tGrid);
void updrctgrid(const struct grid* Grid, struct tgrid* tGrid);
void updbtgrid(const struct grid* Grid, struct tgrid* tGrid, int box);
void crow(struct grid* Grid, struct tgrid* tGrid, int row);
void ccol(struct grid* Grid, struct tgrid* tGrid, int col);
void cbox(struct grid* Grid, struct tgrid* tGrid, int box);
void cgrid(struct grid* Grid, struct tgrid* tGrid);
void frstguess(struct grid* tmpGrid, struct tgrid* tGrid);
void pgrid(const struct grid* Grid);
void dgrid(struct grid* Grid);
void dtgrid(struct tgrid* tGrid);
void ptgrid(const struct tgrid* tGrid);
void ptgridsum(const struct tgrid* tGrid);
void ptopts(const struct tgrid* tGrid);
int chkgrid(const struct grid* Grid);

/* End header guard */
#endif


