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
                cout << "������������ ����. ��������� >> ";
            }
        }
        else {

            while (cin.get() != '\n') {
                if (cin.peek() == EOF)  cin.seekg(0, ios::end);
                cin.clear(); break;
            };
            cin.seekg(0, ios::end);
            cin.clear();
            cout << "������������ ����. ��������� >> ";

        }
    }
}

void printMenu()
{
    cout << endl;
    cout << "0. ���������� ���������" << endl;
    cout << "1. �������� �������" << endl;
    cout << "2. �������� ��� ��������" << endl;
    cout << "3. ��������� ������� ��������" << endl;
    cout << "4. ��������� ������ � ����" << endl;
    cout << "5. ��������� ������ �� �����" << endl;
    cout << "6. �������� ��������������� �������" << endl;
    cout << "���� >> ";
}

std::string selectFILE(int i, std::string path) {
    std::string s;
    std::cout << "���� �� ����� " << ((i == 0) ? "�����" : "������") << " >> ";
    std::getline(std::cin, s);
    if (s.empty()) return path;
    else return s;
}