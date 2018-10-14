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

struct row* nrow(void);
struct trow* ntrow(void);
void tcrow(struct row* Row, struct trow* tRow);
void prow(struct row* Row);
void ptrow(struct trow* tRow);
void ftrow(const struct row* Row, struct trow* tRow);

#endif
