#include "matrix.h"

int main(int argc, char** argv){
	Mat * A = initailizeMatrix(3,3);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			A->data[i][j] = i + j;
		}
	}
	print(A);
	Mat * B = identity(3);
	print(B);
	Mat * C = add(A, B);
	print(C);
	freeMatrix(A);
	return 0;
}

