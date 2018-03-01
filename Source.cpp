//Lucas Manker

#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

int main() {
	fstream stream("1.txt");
	fstream stream1("2.txt");
	Matrix a,b,c;
	a.fill(stream);
	b.fill(stream1);
	c = a*b;
	cout <<c<< endl;
	system("pause");
	return 0;
}



