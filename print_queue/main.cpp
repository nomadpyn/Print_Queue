#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"printPrior.h"


using namespace std;

// структура для хранения данных для статистики
struct task {
	string name{};
	int time[2]{ 0 };
};
// функция получения текущего времени
void getTime(int& hour, int& min) {
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;
}

int main() {

	printPrior Canon(5);
	vector <task> hstr{};
	int choise{ 0 };
	// меню для работы с принтером
	while (choise != 5) {
		cout << "\nWhat you want to do?\n";
		cout << "1 - Show wait, 2 - Add document to print wait, 3 - Print document, 4 - Show history of print, 5 - Turn off\n";
		cin >> choise;
		switch (choise) {
// показывает текущую очередь печати на экран
		case 1: {
			Canon.Show();
			break;
		}
// ввод имени пользователя и приориета и правильно распределение его в очереди печати
		case 2: {
			cout << "Enter name of user\n";
			string tmp_name{};
			cin >> tmp_name;
			cout << "Enter priority from 1 to 10\n";
			int tmp_pr{};
			cin >> tmp_pr;
			if (tmp_pr > 10)
				tmp_pr = 10;
			if (tmp_pr < 1)
				tmp_pr = 1;
			Canon.Add(tmp_name,tmp_pr);
			break;
		}
// добавление элемента в истории печати при его извлечении из очереди
		case 3:{
			task tmp{};
			tmp.name = Canon.Extract();
			getTime(tmp.time[0], tmp.time[1]);
			if (tmp.name != "None") {
				hstr.push_back(tmp);
			}
			break;
		}
// вывод истории печати на экран
		case 4: {
			for (task n : hstr)
				cout << n.name << " " << n.time[0] << ":" << n.time[1] << endl;
			break;
		}
// выход из программы
		case 5: {
			cout << "Goodbye\n";
			break;
		}
// действие по умолчанию
		default: {
			cout << "You make no choise! Try again!\n";
			break;
		}
		}
	}
	return 0;
}