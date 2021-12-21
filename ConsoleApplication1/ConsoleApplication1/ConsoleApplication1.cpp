#include "Functions.h"

int _stateMenu;

void Menu() {
    cout << "Выберите действие: " << endl
        << "(0) Выход из программы" << endl
        << "(1) Ввод данных" << endl
        << "(2) Вывод данных" << endl
        << "(3) Изменение данных" << endl
        << "(4) Добавление данных" << endl
        << "(5) Удаление данных" << endl
        << "(6) Сортировка данных" << endl
        << "Ваш выбор: ";
    cin >> _stateMenu;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    int _actions;
    string filename;

    int _size = 0;
    Data* d = new Data[_size];

    while (_stateMenu != 0)
    {
        switch (_stateMenu)
        {
        case 1:
            system("cls");

            cout << "(0) Ввести данные из файла" << endl
                << "(1) Ввести данные вручную" << endl
                << "Ваш выбор: ";
            cin >> _actions;

            system("cls");

            if (_actions == 1) {
                DataEntry(d, _size);
            }
            else {
                cout << "Введите путь к файлу: ";
                cin >> filename;
                DataReading(d, _size, filename);
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 2:
            system("cls");

            if (_size != 0)
                Print(d, _size);
            else
                cout << "Данные пусты" << endl;

            system("pause");
            system("cls");
            Menu();
            break;

        case 3:
            system("cls");

            if (_size != 0)
                DataChange(d, _size);
            else
                cout << "Данные пусты" << endl;

            system("pause");
            system("cls");
            Menu();
            break;

        case 4:
            system("cls");

            if (_size != 0)
                AddData(d, _size);
            else
                cout << "Данные пусты" << endl;

            system("pause");
            system("cls");
            Menu();
            break;

        case 5:
            system("cls");

            if (_size != 0)
                DeleteData(d, _size);
            else
                cout << "Данные пусты" << endl;

            system("pause");
            system("cls");
            Menu();
            break;

        case 6:
            system("cls");

            if (_size != 0)
                SortingData(d, _size);
            else
                cout << "Данные пусты" << endl;

            system("pause");
            system("cls");
            Menu();
            break;

        default:
            cout << "Пункт меню введён неверно" << endl;
            system("cls");
            Menu();
            break;
        }
    }

}
