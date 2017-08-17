#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Complex{
	private:
		double real, imag;
	public:
		Complex(double r = 0, double i = 0):real(r), imag(i){};
		friend ostream& operator<<(ostream& os, const Complex& c);
		friend istream& operator>>(istream&is, Complex &c);
};

ostream& operator<<(ostream& os, const Complex &c){
	os << c.real << "+" << c.imag << "i";
	return os;
}

istream& operator>>(istream& is, Complex &c){
	string S;
	is >> S;	//将“a+bi”作为字符串读入，“a+bi中间不能有空格”
	int pos = S.find("+", 0);
	string sTmp = S.substr(0, pos);		//分离出代表实部内容的信息
	c.real = atof(sTmp.c_str());		//atof库函数能将const char*指针指向的内容转换成float
	sTmp = S.substr(pos+1, S.length()-pos-2);//分离出代表虚部的字符串
	c.imag = atof(sTmp.c_str());
	return is;
}

int main()
{
	Complex c;
	int n;
	cin >> c >> n;
	cout << c << "," << n;
	return 0;
}
