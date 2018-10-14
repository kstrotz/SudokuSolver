/*
 * Separate file for testing function implementation before migrating.
 *
 * K. Strotz
 * 14 Oct 2018
 */

#include "tsolver.h"

struct row* nrow(void){
	struct row* Row = (struct row*) malloc(sizeof(struct row));
	return Row;
}

struct trow* ntrow(void){
	struct trow* tRow = (struct trow*) malloc(sizeof(struct trow));
	return tRow;
}

void tcrow(struct row* Row, struct trow* tRow){
	int sum = 0;
	int opt = 0;
	for (int i = 0; i < COLUMNS; i++){
		for (int j = 0; j < OPTIONS; j++){
			if (tRow->trvalues[i][j] = 1){
				rsum += 1;
				opt = (j+1);
			}
		}
		if (rsum == 1){
			Row->rvalues[i] = opt;
		}
	}
}

void prow(struct row* Row){
	printf("+---+---+---+---+---+---+---+---+---+\n");
	for (int i = 0; i < COLUMNS; i++){
		printf("| %d ", Row->rvalues[i]);
	}
	printf("|\n");
	printf("+---+---+---+---+---+---+---+---+---+\n");
}
