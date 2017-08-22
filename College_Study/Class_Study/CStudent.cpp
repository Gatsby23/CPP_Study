#include <iostream>
#include <string>

using namespace std;

class CStudent{
	private:
		string name;
		string id;
		char gender;//性别，'F'代表女,'M'代表男,但这里会不会用枚举更好？
		int age;
	public:
		void PrintInfo();
		void SetInfo(const string &name_, const string &id_, int age_, char gender_);
		string GetName(){ return name; }
};	

class CUndergraduateStudent:public CStudent{
//本科生类,继承于CStudent类
	private:
		string department;//学生所属的系的名称
	public:
		void QualifiedForBaoyan(){//给予保研资格
			cout <<"qualified for baoyan" << endl;
		}

		void PrintInfo(){
			CStudent::PrintInfo();//调用基类的PrintInfo;
			cout << "Department: " << department << endl;
		}

		void SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_){
			CStudent::SetINfo(name_, id_, age_, gender_);	//调用基类的SetInfo
			department = department_;
		}
};

int main()
{

}
