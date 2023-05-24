#include <istream>
#include <iostream>
#include <fstream>
#include <string>
#include "File_header.h"
#include "MyFunc_header.h"
using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename); // открываем файл для чтения
    if (file) { // если файл успешно открыт
        return true; // файл существует
    }
    else {
        return false; // файл не существует
    }
    file.close();
}

bool is_file_empty(std::string filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}

string getfilename() {
    string filepath;
    cout << "Enter path of the file:" << endl;
    getline(cin, filepath);
    if (filepath.empty()) {
        return "input.txt";
    }
    else {
        return filepath;
    }
}

string reading_from_file(string filename) {
    ifstream file(filename);
    string str;
    getline(file,str);
    return str;
}

void writing_to_file(string s1, string s2, string s3, string s4) {
    string filepath;
    cout << "Enter path of the file: " << endl;
    getline(cin, filepath);
    if (filepath.empty()) {
        ofstream file1("output.txt");
        file1 <<"a) " <<s1<<endl;
        file1<< "b) "<<s2<<endl;
        file1<< "c) "<<s3<<endl;
        file1<<"d) "<<s4<<endl;
    }
    else {
        ofstream file(filepath);
        file << "a) "<<s1<<endl;
        file<< "b) "<<s2<<endl;
        file<< "c) "<<s3<<endl;
        file<<"d) "<<s4<<endl;
    }
}
