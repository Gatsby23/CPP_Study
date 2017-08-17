//---------------------------------------------------------------------修改分割线-------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------这里写的程序对应编程问题1,只是求出一个数字的二进制表示
/*
#include <iostream>
using namespace std;

void printBinary(int value);

int main() {
    printBinary(17);
    return 0;
}

void printBinary(int value) {
    int bitOfBinary = sizeof(value) * 8;//sieof运算符获取value占几个字节，一个字节是8位
    unsigned int mask = 1 << (bitOfBinary - 1);//假设bitOfBinary是32，将1左移31位得到10000000000000000000000000000000
    for (int i = 1; i <= bitOfBinary; i++) {
        int temp = mask & value;
        if (temp == 0) 
            cout << 0;
        else 
            cout << 1;
        mask >>= 1;//每次将mask右移一位
    }
	cout << endl;
}
*/

//--------------------------------------------------------------------修改分割线--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//这里对应第二个问题:如何求出一个数字的二进制表示的补码--------------------------------------------------------------------------------------------------------
/*
#include <iostream>

using namespace std;

void printBinary(int value);

int main()
{
	printBinary(99);
	printBinary(5280);
	printBinary(255);
	printBinary(-255);
	printBinary(1024);
	printBinary(-1024);
	return 0;
}

void printBinary(int value){
	int bitOfBinary = sizeof(value) * 8;		//sizeof运算符获取value占几个字节,每个字节是8位
	unsigned int mask = 1 << (bitOfBinary - 1);	//假设binary是32位,将1移到位数最左端
	value = ~value;
	for(int i = 1; i <= bitOfBinary; i++){
		int temp = mask &value;
		if(temp == 0)
			cout << 0;
		else 
			cout << 1;
		mask >>= 1;								//每次将mask右移1位 
	}
	cout << endl;
}
*/
//--------------------------------------------------------------修改分割线-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//第三个问题:带有操作符的二进制操作
/*
#include <iostream>
#include <string>

using namespace std;

void printBinary(int value);
void notBinary(int value);
void caculateBinary(string _operator, int number1, int number2);

int main()
{
	int number1 = 13, number2 = 27;
	string _operator = "&";
	//notBinary(1);
	caculateBinary(_operator, number1, number2);
}

void printBinary(int value){
	int bitOfBinary = sizeof(value) * 8;
	unsigned int mask = 1 << (bitOfBinary - 1);		//sizeof运算符获取value占几个字节,每个字节是8位
	for(int i = 1; i <= bitOfBinary; i++){
		int temp = mask & value;
		if(temp == 0)
			cout << 0;
		else
			cout << 1;
		mask >>= 1;
	}
	cout << endl;
}

void notBinary(int value){
	cout << value << " : ";
	printBinary(value);
	cout << "~" << value << "(" ;
	value = ~value;
	cout << value << ")" << " : ";
	printBinary(value);
}

void caculateBinary(string _operator,int number1, int number2){
	if(_operator == "&"){
		cout << number1 << " : ";
		printBinary(number1);
		cout << number2 << " : ";
		printBinary(number2);
		int result = number1 & number2;
		cout << result << " : ";
		printBinary(result);
	}
}
*/

//------------------------------------------------------------------修改分割线----------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------第4个问题:如何判断在使用的C++版本中,一个整数的一处是否会造成"环绕"行为
