#include "printPrior.h"
#include<iostream>
#include<string>

// конструктор с параметром
printPrior::printPrior(int q) {
	maxQ = q;
	Wait = new string[q];
	Pri = new int[q];
	length = 0;
}
// деструктор
printPrior::~printPrior() {
	delete[] Wait;
	delete[] Pri;
}