#pragma once
#include<string>

using namespace std;

class printPrior
{
	string* Wait{};
	int* Pri{};
	int maxQ{};
	int length{};
public:
// конструктор	
	printPrior(int q);
// конструктор по умолчанию
	printPrior() :printPrior(10) {};
// деструктор
	~printPrior();
// описание методов класса
	void Show();
	void Clear();
	bool isEmpty() const;
	bool isFull() const;
	int GetCount() const;
	void Add(string per, int pr);
	string Extract();

};

