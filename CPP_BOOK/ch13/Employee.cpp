#include <iostream>
#include <string>

using namespace std;

class Employee{
	private:
		static int employeeId;
	public:
		Employee() {myId = employeeId++;}
		Employee(const string &s) { myName = s; myId = employeeId++; } 
	//开始创建拷贝构造函数和拷贝赋值运算符
	Employee(Employee &another) { myName = another.myName; myId = employeeId++; }
	Employee &operator=(Employee &rhs) { myName = rhs.myName; return *this; }
	const string &get_name() { return myName;}
	int get_MyId() { return myId;}

	private:
		string myName;
		int myId;
};

//访问符权限这边有点问题?为什么private成员变量在类外可以访问?
int Employee::employeeId = 0;

void employeeInformation(Employee &employ){
	cout << employ.get_name() << " : " << employ.get_MyId() << endl;
}

int main(int argc, char **argv)
{
	Employee a("Yao"), b = a, c;
	c = b;
	employeeInformation(a);
	employeeInformation(b);
	employeeInformation(c);

	return 0;
}
