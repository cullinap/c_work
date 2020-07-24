#include <stdio.h>
#include <stdlib.h>

const int M = 3;
const int N = 3;

void print_matrix(int X[M][N], int i, int j) {

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf("%d", X[i][j]);
			if (j==2) {
				printf("\n");
			}
		}
	}

}


int create_matrix(int Ma) {

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			X[i][j] = rand() % 10;
		}
	}
}


int main() {

	int X[3][3];
	int W[3][3]; // X shaoe[0] x K
	int H[3][3]; // K x X shape [1]
	int i,j;

	// random initialization of target matrix and
	// factors 

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			X[i][j] = rand() % 10;
		}
	}

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			W[i][j] = rand() % 10;
		}
	}

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			H[i][j] = rand() % 10;
		}
	}

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			H[i][j] = rand() % 10;
		}
	}


	// print_matrix(X,i,j);
	// printf("\n");

	// print_matrix(W,i,j);
	// printf("\n");

	// print_matrix(H,i,j);


	return 0;
}

