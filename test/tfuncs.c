/*
 * Separate file for testing function implementation before migrating.
 *
 * K. Strotz
 * 14 Oct 2018
 */

#include "tsolver.h"

struct row* nrow(void){
	struct row* Row = (struct row*) malloc(sizeof(struct row));
	for (int i = 0; i < COLUMNS; i++){
		Row->rvalues[i] = 0;
	}
	return Row;
}

struct trow* ntrow(void){
	struct trow* tRow = (struct trow*) malloc(sizeof(struct trow));
	for (int i = 0; i < COLUMNS; i++){
		for (int j = 0; j < OPTIONS; j++){
			tRow->trvalues[i][j] = 0;
		}
	}
	return tRow;
}

void tcrow(struct row* Row, struct trow* tRow){
	int rsum = 0;
	int opt = 0;
	int col = 0;
	printf("rsum = %d\n", rsum);
	for (int i = 0; i < COLUMNS; i++){
		rsum = 0;
		for (int j = 0; j < OPTIONS; j++){
			if (tRow->trvalues[j][i] == 1){
				rsum += 1;
				opt = (j+1);
				col = i;
			}
		printf("rsum = %d\n", rsum);
		}
		if (rsum == 1){
			Row->rvalues[i] = opt;
			for (int c = 0; c < OPTIONS; c++){
				if (c != (opt-1)){
					tRow->trvalues[col][c] = 0;
				}
			}
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

void ptrow(struct trow* tRow){
	for (int i = 0; i < OPTIONS; i++){
		printf("+---+---+---+---+---+---+---+---+---+\n");
		for (int j = 0; j < COLUMNS; j++){
			printf("| %d ", tRow->trvalues[j][i]);
		}
		printf("|\n");
	}
	printf("+---+---+---+---+---+---+---+---+---+\n");
}

void ftrow(const struct row* Row, struct trow* tRow){
	for (int i = 0; i < COLUMNS; i++){
		if (Row->rvalues[i] == 0){
			for (int j = 0; j < OPTIONS; j++){
				tRow->trvalues[i][j] = 1;
			}
		} else {
			tRow->trvalues[i][(Row->rvalues[i]-1)] = 1;
		}
	}
}


