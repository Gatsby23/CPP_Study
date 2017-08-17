//----------------------------------------------------------------------修改分割线--------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------
//这里主要做的是对内存分配和操作
//----------------------------------------------------------------------------------------------------------------------------------------------------------
//1.这里是对内存地址的申请判断
/*
#include <iostream>

using namespace std;

int main()
{
	short int short_number1, short_number2;
	long int long_number1, long_number2;
	cout << &short_number1 << "	" << &short_number2 << endl;
	cout << &long_number1 << "	" << &long_number2 << endl;
	cout << "The size of short int: " << sizeof(short_number1) << endl;
	cout << "The size of long int: "  << sizeof(long_number1) << endl;
	cout << "The size of short int in RAM: " << (&short_number2 - &short_number1) << endl;
	cout << "The size of long int in RAM:  " << (&long_number2 - &long_number1) << endl;
}*/

//----------------------------------------------------------------------修改分割线--------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------
//2.对多个不同变量进行内存申请,判断它在内存中的占用空间情况
#include <iostream>

using namespace std;

int main()
{
	short int short_number1, short_number2;
	int number1, number2;
	long int long_number1, long_number2;
	float float_number1, float_number2;
	double D_number1, D_number2;
	long double longD_number1, longD_number2;
	bool bool_variable1, bool_variable2;
	char char_variable1, char_variable2;
	
	cout << &short_number1 << "	" << &short_number2 << endl;
	cout << &number1 << "	" << &number2 << endl;
	cout << &long_number1 << "	" << &long_number2 << endl;
	cout << &float_number1 << "	" << &float_number2 << endl;
	cout << &D_number1 << "	" << &D_number2 << endl;
	cout << &longD_number1 << "	" << &longD_number2 << endl;
	cout << &bool_variable1 << "	" << &bool_variable2 << endl;
	cout << &char_variable1 << "	" << &char_variable2 << endl;
	
	cout << "The size of short int: " << sizeof(short_number1) << endl;
	cout << "The size of int: " << sizeof(number1) << endl;
	cout << "The size of long int: " << sizeof(long_number1) << endl;
	cout << "The size of float: " << sizeof(float_number1) << endl;
	cout << "The size of double: "	<< sizeof(D_number1) << endl;
	cout << "The size of long double: " << sizeof(longD_number1) << endl;
	cout << "The size of bool: " << sizeof(bool_variable1) << endl;
	cout << "The size of char: " << sizeof(char_variable1) << endl;
	
	cout << "The size of short int in RAM: " << (&short_number2 - &short_number1) << endl;
	cout << "The size of int in RAM: " 		 << (&number2 - &number1) << endl;
	cout << "The size of long int in RAM: "  << (&long_number2 - &long_number1) << endl;
	cout << "The size of float in RAM: " 	 << (&float_number2 - &float_number1) << endl;
	cout << "The size of double in RAM: " 	 << (&D_number2 - &D_number1) <<endl;
	cout << "The size of long double in RAM: " << (&longD_number2 - &longD_number1) << endl;
	cout << "The size of bool in RAM: "		 << (&bool_variable2 - &bool_variable1) << endl;
	cout << "The size of char in RAM: "		 << (&char_variable2 - &char_variable1) << endl;
	
	return 0;
}
