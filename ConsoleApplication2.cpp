#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include "consts.h"

struct Person {
    std::string fam; // фамилия
    std::string name; // имя
    std::string fatherNAME; // отчество
    std::string work; // должность
    std::string adress; //адресс

    Person(std::string f, std::string n, std::string fn, std::string w, std::string a) {
        fam = f;
        name = n;
        fatherNAME = fn;
        work = w;
        adress = a;
    }
    
    Person() {
        fam = "Иванов";
        name = "Иван";
        fatherNAME = "Иванович";
        work = "бухгалер";
        adress = "Казань";
    }
};

class LinkedList {
private:
    int size{0};
    struct Node {
        Person data;
        Node* next;
        Node(Person p) {
            data = p;
            next = NULL;
        }
    }* head, * tail;
    
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    //добавление элемента в конец списка
    void add(Person p);

    std::string res(Person data, int i);
    
    // Функция для поиска элемента по заданному полю и значению
    void contains(int field, std::string value);

    //Функция для поиска вхождения элемента
    void search(Person data);

    //печать всего списка в консоль
    void print(std::ostream& fout, bool tag);

    //загрузка данных из файла
    void load(std::string filename);


};

std::string selectFILE(int i, const std::string path);
short int readNUM(int all);
void printMenu();

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Лабораторная работа 6 ПОА" << std::endl;
    short int NUM, call;
    bool tag{ true };
    LinkedList laba;
    Person data, ghost;
    std::string searh, fin, fout;
    std::ofstream file;
    while (tag) {
        printMenu();
        NUM = readNUM(6);
        std::cout << std::endl;
        switch (NUM)
        {
        case 0:
            std::cout << "Программа завершена.";
            tag = 0;
            break;
        case 1:
            std::cout << "Введите фамилию: ";
            std::cin >> data.fam;
            std::cout << "Введите имя: ";
            std::cin >> data.name;
            std::cout << "Введите отчество: ";
            std::cin >> data.fatherNAME;
            std::cout << "Введите должность: ";
            std::cin >> data.work;
            std::cout << "Введите место проживания: ";
            std::cin >> data.adress;
            laba.add(data);
            std::cout << "Человек с введенными данными создан!" << std::endl;
            break;
        case 2:
            laba.print(std::cout, 1);
            break;
        /*case 3:
            std::cout << "В каком поле идет поиск:\n\
1. Фамилия\n\
2. Имя \n\
3. Отчество\n\
4. Должность\n\
5. Место жительства\n\
Введите цифру >> ";
            call = readNUM(5);
            std::cout << "Введите искомые данные: ";
            std::cin >> searh;
            std::cout << std::endl;
            laba.contains(call, searh);
            break;
            */
        case 3:
            std::cout << "Введите фамилию: ";
            std::cin >> data.fam;
            std::cout << "Введите имя: ";
            std::cin >> data.name;
            std::cout << "Введите отчество: ";
            std::cin >> data.fatherNAME;
            std::cout << "Введите должность: ";
            std::cin >> data.work;
            std::cout << "Введите место проживания: ";
            std::cin >> data.adress;
            std::cout << std::endl;
            laba.search(data);
            break;
        case 4:
            fout = selectFILE(1, fout_const);
            file.open(fout);
            laba.print(file, 0);
            file.close();
            break;
        case 5:
            fin = selectFILE(0, fin_const);
            laba.load(fin);
            break;
        case 6:
            
            laba.add(ghost);
            std::cout << "Человек с предусмотренными данными создан!" << std::endl;
            break;
        }

    }
    
    
}

void LinkedList::add(Person p)
{
    Node* newNode = new Node(p);
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

std::string LinkedList::res(Person data, int i)
{
    std::string result;
    result = std::to_string(i) + ". " + data.fam + " " + data.name + " " +
        data.fatherNAME + " " + data.work + " " +
        data.adress + "\n";
    return result;
}

void LinkedList::contains(int field, std::string value)
{
    std::string result = "";
    Node* current = head;
    int i{ 0 };
    while (current != nullptr) {
        i++;

        if (field == 1 && current->data.fam == value) {
            result += res(current->data, i);
        }
        else if (field == 2 && current->data.name == value) {
            result += res(current->data, i);
        }
        else if (field == 3 && current->data.fatherNAME == value) {
            result += res(current->data, i);
        }
        else if (field == 4 && current->data.work == value) {
            result += res(current->data, i);
        }
        else if (field == 5 && current->data.adress == value) {
            result += res(current->data, i);
        }
        current = current->next;
    }
    if (result.empty()) {
        std::cout << "Элементов с заданным значением не найдено." << std::endl;;
    }
    else {
        std::cout << "Пользователи с " << field << "-м полем \"" << value << "\" в списке:" << std::endl << result;
    }
}

void LinkedList::search(Person data)
{
    std::string result = "";
    Node* current = head;
    int i{ 0 };
    while (current != nullptr) {
        i++;
        if (data.fam == current->data.fam && data.name == current->data.name && data.fatherNAME == current->data.fatherNAME && data.adress == current->data.adress)
            result += res(current->data, i);
        current = current->next;
    }
    if (result.empty()) {
        std::cout << "Таких пользователей нет в списке." << std::endl;;
    }
    else {
        std::cout << "Найденные пользователь/и:" << std::endl << result;
    }
}


void LinkedList::print(std::ostream& fout, bool tag)
{
    int i{ 0 };
    Node* current = head;
    while (current != nullptr) {
        i++;
        if (tag) fout << i << ". ";
        fout << current->data.fam << " "\
            << current->data.name << " "\
            << current->data.fatherNAME << " "\
            << current->data.work << " "\
            << current->data.adress << std::endl;
        current = current->next;
    }
}

void LinkedList::load(const std::string filename)
{

    std::ifstream file(filename);
    
    if (!file) {
        std::cout << "Ошибка при открытии файла " << filename << "\n";
        return;
    }
    bool i{ 1 };
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Person p;
            if (!(iss >> p.fam >> p.name >> p.fatherNAME >> p.work >> p.adress) or (!(iss.eof()) && iss.get() == ' ') && i) {
                std::cout << "Ошибка при чтении строк/и из файла" << std::endl;
                i = 0;
                
            }
            else{
            Node* newNode = new Node(p);
            if (head == NULL) {
                head = newNode;
            }
            else {
                Node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
            size++;}
        }
        file.close();
    }
    std::cout << "Данные из файла добавлены в конец списка." << std::endl;
}

