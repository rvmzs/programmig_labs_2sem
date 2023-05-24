#include <iostream>
#include <string>
#include "Exercise_header.h"
#include "MyFunc_header.h"
using namespace std;

void PointA(float** matrix, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][0];
	}
	cout <<"a) The sum of elements of the first column: " << sum << endl;
	cout << "------------------------------------" << endl;
}

void PointB(float** matrix, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][i]; // главная диагональ
		sum += matrix[i][n - i - 1]; // побочная диагональ
	}
	cout <<"b) The sum of the elements of the main and secondary diagonals: " << sum << endl;
	cout << "------------------------------------" << endl;
}

void PointC(float** matrix, int n) {
	double max_first = matrix[0][0];
	double max_last = matrix[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (matrix[0][i] > max_first) {
			max_first = matrix[0][i];
		}
		if (matrix[n - 1][i] > max_last) {
			max_last = matrix[n - 1][i];
		}
	}
	double result_v = max(max_first, max_last);
	cout << "c) The largest of the values of the first and last rows: " << result_v << endl;
	cout << "------------------------------------" << endl;
}

void PointD(float** matrix, int n) {
	double min_diag = matrix[0][n - 1];
	double min_line1 = matrix[1][n - 2];
	double min_line2 = matrix[2][n - 3];
	for (int i = 1; i < n - 1; i++) {
		if (matrix[i][n - i - 1] < min_diag) {
			min_diag = matrix[i][n - i - 1];
		}
		if (matrix[i - 1][n - i] < min_line1) {
			min_line1 = matrix[i - 1][n - i];
		}
		if (matrix[i + 1][n - i - 2] < min_line2) {
			min_line2 = matrix[i + 1][n - i - 2];
		}
	}
	double result_g = min(min_diag, min(min_line1, min_line2));
	cout << "d) The smallest of the values of the elements of the secondary diagonal and two adjacent lines:: " << result_g << endl;
	cout << "------------------------------------" << endl;
}

void PointE(float** matrix, int n, int m) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j +2 == m) {
				sum += matrix[i][j];
			}
		}
	}
	cout << "e) The sum of those matrix elements whose sum of indices is equal to m: " << sum << endl;
	cout << "------------------------------------" << endl;
}

void PointF(float** matrix, int n) {
	double max_diag = matrix[0][0];
	double min_diag2 = matrix[0][n - 1];
	for (int i = 1; i < n; i++) {
		if (matrix[i][i] > max_diag) {
			max_diag = matrix[i][i];
		}
		if (matrix[i][n - i - 1] < min_diag2) {
			min_diag2 = matrix[i][n - i - 1];
		}
	}
	bool result_e = max_diag > min_diag2;
	cout << "f) is it true that the largest of the values of the elements of the main diagonal" << endl;
	cout << " is greater than the smallest of the values of the elements of the secondary diagonal: " << result_e << endl;
	cout << "------------------------------------" << endl;
}

int naturalNumForM(int n){
    cout << "Write a natural number 'm' here(0<n<1000 and m<2*n): ";
	while (true) {
		string number;
		getline(cin, number);
		if (isNaturalNumber(number)) {
			int m = stoi(number);
			if(m<=2*n){
                return m;
			}
			else{
                cout<<"'m' doesn't meet the conditions!"<<endl;
                cout<<" Write correctly please: ";
			}
		}
		else {
			cout << "Error! Write a natural number (m<2*n): " << endl;
		}
	}

}

float epoint(float** matrix, int n, int m){
    float res=0;
    for (int i=0; i<n ;i++){
        for (int j=0; j<n ;j++){
            if( i+j+2 == m){
                res += matrix[i][j];
            }
        }
    }
    cout<<"e) The sum of those matrix elements whose sum of indices is equal to m: "<<res<<endl;
    cout<<"-------------------------"<<endl;
    return res;
}
