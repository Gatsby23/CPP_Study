//----对指针去引用的指示

#include <iostream>

using namespace std;

int main()
{
	int i = 11, j = 22;
	double d = 3.3, e = 4.4;
	
	//定义用于以下目的指针变量:
	//1.存放int型对象的地址
	int *iPtr, *jPtr;
	
	//2.存放double型对象的地址
	double *dPtr, *ePtr;
	
	iPtr = &i;				//iPtr的值是i的地址
	jPtr = &j;				//jPtr的值是j的地址
	dPtr = &d;				//dPtr的值是d的地址
	ePtr = &e;				//ePtr的值是e的地址

	cout << "\nAt address " << iPtr
		 << ", the value " << *iPtr << " is stored.\n" 
		 << "\nAt address " << jPtr
		 << ", the value " << *jPtr << " is stored.\n"
		 << "\nAt address " << dPtr
		 << ", the value " << *dPtr << " is stored.\n"
		 << "\nAt address " << ePtr
		 << ", the value " << *ePtr << " is stored.\n";
	return 0;
}
