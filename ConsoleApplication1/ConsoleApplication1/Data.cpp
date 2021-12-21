#include "Data.h"

Data::Data()
{
	initials.surname = "";
	initials.name = "";
	initials.patrinymic = "";
	
	years.age = 0;

	grade.letter = "";
	grade.year = 0;
}

Data::Data(Initials initials_, Years years_, Grade grade_)
{
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	years.age = years_.age;

	grade.letter = grade_.letter;
	grade.year = grade_.year;
}

Data::~Data()
{
}

void Data::Print()
{
	cout << "ФИО: " << initials.surname << " " << initials.name << " " << initials.patrinymic << endl;
	cout << "Возраст: " << years.age << endl;
	cout << "Класс: " << grade.year << " " << grade.letter << endl;
}

void Data::DataEntry(Initials initials_, Years years_, Grade grade_)
{
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	years.age = years_.age;

	grade.letter = grade_.letter;
	grade.year = grade_.year;
}

Data& Data::operator=(Data d_o)
{
	this->initials.surname = d_o.initials.surname;
	this->initials.name = d_o.initials.name;
	this->initials.patrinymic = d_o.initials.patrinymic;

	this->years.age = d_o.years.age;

	this->grade.letter = d_o.grade.letter;
	this->grade.year = d_o.grade.year;

	return *this;
}