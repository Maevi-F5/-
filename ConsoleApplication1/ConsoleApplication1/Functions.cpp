#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	Initials initials;
	Years years;
	Grade grade;

	cout << "Ââåäèòå ðàçìåð ìàññèâà: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Ââåäèòå ÔÈÎ: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Ââåäèòå âîçðàñò: ";
		cin >> years.age;

		cout << "Ââåäèòå êëàññ: ";
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

		cout << "Äàííûå ñ÷èòàíû" << endl;
	}
	else
		cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Äàííûå ¹" << i + 1 << endl;

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

	cout << "Ââåäèòå íîìåð íóæíîãî ýëåìåíòà (îò 1 äî " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		cout << "Ââåäèòå íîâûå ÔÈÎ: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Ââåäèòå íîâûé âîçðàñò: ";
		cin >> years.age;

		cout << "Ââåäèòå íîâûé êëàññ: ";
		cin >> grade.year >> grade.letter;

		d[_n].DataEntry(initials, years, grade);
	}
	else
		cout << "Íîìåð ââåä¸í íåâåðíî" << endl;
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

	cout << "Ââåäèòå íîâûå ÔÈÎ: ";
	cin >> initials.surname >> initials.name >> initials.patrinymic;

	cout << "Ââåäèòå íîâûé âîçðàñò: ";
	cin >> years.age;;

	cout << "Ââåäèòå íîâûé êëàññ: ";
	cin >> grade.year >> grade.letter;

	d[size].DataEntry(initials, years, grade);

	cout << "" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Ââåäèòå íîìåð íóæíîãî ýëåìåíòà (îò 1 äî " << n << "): ";
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

		cout << "Äàííûå óäàëåíû" << endl;
	}
	else
		cout << "Íîìåð ââåä¸í íåâåðíî" << endl;

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

	cout << "Äàííûå îòñîðòèðîâàíû" << endl << "Êîëè÷åñòâî ñîðòèðîâîê : " << numOfSorted << endl;
}

void SaveData(Data* d, int n, string filename)
{
	ofstream record(filename);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patrinymic << endl;
			record << d[i].GetYears().age << endl;
			record << d[i].GetGrade().year << " " << d[i].GetGrade().letter << endl;

			if (i < n - 1)
				record << endl;
		}

		cout << "Данные сохранены в файл: " << filename << endl;
	}
	else
		cout << "Ошибка открытия файла" << endl;

	record.close();
}
