#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "Func_1.h"
#include "FileHeader.h"
using namespace std;

bool fileExists(const string& filename){
    ifstream file(filename); // открываем файл для чтения
    if (file) { // если файл успешно открыт
        return true; // файл существует
    }
    else {
        return false; // файл не существует
    }
}

void WriteFile(float* array, int n) {
    ofstream file("output.txt");
    sort(array, array + n);
    if (n == 1) {
        file << "You wrote just 1 point. The length is 0." << endl;
    }
    float len = array[1] - array[0];
    for (int i = 2; i < n; i++) {
        float a = array[i - 1];
        float b = array[i];
        float c = abs(b - a);

        if (len < c || len == c) {
            continue;
        }
        else {
            len = c;
        }
    }
    file << "The result is " << len << endl;
    file.close();
}

float* ArrayFile() {
    ifstream file("input.txt");
    string n;
    int n_int;
    getline(file, n);
    if (!contains_letterforint(n)) {
        n_int = stoi(n);
    }
    else {
        cout << "File has an invalid values!" << endl;
        return 0;
    }
    float* arr = new float[n_int];
    string val;
    float val1;
    for (int i = 0; i < n_int;i++) {
        file >> val;
        if (contains_letter(val)) {
            cout << "Error! File contains invalid values!" << endl;
            i--;
            return 0;
        }
        else {
            val1 = stof(val);
            arr[i] = val1;
        }
    }
    file.close();
    return arr;
}

bool is_file_empty(std::string filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}