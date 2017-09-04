#include <memory>
#include <iostream>

using namespace std;

struct A{
	int n;
	A(int v = 0):n(v){}
	~A(){cout << n << "desturctor" << endl;}
};

int main()
{
	shared_ptr<A> sp1(new A(2));						//sp1托管A(2)
	shared_ptr<A> sp2(sp1);								//sp2也托管A(2)
	cout << "1)" << sp1->n << "," << sp2->n << endl;	//输出1) 2, 2
	shared_ptr<A> sp3;
	A* p = sp1.get();
	cout << "2)" << p->n << endl;
	sp3 = sp1;											//sp3也托管A(2)
	cout << "3)" << (*sp3).n << endl;					//输出2
	sp1.reset();										//sp1放弃托管A(2)
	if(!sp1)
		cout << "4) sp1 is null" << endl;				//会输出
	A* q = new A(3);
	sp1.reset(q);										//sp1托管q
	cout << "5)" << sp1->n << endl;						//输出3
	shared_ptr<A> sp4(sp1);								//sp4托管A(3)
	shared_ptr<A> sp5;
	//sp5.reset(q)会导致程序报错,注意看C++ primer中，为什么这里会不能进行引用计数
	sp1.reset();
	cout << "before end main" << endl;
	sp4.reset();										//sp4放弃托管A(3),现在没有托管，会自动释放
	cout << "end main" << endl;
	return 0;
}
