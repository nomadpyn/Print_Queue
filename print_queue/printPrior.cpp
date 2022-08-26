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
			cout << "User: " << this->Wait[i] << " - Priority " << this->Pri[i] << endl;
		cout << "Wait end\n";
	}
}// метод "очистки" очереди
void printPrior::Clear() {
	this->length = 0;
}
// проверка на пустую очередь
bool printPrior::isEmpty() const {
	return this->length == 0;
}
// проверка на полную очередь
bool printPrior::isFull() const {
	return this->length == this->maxQ;
}
// метод получения значения длины очереди
int printPrior::GetCount() const {
	return this->length;
}
// добавление элемента в очередь
void printPrior::Add(string per, int pr) {
	if (!isFull()) {
		int ind = this->length;
		for (int i = 0; i < this->length; i++) {
			if (pr > this->Pri[i]) {
				ind = i;
				break;
			}
		}
		if(ind !=(this->length)){
			for (int j = this->length; j > ind; j--) {
				this->Wait[j] = this->Wait[j - 1];
				this->Pri[j] = this->Pri[j - 1];
			}
		}
		this->Wait[ind] = per;
		this->Pri[ind] = pr;
		this->length++;
	}
}
// извлечение элемента из очереди
string printPrior::Extract() {
	string temp = "None";
	if (!isEmpty()) {
		temp = this->Wait[0];
		length--;
		for (int i = 0; i < length; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		return temp;
	}
	else 
		return temp;
		
}