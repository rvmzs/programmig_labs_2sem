#include <iostream>
#include <string>
#include "File_header.h"
#include "MyFunc_header.h"

using namespace std;

int main() {
	string again = "Do you want to restart this program?";
	string readingfile = "Do you want to read from file?";
	string writingfile = "Do you want to write results to file?";
	if (getsmth(readingfile)) {     // from file
		string filename = getfilename();
		if (!fileExists(filename)) {
			cout << "Can't find this file!" << endl;
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
		string sfile = reading_from_file(filename);
		string sf1= PointA(sfile);
		string sf2 =PointB(sfile);
		string sf3=PointC(sfile);
		string sf4 = PointD(sfile);

		if (getsmth(writingfile)) {
			writing_to_file(sf1,sf2,sf3,sf4);
			return 0;
		}
		cout<<"a) "<<sf1<<endl;
		cout<<"b) "<<sf2<<endl;
		cout<<"c) "<<sf3<<endl;
		cout<<"d) "<<sf4<<endl;
		return 0;
	}
	else {    // read from console
		//int n = naturalNum();

		string s=get_string();
		string s1 =PointA(s);
		string s2 = PointB(s);
		string s3 = PointC(s);
		string s4 =PointD(s);
		if (getsmth(writingfile)) {
			writing_to_file(s1,s2,s3,s4);
		}
		else{
            cout<<"a) "<<s1<<endl;
            cout<<"b) "<<s2<<endl;
            cout<<"c) "<<s3<<endl;
            cout<<"d) "<<s4<<endl;
		}
		if (getsmth(again)) {
			main();
		}
		return 0;
	}
	return 0;
}
