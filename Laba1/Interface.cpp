#include <iostream>
#include <cctype> //���������� ��� ������� isdigit()
#include <string>
#include "interF.h"
using namespace std;


bool getnext() {
    setlocale(LC_ALL, "Russian");
	cout << "������ �� �� ���������� ������ ��������� � ������ ������ ������?(0-���, 1-��)" << endl;
	while (true) {
            
            string sm;
            getline(cin, sm);
            if(sm=="1" || sm=="0") {
                return sm == "1";

            }
            else {
                cout << "������ �����. ����������, ������� ���������� ������jq." << endl;
            }
        }
}

bool isNaturalNumber(string s);

int naturalNum() {
    setlocale(LC_ALL, "Russian");
    cout << "������� ����������� ����� n: ";


    while (true) {
        string number;
        getline(cin, number);
        if (number.length() >= 10) {
            cout << "������ �����! ������� ������� ��������! ������� ����������� �����: " << endl;
        }
        else {
            if (isNaturalNumber(number)) {
                return stoi(number);
            }
            else {
                cout << "������ �����! ������� ����������� �����: " << endl;
            }
        }
    }
   
}



bool isNaturalNumber(string s) {
    // ��������� ������ ������ ������ �� ������������ �����
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    // ��������� ������ � �����
    int n = stoi(s);
    // ���������, ��� ����� �������������
    if (n <= 0) {
        return false;
    }
    return true;
}


bool FileOrNot() {
   
    cout << "������ ������������ ������ � ����� 'input.txt'? (0-���, 1-��)" << endl;
    while (true) {
        string sm;
        getline(cin, sm);
        if (sm == "1" || sm == "0") {
            return sm == "1";

        }
        else {
            cout << "������ �����. ����������, ������� ���������� ������ ������.." << endl;
        }
    }
}

bool getAgain() {
    setlocale(LC_ALL, "Russian");
    cout << "������ �� �� ������ ������ ��������� ������? (0-���, 1-��)" << endl;
    while (true) {
        string sm;
        getline(cin, sm);
        if (sm == "1" || sm == "0") {
            return sm == "1";

        }
        else {
            cout << "������ �����. ����������, ������� ���������� ������..." << endl;
        }
    }
}

bool FileWriting() {
    cout << "������ �� �� �������� ��������� ������ ��������� � ��������� ����?" << endl;
    while (true) {
        string sm;
        getline(cin, sm);
        if (sm == "1" || sm == "0") {
            return sm == "1";

        }
        else {
            cout << "������ �����. ����������, ������� ���������� ������...." << endl;
        }
    }
}
