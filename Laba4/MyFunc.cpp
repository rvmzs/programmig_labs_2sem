#include <iostream>
#include <string>
#include "Myfunc_header.h"
using namespace std;


bool getsmth(string value) {
	while (true) {
		string str;
		cout << value <<"(1-'yes', '0'- no): ";
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

string init(int n){
	string s;
	char ch;
	for (int i = 0; i < n; i++) {
		cout << "s[" << i + 1 << "] = ";
		cin >> ch;
		s.push_back(ch);
	}
	return s;
}


string my_functions( string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '!') {
            s[i] = '.';
			}
		}

    cout << s << endl;


		string res2;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				res2 += "...";
			}
			else {
				res2 += s[i];
			}
		}

    cout << res2 << endl;


		string res3;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				res3 += '.';
				while (s[i + 1] == '.') {
					i++;
				}
			}
			else {
				res3 += s[i];
			}
		}
		cout << res3 << endl;



		string res4;
		int i = 0;
		while (i < s.length()) {
			if (s[i] == '.') {
				res4 += s[i];
				int j = i + 1;
				while (j < s.length() && s[j] == '.') {
					j++;
				}
				if (j - i > 2) {
					res4 += "...";
				}
				i = j;
			}
			else {
				res4 += s[i];
				i++;
			}
		}
		return res4;
		cout << res4 << endl;
	}


string get_string(){
    cout<<"Write a string right here: ";
    string str;
    while(true){
    getline (cin,str);
    if(str.empty()){
        cout<<"String is empty! Try again: ";
        continue;
    }
    return str;
}
}

string PointA(string s){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '!') {
            s[i] = '.';
			}
		}
		return s;
}
string PointB(string s){
    string res2;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				res2 += "...";
			}
			else {
				res2 += s[i];
			}
		}
		return res2;
}
string PointC(string s){
    string res3;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				res3 += '.';
				while (s[i + 1] == '.') {
					i++;
				}
			}
			else {
				res3 += s[i];
			}
		}
		return res3;
    }

string PointD(string s){
    int count{0};
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            count++;
        }
        else {
            if (count >= 3) {
                result += "...";
            }
            else {
                result += string(count, '.');
            }

            count = 0;
            result += s[i];
        }
    }

    if (count >= 3) {
        result += "...";
    }
    else {
        result += string(count, '.');
    }

    return result;

}

