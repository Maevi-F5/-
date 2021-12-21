#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Initials {
	string surname,
		name,
		patrinymic;
};

struct Years {
	int age;
};

struct Grade {
	int year;
	string letter;
};


class Data
{
private:
	Initials initials;
	Years years;
	Grade grade;

public:
	Data();
	Data(Initials initials_, Years years_, Grade grade_);
	~Data();

	void Print();
	void DataEntry(Initials initials_, Years years_, Grade grade_);
	Initials GetInitials() { return initials; };
	Years GetYears() { return years; };
	Grade GetGrade() { return grade; };

	Data& operator = (Data d_o);

};