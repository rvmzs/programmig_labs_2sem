#include <iostream>
#include <cmath>
#include "interF.h"
#include <clocale>
#include "fileManager.h"
#include <fstream>
#include <string>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	if (FileOrNot()) {
		string filename = "input.txt";
		
		if (fileExists(filename)) {


			ifstream filenameU("input.txt");
			string str;
			getline(filenameU, str);

			if (str.empty()) {
				cout << "Файл пустой!" << endl;
				filenameU.close();

				if (getAgain()) {
					main();
				}
				else {
					return 0;
				}
			}



			int num = FileF(filename);
			if (num == -1) {
				if (getAgain()) {
					main();
				}
				return 0;
			}

			else {
				if (FileWriting()) {
					ofstream FileForWriting("output.txt");

					for (float x = 1; x < (1 + 0.1 * num); x = x + 0.1) {
						float y = (x * x - 3 * x + 2) / (sqrt(2 * x * x * x - 1));
						FileForWriting << "при x = " << x << "   " << "y=" << y << endl;
					}
					FileForWriting.close();

				}
				else {
					for (float x = 1; x < (1 + 0.1 * num); x = x + 0.1) {
						float y = (x * x - 3 * x + 2) / (sqrt(2 * x * x * x - 1));
						cout << "при x = " << x << "   " << "y=" << y << endl;
					}
				}
			}
			return 0;


		}
			else {
				cout << "Такого файла не существует. Либо файл находится в другой директории " << endl;
				if (getAgain()) {
					main();
				}
				return 0;
			}
	}
	
	
	int g{ 0 };

	int n = naturalNum();

	if (FileWriting()) {
		ofstream os("output.txt");
		for (float x = 1; x < (1 + 0.1 * n); x = x + 0.1) {
			float y = (x * x - 3 * x + 2) / (sqrt(2 * x * x * x - 1));
			os << "при x = " << x << "   " << "y=" << y << endl;
		}
		os.close();
		return 0;
	
	}
	
	else {
		for (float x = 1; x < (1 + 0.1 * n); x = x + 0.1) {
			float y = (x * x - 3 * x + 2) / (sqrt(2 * x * x * x - 1));
			cout << "при x = " << x << "   " << "y=" << y << endl;
		}
	}
	
	if (getAgain()) {
		main();
	}
	
	return 0;
}

