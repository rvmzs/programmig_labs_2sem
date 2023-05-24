#include <iostream>
#include <string>
#include <fstream>
#include "Header_File.h"
#include "MyFunc_header.h"
#include "Exercise_header.h"
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
		string matrix_use;
		getline(file, n_use);
		getline(file, m_use);
		getline(file,matrix_use);
		if (!contains_letterforint(n_use) && !contains_letterforint(m_use) && !n_use.empty() && !m_use.empty() && !matrix_use.empty()) {
			int n = stoi(n_use);
			int m = stoi(m_use);
		}
		else {
			cout << "File has an invalid values or file doesn't have enough values!" << endl;
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		int n = stoi(n_use);
		int m = stoi(m_use);
		float** matrix = matrixfromfile();
		if (!matrix) {
			if (getsmth(again)) {
				main();
			}
			return 0;
		}
		if (getsmth(filewriting)) {
			WriteToFile(matrix, n, m);
			delete[] matrix;
			return 0;
		}
		PointA(matrix, n);
		PointB(matrix, n);
		PointC(matrix, n);
		PointD(matrix, n);
		PointE(matrix, n, m);
		PointF(matrix, n);
		OutputMatrix(matrix, n);

		delete[] matrix;
		return 0;
	}
	else {                                 // read from console (ready)
		string val;
		float val1{0};
		int n = naturalNum();
		if(n==1){
            cout<<"Let's play with more that 1 element"<<endl;
            return 0;
		}
		float** matrix = new float* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new float[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Write elements of " << i + 1 << " line and " << j + 1 << " column: ";
				getline(cin, val);
				if (contains_letter(val)) {
					cout << "Error" << endl;
					j--;
				}
				else {
					val1 = stof(val);
					matrix[i][j] = val1;
				}
			}
		}
		int m = naturalNumForM(n);

		if (getsmth(filewriting)) {    // from console to file
			WriteToFile(matrix, n, m);
			delete[] matrix;
			if (getsmth(again)) {
				main();
			}
			return 0;
		}

		PointA(matrix,n);
		PointB(matrix, n);
		PointC(matrix, n);
		if(!n==2){
            PointD(matrix,n);
		}
		else{
            float minval = matrix[0][0];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]<minval){
                        minval = matrix[i][j];
                    }
                }
            }
            cout<<"d) The smallest of the values of the elements of the secondary diag and and two adjacent lines: "<< minval<<endl;
            cout<<"---------------------------"<<endl;
		}

		float res= epoint(matrix,n,m);
		PointF(matrix, n);
		OutputMatrix(matrix,n);
		delete[] matrix;
		if (getsmth(again)) {
			main();
		}
		return 0;
	}
	return 0;
}
