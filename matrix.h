#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int rows;
	int cols;
	double ** data;
} Mat;

Mat * initailizeMatrix(int, int);
void print(Mat *);
void freeMatrix(Mat *);
Mat* identity(int);
Mat * add(Mat *, Mat *);
Mat * subtract(Mat *, Mat *);
Mat * multiply(Mat *, Mat *);
Mat * scalarMultiply(Mat *, double);
#endif
