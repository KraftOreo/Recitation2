#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Mat * initailizeMatrix(int rows, int cols){
	Mat * m = (Mat *) malloc(sizeof(Mat));
	m->rows = rows;
	m->cols = cols;
	m->data = (double **) malloc(sizeof(double *) * rows);
	for(int i = 0; i < rows; i++){
		m->data[i] = (double *) malloc(sizeof(double) * cols);
		for(int j=0; j < cols; j++){
			m->data[i][j] = 0;
		}
	}
	return m;
}

void print(Mat * mat){
	for(int i = 0; i < mat->rows; i++){
		for(int j = 0; j < mat->cols; j++){
			printf("%f ", mat->data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void freeMatrix(Mat * mat){
	for(int i = 0; i < mat->rows; i++){
		free(mat->data[i]);
	}
	free(mat->data);
	free(mat);
}

Mat * identity(int size){
	Mat * m = initailizeMatrix(size, size);
	for(int i = 0; i < size; i++){
		m->data[i][i] = 1;
	}
	return m;
}

Mat * add(Mat * mat1, Mat* mat2){
	if(mat1->rows != mat2->rows || mat1->cols != mat2->cols){
		printf("Error: Matrices must be the same size to add\n");
		return NULL;
	}
	Mat * m = initailizeMatrix(mat1->rows, mat1->cols);
	for(int i = 0; i < mat1->rows; i++){
		for(int j = 0; j < mat1->cols; j++){
			m->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
		}
	}
	return m;
}

Mat * scalarMultiply(Mat * mat, double coef){
	Mat * m = initailizeMatrix(mat->rows, mat->cols);
	for(int i = 0; i < mat->rows; i++){
		for(int j = 0; j < mat->cols; j++){
			m->data[i][j] = mat->data[i][j] * coef;
		}
	}
	return m; 
}

Mat * subtract(Mat * mat1, Mat * mat2){
	return add(mat1, scalarMultiply(mat2, -1));
}

Mat * multiply(Mat * mat1, Mat* mat2){
	if(mat1->cols != mat2->rows){
		printf("Error: Matrices must be the same size to multiply\n");
		return NULL;
	}
	Mat * m = initailizeMatrix(mat1->rows, mat2->cols);
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			for(int k = 0; k < mat1->cols; k++){
				m->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
			}
		}
	}
	return m;
}

