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
