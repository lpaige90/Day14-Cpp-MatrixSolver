#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	int rows;
	int cols;
	double **matrix;

	public:
		Matrix();
		Matrix(int numRows, int numCols);
		~Matrix();

		void setMatrix();
		void printMatrix();

		double* operator[](int num) const;
		friend Matrix* operator+(const Matrix &matrix1, const Matrix &matrix2);
		friend Matrix* operator-(const Matrix &matrix1, const Matrix &matrix2);
		friend Matrix* operator*(const Matrix &matrix1, const Matrix &matrix2);
		friend Matrix* operator*(const double coefficient, const Matrix &matrix1);
};

#endif