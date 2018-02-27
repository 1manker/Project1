#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include "node.h"

using namespace std;

class Matrix {
public:
	Matrix();
	void insert(int x);
	double size() const;
	void fill(fstream& stream);
	void print(ostream& stream) const;
	int Matrix::squareRoot(int count) const;
	Node * first;
};
ostream & operator<<(ostream & outfile, const Matrix & matrix);
Matrix operator+(Matrix& a, Matrix& b);
Matrix operator*(Matrix& a, int b);
Matrix operator*(Matrix& a, Matrix& b);
int nextEntry(int id, int step, Matrix& matrix);

#endif _MATRIX_H_