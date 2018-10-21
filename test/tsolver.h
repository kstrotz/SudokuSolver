/*
 * Header file for testing various functions.
 * 
 * K. Strotz
 * 14 Oct 2018
 */

#ifndef TSOLVER_H
#define TSOLVER_H

#define ROWS 9
#define COLUMNS 9
#define OPTIONS 9

#include <stdio.h>
#include <stdlib.h>

struct row {
	int status;
	int rvalues[COLUMNS];
};

struct trow {
	int tstatus;
	int trvalues[COLUMNS][OPTIONS];
};

struct box {
	int status;
	int bvalues[(ROWS/3)][(COLUMNS/3)];
};

struct tbox {
	int tstatus;
	int tbvalues[(ROWS/3)][(COLUMNS/3)][OPTIONS];
}

struct row* nrow(void);
struct trow* ntrow(void);
void tcrow(struct row* Row, struct trow* tRow);
void prow(struct row* Row);
void ptrow(struct trow* tRow);
void ftrow(const struct row* Row, struct trow* tRow);

struct box* nbox(void);
struct tbox* ntbox(void);
void tcbox(struct box* Box, struct tbox* tBox);
void pbox(struct box* Box);
void ptbox(struct tbox* tBox);
void ftbox(const struct box* Box, struct tbox* tBox);

#endif
