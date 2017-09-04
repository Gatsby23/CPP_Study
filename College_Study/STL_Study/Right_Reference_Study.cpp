#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String{
	public:
		char* str;
		String():str(new char[1]){ str[0] = 0;}
		String(const char* s){
			str = new char[strlen(s) + 1];
			strcpy(str, s);
		}

		String(const String &s){
			cout << "Copy constructor called" << endl;
			str = new char[strlen(s.str) + 1];
			strcpy(str, s.str);
		}

		String &operator=(const String &s){
			cout << "Copy operator= called" << endl;
			if( str != s.str){
				delete []str;
				str = new char[strlen(s.str) + 1];
				strcpy(str, s.str);
			}
			return *this;
		}

		//move constructor
		String(String &&s):str(s.str){
			cout << "move constructor called" << endl;
			s.str = new char[1];
			s.str[0] = 0;
		}
		//move assignment
		String &operator=(String &&s){
			cout << "move operator= called" << endl;
			if(str!=s.str){
				delete []str;
				str = s.str;
				s.str = new char[1];
				s.str[0] = 0;
			}
			return *this;
		}
		~String(){ delete []str; }

};

template <class T> 
void MoveSwap(T& a, T& b){
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(a);
}

int main()
{
	String s;
	s = String("Ok");
	cout << "******" << endl;
	String &&r = String("this");
	cout << r.str << endl;
	String s1 = "hello", s2 = "word";
	MoveSwap(s1, s2);
	cout << s2.str << endl;
	return 0;
}
