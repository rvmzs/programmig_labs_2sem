#include <iostream>
#include <cctype> //библиотека для функции isdigit()
#include <string>
#include "interF.h"
using namespace std;


bool getnext() {
    setlocale(LC_ALL, "Russian");
	cout << "Хотите ли вы продолжить работу программы и ввести данные заново?(0-нет, 1-да)" << endl;
	while (true) {
            
            string sm;
            getline(cin, sm);
            if(sm=="1" || sm=="0") {
                return sm == "1";

            }
            else {
                cout << "Ошибка ввода. Пожалуйста, введите корректные данныеjq." << endl;
            }
        }
}

bool isNaturalNumber(string s);

int naturalNum() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите натуральное число n: ";


    while (true) {
        string number;
        getline(cin, number);
        if (number.length() >= 10) {
            cout << "Ошибка ввода! Слишком большое значение! Введите натуральное число: " << endl;
        }
        else {
            if (isNaturalNumber(number)) {
                return stoi(number);
            }
            else {
                cout << "Ошибка ввода! Введите натуральное число: " << endl;
            }
        }
    }
   
}



bool isNaturalNumber(string s) {
    // проверяем каждый символ строки на соответствие цифре
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    // переводим строку в число
    int n = stoi(s);
    // проверяем, что число положительное
    if (n <= 0) {
        return false;
    }
    return true;
}


bool FileOrNot() {
   
    cout << "Хотите использовать данные с файла 'input.txt'? (0-нет, 1-да)" << endl;
    while (true) {
        string sm;
        getline(cin, sm);
        if (sm == "1" || sm == "0") {
            return sm == "1";

        }
        else {
            cout << "Ошибка ввода. Пожалуйста, введите корректные данные заново.." << endl;
        }
    }
}

bool getAgain() {
    setlocale(LC_ALL, "Russian");
    cout << "Хотите ли вы начать работу программы заново? (0-нет, 1-да)" << endl;
    while (true) {
        string sm;
        getline(cin, sm);
        if (sm == "1" || sm == "0") {
            return sm == "1";

        }
        else {
            cout << "Ошибка ввода. Пожалуйста, введите корректные данные..." << endl;
        }
    }
}

bool FileWriting() {
    cout << "Хотите ли вы записать результат работы программы в текстовый файл?" << endl;
    while (true) {
        string sm;
        getline(cin, sm);
        if (sm == "1" || sm == "0") {
            return sm == "1";

        }
        else {
            cout << "Ошибка ввода. Пожалуйста, введите корректные данные...." << endl;
        }
    }
}
