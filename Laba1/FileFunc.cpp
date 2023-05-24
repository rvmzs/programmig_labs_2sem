#include <iostream>
#include <fstream>
#include <clocale>
#include "fileManager.h"
#include <fstream>
#include <string>
#include <cctype>
#include "interF.h"
using namespace std;

bool isFileEmpty(string filename);

bool fileExists(const string& filename)
{
   ifstream file(filename); // открываем файл для чтения

    if (file) { // если файл успешно открыт
        return true; // файл существует
    }
    else {
        return false; // файл не существует
    }
}




int FileF(const string& filename) {
    string line;
    ifstream file(filename);
    getline(file, line);

    if (line.empty()) {
        return -1;
    }
    
    while (true) {
        
        
            if (isNaturalNumber(line)) {
                return stoi(line);
            }
            else {
                cout << "Ошибка! В файле содержатся недопустимые значения" << endl;
                return -1;
            }
        
    }
}

bool isFileEmpty(string filename) {
    ifstream file(filename);
    return file.peek() == EOF;
}