#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class CStudent{
	public:
		char szName[20];
		int nScore;
};

int main()
{
	CStudent s;
	/*
	ofstream OutFile("student.dat", ios::out|ios::binary);
	while(cin >> s.szName >> s.nScore){
		if(strcmp(s.szName, "exit") == 0)
			break;
		OutFile.write((char*)&s, sizeof(s));
	}
	OutFile.close();*/
	
	/*
	ifstream inFile("student.dat", ios::in|ios::binary);
	if(!inFile){
		cout << "error" << endl;
		return 0;
	}

	while(inFile.read((char*)&s, sizeof(s))){
		int nReadedBytes = inFile.gcount();	//看刚刚读了多少字节
		cout << s.szName << " " << s.nScore << endl;
	}
	inFile.close();*/

	fstream iofile("student.dat", ios::in|ios::out|ios::binary);
	if(!iofile){
		cout << "error";
		return 0;
	}
	iofile.seekp(2*sizeof(s), ios::beg);
	iofile.write("Mike", strlen("Mike")+1);
	iofile.seekg(0, ios::beg);	//定位读指针到开头
	while(iofile.read( (char*)&s, sizeof(s) ))
		cout << s.szName << " " << s.nScore << endl;
	iofile.close();
	return 0;
}
