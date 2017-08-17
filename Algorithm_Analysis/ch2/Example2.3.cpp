//-------关于指针变量和地址的演示
#include <iostream>

using namespace std;

int main()
{
	int i = 11, j = 22;
	double d = 3.3, e = 4.4;
	
	//定义指针变量：
	//1.用于存放整数的地址:
	int *iPtr, *jPtr;
	
	//2.用于存放双精度的地址
	double *dPtr, *ePtr;
	
	iPtr = &i;			//iPtr的值是i的地址
	jPtr = &j;			//jPtr的值是j的地址
	dPtr = &d;			//dPtr的值是d的地址
	ePtr = &e;			//ePtr的值是e的地址
	
	cout << "&i = " << iPtr << endl
		 << "&j = " << jPtr << endl
		 << "&d = " << dPtr << endl
		 << "&e = " << ePtr << endl;
	
	return 0;
}
