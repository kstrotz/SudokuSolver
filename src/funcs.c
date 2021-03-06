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
	printf("\n");
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
			do {
				scanf("%d", &(Grid->values[i][j]));
				if (Grid->values[i][j] < 0 || Grid->values[i][j] > 9){
					fprintf(stderr, "[ ERROR ] Invalid numeric entry.\n");
				}
			} while (Grid->values[i][j] < 0 || Grid->values[i][j] > 9);
		}
	}
}

void fgridtst(struct grid* Grid){
	printf("Filling the grid...\n");
	Grid->values[0][0] = 5;
	Grid->values[0][1] = 0;
	Grid->values[0][2] = 0;
	Grid->values[0][3] = 3;
	Grid->values[0][4] = 0;
	Grid->values[0][5] = 8;
	Grid->values[0][6] = 4;
	Grid->values[0][7] = 0;
	Grid->values[0][8] = 0;
	Grid->values[1][0] = 0;
	Grid->values[1][1] = 0;
	Grid->values[1][2] = 6;
	Grid->values[1][3] = 0;
	Grid->values[1][4] = 9;
	Grid->values[1][5] = 0;
	Grid->values[1][6] = 0;
	Grid->values[1][7] = 7;
	Grid->values[1][8] = 0;
	Grid->values[2][0] = 8;
	Grid->values[2][1] = 1;
	Grid->values[2][2] = 0;
	Grid->values[2][3] = 6;
	Grid->values[2][4] = 0;
	Grid->values[2][5] = 0;
	Grid->values[2][6] = 0;
	Grid->values[2][7] = 0;
	Grid->values[2][8] = 0;
	Grid->values[3][0] = 7;
	Grid->values[3][1] = 0;
	Grid->values[3][2] = 8;
	Grid->values[3][3] = 0;
	Grid->values[3][4] = 0;
	Grid->values[3][5] = 0;
	Grid->values[3][6] = 1;
	Grid->values[3][7] = 0;
	Grid->values[3][8] = 0;
	Grid->values[4][0] = 0;
	Grid->values[4][1] = 5;
	Grid->values[4][2] = 0;
	Grid->values[4][3] = 0;
	Grid->values[4][4] = 0;
	Grid->values[4][5] = 0;
	Grid->values[4][6] = 0;
	Grid->values[4][7] = 9;
	Grid->values[4][8] = 0;
	Grid->values[5][0] = 0;
	Grid->values[5][1] = 0;
	Grid->values[5][2] = 1;
	Grid->values[5][3] = 0;
	Grid->values[5][4] = 0;
	Grid->values[5][5] = 0;
	Grid->values[5][6] = 3;
	Grid->values[5][7] = 0;
	Grid->values[5][8] = 4;
	Grid->values[6][0] = 0;
	Grid->values[6][1] = 0;
	Grid->values[6][2] = 0;
	Grid->values[6][3] = 0;
	Grid->values[6][4] = 0;
	Grid->values[6][5] = 5;
	Grid->values[6][6] = 0;
	Grid->values[6][7] = 3;
	Grid->values[6][8] = 2;
	Grid->values[7][0] = 0;
	Grid->values[7][1] = 7;
	Grid->values[7][2] = 0;
	Grid->values[7][3] = 0;
	Grid->values[7][4] = 3;
	Grid->values[7][5] = 0;
	Grid->values[7][6] = 8;
	Grid->values[7][7] = 0;
	Grid->values[7][8] = 0;
	Grid->values[8][0] = 0;
	Grid->values[8][1] = 0;
	Grid->values[8][2] = 3;
	Grid->values[8][3] = 2;
	Grid->values[8][4] = 0;
	Grid->values[8][5] = 0;
	Grid->values[8][6] = 0;
	Grid->values[8][7] = 0;
	Grid->values[8][8] = 6;
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
	int rsum = 0;
	int opt = 0;
	int jval = 0;
//	printf("Checking row %d.\n", row);
	for (int k = 0; k < OPTIONS; k++){
		rsum = 0;
		for (int j = 0; j < COLUMNS; j++){
			if (tGrid->tvalues[row][j][k] == 1){
				rsum += 1;
				opt = (k+1);
				jval = j;
			}
		}
		if (rsum == 1){
//			printf("Found match for [%d][%d].\n", row, jval);
			Grid->values[row][jval] = opt;
			for (int c = 0; c < OPTIONS; c++){
				if (c != (opt-1)){
					tGrid->tvalues[row][jval][c] = 0;
				}
			}
		}
	}
//	pgrid(Grid);
//	char ch;
//	scanf("%c",&ch);
}

void ccol(struct grid* Grid, struct tgrid* tGrid, int col){
	int csum = 0;
	int opt = 0;
	int ival = 0;
//	printf("Checking column %d.\n", col);
	for (int k = 0; k < OPTIONS; k++){
		csum = 0;
		for (int i = 0; i < ROWS; i++){
			if (tGrid->tvalues[i][col][k] == 1){
				csum += 1;
				opt = (k+1);
				ival = i;
			}
		}
		if (csum == 1){
//			printf("Found match for [%d][%d].\n", ival, col);
			Grid->values[ival][col] = opt;
			for (int r = 0; r < OPTIONS; r++){
				if (r != (opt-1)){
					tGrid->tvalues[ival][col][r] = 0;
				}
			}
		}
	}
//	pgrid(Grid);
//	char ch;
//	scanf("%c",&ch);
}

void cbox(struct grid* Grid, struct tgrid* tGrid, int box){
	int bsum = 0;
	int opt = 0;
	int row = 0;
	int col = 0;
	int rmin, cmin, rmax, cmax;
//	printf("bsum = %d\n", bsum);
//	printf("Checking box %d.\n", box);
	switch (box) {
		case 1:
			rmin = 0;
			cmin = 0;
			rmax = 3;
			cmax = 3;
			break;
		case 2:	
			rmin = 0;
			cmin = 3;
			rmax = 3;
			cmax = 6;
			break;
		case 3:	
			rmin = 0;
			cmin = 6;
			rmax = 3;
			cmax = 9;
			break;
		case 4:
			rmin = 3;
			cmin = 0;
			rmax = 6;
			cmax = 3;
			break;
		case 5:
			rmin = 3;
			cmin = 3;
			rmax = 6;
			cmax = 6;
			break;
		case 6:	
			rmin = 3;
			cmin = 6;
			rmax = 6;
			cmax = 9;
			break;
		case 7:
			rmin = 6;
			cmin = 0;
			rmax = 9;
			cmax = 3;
			break;
		case 8:
			rmin = 6;
			cmin = 3;
			rmax = 9;
			cmax = 6;
			break;
		case 9:
			rmin = 6;
			cmin = 6;
			rmax = 9;
			cmax = 9;
			break;
		default:
			rmin = 0;
			cmin = 0;
			rmax = 3;
			cmax = 3;
			break;
	}

//	printf("i: %d\nj: %d\nrmax: %d\ncmax: %d\n", rmin, cmin, rmax, cmax);

	for (int k = 0; k < OPTIONS; k++){
		bsum = 0;
		for (int i = rmin; i < rmax; i++){
			for (int j = cmin; j < cmax; j++){
				if (tGrid->tvalues[i][j][k] == 1){
					bsum += 1;
					opt = (k+1);
					row = i; 
					col = j;
				}
//			printf("i: %d j: %d bsum = %d\n",i, j, bsum);
			}		
		}
		if (bsum == 1){
//			printf("Found match for [%d][%d].\n", row, col);
			Grid->values[row][col] = opt;
			for (int b = 0; b < OPTIONS; b++){
				if (b != (opt-1)){
					tGrid->tvalues[row][col][b] = 0;
				}
			}
		}
	}
//	pgrid(Grid);
//	char ch;
//	scanf("%c",&ch);
}

void cgrid(struct grid* Grid, struct tgrid* tGrid){
	int optsum = 0;
	int opt = 0;
//	printf("Checking grid for single options.\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			for (int k = 0; k < OPTIONS; k++){
				optsum += tGrid->tvalues[i][j][k];
				if (tGrid->tvalues[i][j][k] == 1){
					opt = (k+1);
				}
			}
//			printf("[%d][%d] optsum = %d\n", i, j, optsum);
			if (optsum == 1){
				Grid->values[i][j] = opt;
//				printf("Found match for [%d][%d].\n", i, j);
			}
			opt = 0;
			optsum = 0;
		}
	}	
}

void frstguess(struct grid* tmpGrid, struct tgrid* tGrid, int* alt){
	int chk = 0;
	int sum = 0;
	alt[0] = 0;
	alt[1] = 0;
	alt[2] = 0;

	printf("[  ALERT  ] Guessing required!\n");

	for (int i = 0; i < ROWS; i++){
	if (chk){
		break;
	}
		for (int j = 0; j < COLUMNS; j++){
			if (chk){
				break;
			}
			if (!(tmpGrid->values[i][j])){
				for (int k = 0; k < OPTIONS; k++){
					if (tGrid->tvalues[i][j][k] == 1){
						sum += 1;
						if (sum == 2){
							alt[0] = i;
							alt[1] = j;
							alt[2] = (k+1);
						} else {
							alt[0] = 0;
							alt[1] = 0;
							alt[2] = 0;
						}
					}
				}
				if (sum == 2){
					for (int l = 0; l < OPTIONS; l++){
						if (tGrid->tvalues[i][j][l] == 1){
							tmpGrid->values[i][j] = (l+1);
							chk = 1;
							break;
						}
					}
				}
			}
		}
	}
}

void updrctgrid(const struct grid* Grid, struct tgrid* tGrid){
//	printf("Updating temp grid.\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			if (Grid->values[i][j] != 0){
				for (int ti = 0; ti < ROWS; ti++){
					if (ti != i){
						tGrid->tvalues[ti][j][((Grid->values[i][j])-1)] = 0;
					}
				}
				for (int tj = 0; tj < COLUMNS; tj++){
					if (tj != j){
						tGrid->tvalues[i][tj][((Grid->values[i][j])-1)] = 0;
					}
				}
			}
		}
	}
}

void updbtgrid(const struct grid* Grid, struct tgrid* tGrid, int box){
	int rmin, cmin, rmax, cmax;
	switch (box) {
		case 1:
			rmin = 0;
			cmin = 0;
			rmax = 3;
			cmax = 3;
			break;
		case 2:	
			rmin = 0;
			cmin = 3;
			rmax = 3;
			cmax = 6;
			break;
		case 3:	
			rmin = 0;
			cmin = 6;
			rmax = 3;
			cmax = 9;
			break;
		case 4:
			rmin = 3;
			cmin = 0;
			rmax = 6;
			cmax = 3;
			break;
		case 5:
			rmin = 3;
			cmin = 3;
			rmax = 6;
			cmax = 6;
			break;
		case 6:	
			rmin = 3;
			cmin = 6;
			rmax = 6;
			cmax = 9;
			break;
		case 7:
			rmin = 6;
			cmin = 0;
			rmax = 9;
			cmax = 3;
			break;
		case 8:
			rmin = 6;
			cmin = 3;
			rmax = 9;
			cmax = 6;
			break;
		case 9:
			rmin = 6;
			cmin = 6;
			rmax = 9;
			cmax = 9;
			break;
		default:
			rmin = 0;
			cmin = 0;
			rmax = 3;
			cmax = 3;
			break;
	}
	for (int i = rmin; i < rmax; i++){
		for (int j = cmin; j < cmax; j++){
			if (Grid->values[i][j] != 0){
				for (int ti = rmin; ti < rmax; ti++){
					for (int tj = cmin; tj < cmax; tj++){
						if ((ti != i) || (tj != j)){
							tGrid->tvalues[ti][tj][((Grid->values[i][j])-1)] = 0;
						}
					}
				}
			}
		}
	}	
}

int chkgrid(const struct grid* Grid){
	int sum = 0;
//	printf("Calculating sum.\n");
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			sum += Grid->values[i][j];
		}
	}
	return sum;
}

void ptgridsum(const struct tgrid* tGrid){
	int sum;
	struct grid* tmpGrid = ngrid();
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			sum = 0;
			for (int k = 0; k < OPTIONS; k++){
				sum += tGrid->tvalues[i][j][k];
			}
			tmpGrid->values[i][j] = sum;
		}
	}
	pgrid(tmpGrid);
	free(tmpGrid);
}

void ptopts(const struct tgrid* tGrid){
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			printf("\n[%d][%d]: ", i, j);
			for (int k = 0; k < OPTIONS; k++){
				if (tGrid->tvalues[i][j][k] == 1){
					printf("%d", (k+1));
				}
			}
		}
	}
	printf("\n\n");
}
