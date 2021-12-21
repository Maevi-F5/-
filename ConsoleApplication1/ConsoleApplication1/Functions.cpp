#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	Initials initials;
	Years years;
	Grade grade;

	cout << "Введите размер массива: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Введите возраст: ";
		cin >> years.age;

		cout << "Введите класс: ";
		cin >> grade.year >> grade.letter;

		d[i].DataEntry(initials, years, grade);

		cout << "_________________________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string filename)
{
	ifstream reading(filename);

	if (reading) {
		Initials initials;
		Years years;
		Grade grade;

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> initials.surname >> initials.name >> initials.patrinymic;
			reading >> years.age;
			reading >> grade.year >> grade.letter;

			d[i].DataEntry(initials, years, grade);
		}

		cout << "Данные считаны" << endl;
	}
	else
		cout << "Ошибка открытия файла" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные №" << i + 1 << endl;

		d[i].Print();
		cout << "_________________________________________\n";
	}
}

void DataChange(Data* d, int n)
{
	Initials initials;
	Years years;
	Grade grade;
	int _n;

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		cout << "Введите новые ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Введите новый возраст: ";
		cin >> years.age;

		cout << "Введите новый класс: ";
		cin >> grade.year >> grade.letter;

		d[_n].DataEntry(initials, years, grade);
	}
	else
		cout << "Номер введён неверно" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	Initials initials;
	Years years;
	Grade grade;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите новые ФИО: ";
	cin >> initials.surname >> initials.name >> initials.patrinymic;

	cout << "Введите новый возраст: ";
	cin >> years.age;;

	cout << "Введите новый класс: ";
	cin >> grade.year >> grade.letter;

	d[size].DataEntry(initials, years, grade);

	cout << "" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != n) {
				d[q] = buf[i];
				q++;
			}
		}

		cout << "Данные удалены" << endl;
	}
	else
		cout << "Номер введён неверно" << endl;

	delete[] buf;
}

void SortingData(Data* d, int n)
{
	Data buf;
	int numOfSorted = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].GetInitials().surname > d[j].GetInitials().surname) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSorted++;
			}
		}
	}

	cout << "Данные отсортированы" << endl << "Количество сортировок : " << numOfSorted << endl;
}