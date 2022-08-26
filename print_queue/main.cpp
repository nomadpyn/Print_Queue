#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"printPrior.h"


using namespace std;

struct task {
	string name{};
	int time[2]{ 0 };
};

void getTime(int& hour, int& min) {
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;
}

int main() {


	return 0;
}