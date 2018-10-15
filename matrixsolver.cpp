#include <iostream>
#include "matrix.h"

int main() {
	int aRows, aCols;
	int bRows, bCols;
	int toDo;

	std::cout << "Number of rows in Matrix A: ";
	std::cin >> aRows;

	std::cout << "Number of columns in Matrix A: ";
	std::cin >> aCols;

	std::cout << "Number of rows in Matrix B: ";
	std::cin >> bRows;

	std::cout << "Number of columns in Matrix B: ";
	std::cin >> bCols;

	if (aRows <= 0 || aCols <= 0 || bRows <= 0 || bCols <= 0) {
		std::cout << "Rows and columns must be greater than 0. Terminating program.";
		exit (EXIT_FAILURE);
	}

	Matrix *matrixA = new Matrix(aRows, aCols);
	Matrix *matrixB = new Matrix(bRows, bCols);

	std::cout << "Enter the values in Matrix A, row by row..." << std::endl;

	matrixA->setMatrix();

	std::cout << "Matrix A: " << std::endl;
	matrixA->printMatrix();

	std::cout << "\nEnter the values in Matrix B, row by row..." << std::endl;

	matrixB->setMatrix();

	std::cout << "Matrix B: " << std::endl;
	matrixB->printMatrix();

	std::cout << "What would you like to do?\n1 - Add: A + B\n2 - Subtract: A - B\n3 - Multiply: A * B\n4 - Multiply by Coefficient: 2 * A" << std::endl;
	std::cin >> toDo;

	if (toDo == 1) {
		Matrix *sum;

		sum = *matrixA + *matrixB;
		std::cout << "\nA + B =" << std::endl;
		sum->printMatrix();
	} else if (toDo == 2) {
		Matrix *difference;

		difference = *matrixA - *matrixB;
		std::cout << "\nA - B =" << std::endl;
		difference->printMatrix();
	} else if (toDo == 3) {
		Matrix *product;

		product = (*matrixA) * (*matrixB);
		std::cout << "\nA * B =" << std::endl;
		product->printMatrix();
	} else if (toDo == 4) {
		Matrix *coeff;

		coeff = 2 * (*matrixA);
		std::cout << "\n2A = " << std::endl;
		coeff->printMatrix();
	} else {
		std::cout << "Unrecognized input. Terminating program.";
	}

	delete matrixA;
	delete matrixB;

	return 0;
}