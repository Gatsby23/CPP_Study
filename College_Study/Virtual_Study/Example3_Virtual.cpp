#include <iostream>
class Base{
	public:
		void fun1() {fun2();}
		virtual void fun2(){ cout << "Base:fun2()" << endl; }
};

class Derived::public Base{
	public:
		virtual void fun2(){ cout << "Derived:fun2()" << endl;}
};

int main()
{
	Derived d;
	Base *pBase = &d;
	pBase->fun1();
	return 0;
}
