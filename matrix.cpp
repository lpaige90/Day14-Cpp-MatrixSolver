#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
	rows=1;
	cols=1;

	matrix = new double*[rows];
	matrix[rows-1][cols-1] = 0;
}

Matrix::Matrix(int numRows, int numCols) {
	rows = numRows;
	cols = numCols;

	matrix = new double*[rows];

	for (int r=0; r<rows; ++r) {
			matrix[r] = new double[cols];
	}

	for (int r=0; r<rows; ++r) {
		for (int c=0; c<cols; ++c) {
			matrix[r][c] = 0;
		}
	}
}

Matrix::~Matrix() {
	for (int r=0; r<rows; ++r) {
		delete [] matrix[r];
	}
	delete [] matrix;
}

double* Matrix::operator[](int num) const {
	return matrix[num];
}

Matrix* operator+(const Matrix &matrix1, const Matrix &matrix2) {
	if ((matrix1.rows != matrix2.rows) || (matrix1.cols != matrix2.cols)) {
		std::cout << "You cannot add two matrices of different sizes.";
		exit (EXIT_FAILURE);
	} else {
		Matrix *tempMatrix  = new Matrix(matrix1.rows, matrix1.cols);

		for (int r=0; r<matrix1.rows; ++r) {
			for (int c=0; c<matrix1.cols; ++c) {
				(*tempMatrix)[r][c] = matrix1[r][c] + matrix2[r][c];
			}
		}

		return tempMatrix;
	}
}

Matrix* operator-(const Matrix &matrix1, const Matrix &matrix2) {
	if ((matrix1.rows != matrix2.rows) || (matrix1.cols != matrix2.cols)) {
		std::cout << "You cannot add two matrices of different sizes.";
		exit (EXIT_FAILURE);
	} else {
		Matrix *tempMatrix  = new Matrix(matrix1.rows, matrix1.cols);

		for (int r=0; r<matrix1.rows; ++r) {
			for (int c=0; c<matrix1.cols; ++c) {
				(*tempMatrix)[r][c] = matrix1[r][c] - matrix2[r][c];
			}
		}

		return tempMatrix;
	}
}

Matrix* operator*(const Matrix &matrix1, const Matrix &matrix2) {
	if ((matrix1.cols != matrix2.rows)) {
		std::cout << "Number of columns in A must match number of rows in B.";
		exit (EXIT_FAILURE);
	} else {
		Matrix *tempMatrix  = new Matrix(matrix1.rows, matrix2.cols);
		double sum;

		for (int i=0; i<matrix1.rows; ++i) {
			for (int j=0; j<matrix2.cols; ++j) {
				sum = 0;
				for (int k=0; k<matrix1.cols; ++k) {
					sum += (matrix1[i][k]) * (matrix2[k][j]);
				} 
				(*tempMatrix)[i][j] = sum;
			}
		}

		return tempMatrix;
	}
}

Matrix* operator*(const double coefficient, const Matrix &matrix1) {

	Matrix *tempMatrix  = new Matrix(matrix1.rows, matrix1.cols);

	for (int r=0; r<matrix1.rows; ++r) {
		for (int c=0; c<matrix1.cols; ++c) {
				(*tempMatrix)[r][c] = coefficient * (matrix1[r][c]);
			}
		}

	return tempMatrix;
}



void Matrix::setMatrix() {
	for (int r=0; r<rows; ++r) {
		std::cout << "Row " << r+1 << ": " << std::endl;
		for (int c=0; c<cols; ++c) {
			std::cin >> matrix[r][c];
		}
		std::cout << std::endl;
	}
}

void Matrix::printMatrix() {
	for (int r=0; r<rows; ++r) {
		for (int c=0; c<cols; ++c) {
			std::cout << matrix[r][c] << " ";
		}
		std::cout << std::endl;
	}
}