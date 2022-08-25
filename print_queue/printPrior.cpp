#include "printPrior.h"
#include<iostream>
#include<string>

// конструктор с параметром
printPrior::printPrior(int q) {
	this->maxQ = q;
	this->Wait = new string[q];
	this->Pri = new int[q];
	this->length = 0;
}
// деструктор
printPrior::~printPrior() {
	delete[] this->Wait;
	delete[] this->Pri;
}
// метод вывода очереди печати на экран
void printPrior::Show() {
	if (this->length == 0)
		cout << "Print Wait is empty.\n";
	else {
		cout << "Wait start:\n";
		for (int i = 0; i < this->length; i++)
			cout << "User: " << this->Wait[0] << ".Priority " << this->Pri[0] << endl;
		cout << "Wait end\n";
	}
}// метод "очистки" очереди
void printPrior::Clear() {
	this->length = 0;
}