#include <iostream>
#include <string>
#include <fstream>
#include "Func_1.h"
#include "FileHeader.h"
using namespace std;
int main() {
	string again = "Do you want to restart this program? (1-'yes', 0-'no')";
	string filereading = "Do you want to read data from file 'input.txt'? (1-'yes', 0-'no')";
	string filewriting = "Do you want to write to file? (1-'yes', 0-'no')";
	string filename = "input.txt";
	if (getsmth(filereading)) { // read from file
		if (!fileExists("input.txt")) { // checking #1 is beginning
			cout << "Can't find this file in this folder!" << endl;
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		if (is_file_empty(filename)) {
			cout << "The file is empty!" << endl;
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		ifstream file("input.txt");
		string n_use;
		string m_use;
		getline(file, n_use);
		if (!contains_letterforint(n_use) && m_use.empty()) {
			int n = stoi(n_use);
		}
		else {
			cout << "File has an invalid values!" << endl;
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		int n = stoi(n_use);
		float* arr = ArrayFile();
		if (!arr) {
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		if (getsmth(filewriting)) { // from file to file
			WriteFile(arr, n);
			return 0;
		}
		float res = FuncLab(arr, n);
		return 0;
	}
	else {             // read from console

		int n = naturalNum();
		float* array = ArrayRes(n);
		if (getsmth(filewriting)) {
			WriteFile(array, n);
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		float num = FuncLab(array, n);
		if (getsmth(again)) {
			main();
		}
		return 0;
	}
}