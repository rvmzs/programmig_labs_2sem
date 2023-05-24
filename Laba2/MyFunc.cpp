#include <iostream>
#include <string>
#include "math.h"
#include <algorithm>
#include "Func_1.h"
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
	cout << "Write a natural number here: ";
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

bool contains_letter(const std::string& str) {
	for (char c : str)
	{
		if (std::isalpha(c) || c == ' ' || c == '_' || c == ',')
		{
			return true;
		}
	}
	return false;
}

bool contains_letterforint(const std::string& str) {
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



float* ArrayRes(int n) {//эта функция готова, нужно доделать функцию выше
	string str;
	float str1;
	float* arr;
	arr = new float[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the " << i+1 << " element: ";
		getline (cin, str);
		if (contains_letter(str)) {
			cout << "Error!" << endl;
			i--;
		}
		else {
			str1 = stof(str);
			arr[i] = str1;
		}
	}
	return arr;
}

float FuncLab(float* array, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] == 0) {
			count++;
		}
	}
	if (count == n) {
		return 0;
	}
	sort(array, array + n);
	if (n == 1) {
		cout << "You wrote just 1 point. Length is 0." << endl;
		return 1;
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
	cout << "The result is: " << len << endl;
	return len;
}
	

