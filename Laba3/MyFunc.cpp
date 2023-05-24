#include <iostream>
#include <string>
#include "math.h"
#include <algorithm>

#include "MyFunc_header.h"

using namespace std;

bool getsmth(string value) {
	while (true) {
		string str;
		cout << value << endl;
		getline(cin, str);
		if (str == "1") {
			return true;
		}
		else if (str == "0") {
			return false;
		}
		else {
			cout << "Error! Write correctly please: " << endl;
		}
	}
}

bool isNaturalNumber(string s) {
	if (s.length() >= 5) {
		cout << "Error! It's out of range!" << endl;
		return false;
	}
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	int n = stoi(s);
	if (n <= 0) {
		return false;
	}
	return true;
}

int naturalNum() {
	cout << "Write a natural number here(0<n<1000): ";
	while (true) {
		string number;
		getline(cin, number);
		if (isNaturalNumber(number)) {
			return stoi(number);
		}
		else {
			cout << "Error! Write a natural number: " << endl;
		}
	}
}

bool contains_letter(const std::string& str){
    if(str.empty()){
        return true;
    }
	for (char c : str)
	{
		if (std::isalpha(c)|| c==' '||c=='_'|| c==',')
		{
			return true;
		}
	}
	return false;
}

bool contains_letterforint(const std::string& str){
    if(str.empty()){
        return true;
    }
	if (str.length() >= 9) {
		return true;
	}
	for (char c : str)
	{
		if (std::isalpha(c) || c == ' ' || c == '-' || c == '_' || c == ',')
		{
			return true;
		}
	}
	return false;
}

void OutputMatrix(float** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << "       ";
		}
		cout << endl;
		cout<<endl;
	}
}
