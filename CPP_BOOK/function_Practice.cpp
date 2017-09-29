//==============================================================================================
//1.第一个练手程序，对形参、局部变量、局部静态变量区别的一个测试程序

/*
#include <iostream>

using namespace std;

void differ_between_parmeter(int var){
	 int local_var = 1;
	 static int local_static_var = 1;
	 cout << "The var is: " << var << endl;
	 cout << "The local_var is: " << local_var << endl;
	 cout << "The static local var is: " << local_static_var << endl;
	 local_var++;
	 local_static_var++;
}

test_for_differ(){
	int main_var = 0;
	for(int i = 0; i < 5; i++){
		cout << "==============================================" << endl;
		cout << "This is the " << i << "th to call the function:" << endl;
		differ_between_parmeter(main_var);
		cout << "==============================================" << endl;
		cout << endl;
	}
}
*/

//=============================================================================================
//2.头文件和声明函数之间的关系的一个例子
//-------------------------------Chapter.h-----------------------------------------------------
/*
int fact(int num_);
int my_abs(int num_);
*/

/*
#include <iostream>

using namespace std;

template<typename T>
void Swap(T* pointA, T* pointB){
	cout << "Before Swap: " << endl;
	cout << "	The A is: " << *pointA << endl;
	cout << "	The B is: " << *pointB << endl;
	T temp = *pointA;
	*pointA = *pointB;
	*pointB = temp;
	cout << "After Swap: " << endl;
	cout << "	The A is: " << *pointA << endl;
	cout << "	The B is: " << *pointB << endl;
}

void test_swap(){
	int int_A = 20, int_B = 30;
    int *int_pointA = &int_A;
	int *int_pointB = &int_B;
	Swap(int_pointA, int_pointB);	
	double double_A = 20.1, double_B = 30.1;
	double *double_pointA = &double_A;
	double *double_pointB = &double_B;
	Swap(double_pointA, double_pointB);
}

int main()
{
	test_swap();
}
*/

//==============================================================================================
//3.这里是对于引用参数传递理解的例子
//----------------------------------------------------------------------------------------------
/*
#include <iostream>

using namespace std;

void reset(int &num){
	num = 0;
}

int main()
{
	int number = 15;
	cout << "Before Reset, the number is: " << number << endl;
	reset(number);
	cout << "After Reset, the number is: " << number << endl;
	return 0;
}*/

//==============================================================================================
//4.考察const对于形参的描述问题
//----------------------------------------------------------------------------------------------
//--1.练手:判断一个String对象中是否有大写字母
//
/*
#include <iostream>
#include <string>

using namespace std;

bool is_captial(const string &str_word){
	for(auto c: str_word)
		if(isupper(c))\
			return true;
	return false;
}

void convert_to_Lower_case(string &str_word){
	for(auto &c:str_word)
		c = tolower(c);
}

int main()
{
	cout << "请输入一个字符串: " << endl;
	string str;
	cin >> str;
	if(is_captial(str)){
		convert_to_Lower_case(str);
		cout << "转换后的字符串为: " << str <<endl;
	}else
		cout << "该字符串不含大写字母, 无需转换" << endl;
	return 0;
}*/

//===============================================================================================
//5.
//-----------------------------------------------------------------------------------------------
/*
#include <iostream>
#include <string>

using namespace std;

int the_Bigger(const int num1, const int *num2_pointer){
	return (num1 < *num2_pointer) ? *num2_pointer : num1;
}

int main()
{
	int number1 = 10;
	int number2 = 20;
	int the_bigger_one = the_Bigger(number1, &number2);
	cout << "The number1 is: " << number1 << endl;
	cout << "The number2 is: " << number2 << endl;
	cout << "So the bigger one is: " << the_bigger_one << endl;
	return 0;
}*/

//==============================================================================================
//6.Swap的变种，对两个变量的指针进行变形->实际上对引用初始化的理解
//----------------------------------------------------------------------------------------------
/*
#include <iostream>

using namespace std;

void exchange_Int_Pointer(int* &num_pointer1, int* &num_pointer2){
	int* temp = num_pointer1;
	num_pointer1 = num_pointer2;
	num_pointer2 = temp;
}

int main()
{
	int number1 = 10;
	int number2 = 20;
	int *number_pointer1 = &number1;
	int *number_pointer2 = &number2;
	cout << "Before Exchange: The two pointer point is: " << endl
		 << "\t\t the first pointer point is: " << *number_pointer1 << endl
		 << "\t\t the second pointer point is: " << *number_pointer2 << endl;
	exchange_Int_Pointer(number_pointer1, number_pointer2);
	cout << "After Exchange: The two pointer point is " << endl
		 << "\t\t the first pointer point is: " << *number_pointer1 << endl
		 << "\t\t the second pointer point is: " << *number_pointer2 << endl;
	return 0;
}*/

//===============================================================================================
//7.数组类形参的传递与表示
//-----------------------------------------------------------------------------------------------
/*
#include <iostream>

using namespace std;

void print(const int *num){
	cout << "The numer in arry is: " << *num << endl;
}
void print(const int number){
	cout << "The number is: " << number << endl;
}

void print(const int *beg, const int *end){
	while( beg != end )
		cout << "The number in array is: " <<  *beg++ << endl;
}

int main()
{
	int i = 123;
	int j[2] = {0, 1};
	print(i);
	print(j);
	print(begin(j), end(j));
	return 0;
}*/

//==============================================================================================
//8.针对Main实参的操作
//----------------------------------------------------------------------------------------------
/*#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string str1_argv = argv[1];
	string str2_argv = argv[2];
	cout <<"The connection of two string: "<< str1_argv << " and " << str2_argv << " is "  << str1_argv+str2_argv << endl;
	return 0;
}*/

//===============================================================================================
//9.对于可变形参进行操作
//-----------------------------------------------------------------------------------------------
//1.编写一个函数,对于列表中所有元素进行求和
/*
#include <iostream>
using namespace std;

void calculate_all(initializer_list<int> numbers){
	int sum = 0;
	for(auto number : numbers){
		sum += number;
	}
	cout << "The sum of this number is: " << sum << endl;
}

void test_for_calculate_all(){
	calculate_all({1, 2, 3, 4, 5});
	calculate_all({20, 30, 40, 50, 12, 4, 2, 30,});
}

int main()
{
	test_for_calculate_all();
}*/

//===============================================================================================
//10.对于函数返回值的理解
//-----------------------------------------------------------------------------------------------
//1.重新修改200页的函数
/*
#include <iostream>
#include <string>
using namespace std;

bool str_subrange(const string &str1, const string &str2){
	//大小相同：此时用普通相等性判断结果作为返回值
	if(str1.size() == str2.size())
		return str1 == str2;								
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	
	//检查两个string对象的对应字符是否相等,以较短的字符串长度为限
	for(decltype(size) i = 0; i != size; i++){
		if(str1[i] != str2[i])
			return false;
	}
	return true;
}

void test_str_subrange(){
	string str1 = "hello";
	string str2 = "world";
	if(str_subrange(str1, str2))
		cout << "The" <<  str1 << " is the subrange of the " << str2 << endl;
	else
		cout << "The" <<  str1 << " is not the subrange of the " << str2 << endl;
}

int main()
{
	test_str_subrange();
}*/

//===============================================================================================
//11.对引用返回+数组形参传递的理解
//-----------------------------------------------------------------------------------------------
/*
#include <iostream>
using namespace std;

int &get(int *array, int index){ return array[index]; }

int main()
{
	int ia[10];
	for(int i = 0; i != 10; ++i)
		get(ia, i) = i;
	for(auto num : ia)
		cout << num << endl;
	return 0;
}*/

//===============================================================================================
//12.对递归函数的理解
//----------------------------------------------------------------------------------------------
//
#include <iostream>
#include <vector>

using namespace std;

//递归函数输出vector<int>的内容
void print(vector<int> vInt, unsigned index){
	unsigned sz = vInt.size();
	if(!vInt.empty() && index << sz){
		cout << vInt[index] << endl;
		print(vInt, index+1);
	}
}

int main()
{
	vector v = {1, 3, 5, 7, 9, 11, 13, 15};
	print(v, 0);
	return 0;
}
