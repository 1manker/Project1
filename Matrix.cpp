#include<iostream>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

Matrix::Matrix() 
	:first(NULL)
{
}

void Matrix::fill(fstream& stream) {
	//filling the matrix, needs work to accept all formatting of data and checking 
	//to make sure the matrix is square
	int temp(0);
	while(stream >> temp) {
		insert(temp);
	}
}

void Matrix::insert(int x) {
	//inserting entries into the matrix in order
	if (this->size() != 0) {
		Node * ptr = first;
		while (ptr->next_ != NULL) {
			ptr = ptr->next_;
		}
		ptr->next_ = new Node(x);
	}
	//if matrix is empty start a new first node
	else {
		first = new Node(x);
	}
	return;
}

double Matrix::size() const {
	//just counting through the linked list of entries
	double count(0);
	double square;
	Node * ptr = first;
	while (ptr != NULL) {
		count++;
		ptr = ptr->next_;
	}
	return count;
}

void Matrix::print(ostream& stream) const
{
	//formats and prints the matrix
	int index(1);
	int total = size();
	//finding how many entries to loop through
	total = squareRoot(total);
	Node * ptr = first;
	while (ptr != NULL) {
		stream <<setw(5)<< ptr->entry_ ;
		//endline every time a row is finished
		if (index%total == 0) {
			cout << endl;
		}
		ptr = ptr->next_;
		index++;
	}
}

int Matrix::squareRoot(int count) const {
	//as the matrices are supposed to always be square, can loop integers until the square root is found
	int squareOne(1), squareTwo(1);
	while ((squareOne*squareTwo) != count) {
		squareOne++;
		squareTwo++;
		if (squareOne > count) {
			cout << "error: matrix is not square" << endl;
			return 0;
		}
	}
	return squareOne;
}

Matrix operator+(Matrix& a, Matrix& b) {
	//take out each value and add them together, then put the entries in new matrix C
	int temp(0);
	Matrix c;
	Node * ptrOne = a.first;
	Node * ptrTwo = b.first;
	while (ptrOne != NULL) {
		temp = (ptrOne->entry_ + ptrTwo->entry_);
		c.insert(temp);
		ptrOne = ptrOne->next_;
		ptrTwo = ptrTwo->next_;
	}
	//return the new matrix C
	return c;
}

Matrix operator*(Matrix& a, Matrix& b) {
	int cols = a.squareRoot(a.size());
	Matrix c;
	int temp(0);
	//loop to cycle through matrix B values
	for (int h = 0; h < cols; h++) {
		//loop to cyle through matrix A values
		for (int j = 0; j < cols; j++) {
			temp = 0;
			//loop to get every individual entry
			for (int i = 0; i < cols; i++) {
				temp += (nextEntry(0, ((h*(cols)) + i%cols), a) * (nextEntry(1, (j*cols) + i, b)));
			}
			//adding the entries into the new matrix C
			c.insert(temp);
		}
	}
	//return the new matrix C that's been filled with new values
	return c;
}

int nextEntry(int id, int step, Matrix& matrix) {
	//determine next entry if it's the first matrix
	Node * ptr = matrix.first;
	int entry, cols(0), subcycle, cycle;
	cols = matrix.squareRoot(matrix.size());
	subcycle = step%cols;
	cycle = step / cols;
	//set the "steps" to go across rows
	if (id == 0) {
		for (int i = 0; i < step; i++) {
			ptr = ptr->next_;
		}
	}
	//determine next entry if it's the second matrix (going down columns)
	if (id == 1) {
		//set the "steps" to go down columns
		for (int h = 0; h < cycle; h++) {
			ptr = ptr->next_;
		}
		for (int j = 0; j < cols*subcycle; j++) {
				ptr = ptr->next_;
			}
		
	}
	//set the entry off to the multiplication function
	entry = ptr->entry_;
	return entry;
}

Matrix operator*(Matrix& a, int b) {
	//take each entry and multiply by int b
	Node * ptr = a.first;
	while (ptr != NULL) {
		ptr->entry_ *= b;
		ptr = ptr->next_;
	}
	return a;
}

ostream & operator<<(ostream & outfile, const Matrix & matrix)
{
	matrix.print(outfile);
	return outfile;
}
