#include <iostream>
#include <string>
#include "consts.h"

using namespace std;
short int readNUM(int all) {
    short int NUM;
    while (true) {
        cin >> NUM;
        if (cin.get() == '\n')
        {
            if (NUM >= 0 && NUM <= all) {
                return NUM;
            }
            else {
                cin.seekg(0, ios::end);
                cin.clear();
                cout << "Некорректный ввод. Повторите >> ";
            }
        }
        else {

            while (cin.get() != '\n') {
                if (cin.peek() == EOF)  cin.seekg(0, ios::end);
                cin.clear(); break;
            };
            cin.seekg(0, ios::end);
            cin.clear();
            cout << "Некорректный ввод. Повторите >> ";

        }
    }
}

void printMenu()
{
    cout << endl;
    cout << "0. Завершение программы" << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Показать все элементы" << endl;
    cout << "3. Проверить наличие элемента" << endl;
    cout << "4. Сохранить список в файл" << endl;
    cout << "5. Загрузить список из файла" << endl;
    cout << "6. Добавить предусмотренный элемент" << endl;
    cout << "Ввод >> ";
}

std::string selectFILE(int i, std::string path) {
    std::string s;
    std::cout << "Путь до файла " << ((i == 0) ? "ввода" : "вывода") << " >> ";
    std::getline(std::cin, s);
    if (s.empty()) return path;
    else return s;
}