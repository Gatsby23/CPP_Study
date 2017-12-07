// util/sharedptr3.cpp
/*
 * 这个例子主要是为了学习如何使用在共享内存中使用共享指针
 * 

#include <memory>		//for shared_ptr
#include <sys/mman.h>	//for shared memory
#include <fcntl.h>
#include <unistd.h>
#include <cstring>		//for strerror()
#include <cerrno>		//for errno
#include <string>
#include <iostream>

class
*/

/*
 * 这个例子主要是学习shared_ptr不适合用的情况下
 * 具体观察是在于:
 * 1.为什么不适用？具体表现在析构的时候为什么会不析构？
 * 2.当程序将要退出时，每个变量有几个指引？有几个被指向的对象
 * */


#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

//class Person{
//	public:
//		string name;
//		shared_ptr<Person> mother;
//		shared_ptr<Person> father;
//		vector<shared_ptr<Person>> kids;

//		Person(const string& n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr): name(n), mother(m), father(f){}

//		~Person(){
//			std::cout << "delete " << name << std::endl;
//		}
//};

class Person{
	public:
		string name;
		shared_ptr<Person> mother;
		shared_ptr<Person> father;
		vector<weak_ptr<Person>> kids;									// weak pointer
		Person( const string &n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr):name(n), mother(m), father(f){}
		void setParentsAndTheirKids(shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr){
			mother = m;
			father = f;
			if( m != nullptr){
				m->kids.push_back(shared_ptr<Person>(this));
			}
			if( f != nullptr){
				f->kids.push_back(shared_ptr<Person>(this));
			}
		}
		~Person(){
			cout << "delete " << name << endl;
		}
};

shared_ptr<Person> initFamily(const string& name){
	shared_ptr<Person> mom(new Person(name + "'s mom"));
	shared_ptr<Person> dad(new Person(name + "'s dad"));
	shared_ptr<Person> kid(new Person(name, mom, dad));
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}

int main()
{
	shared_ptr<Person> p_nico = initFamily("nico");

	std::cout << "nico's family exists" << std::endl;
	std::cout << "- nico is shared " << p_nico.use_count() << " times" << std::endl;
	std::cout << "- name of 1st kid of nico's mom: " << p_nico->mother->kids[0].lock()->name << std::endl;

	shared_ptr<Person> p_jim = initFamily("jim");
	std::cout << "jim's family exists" << std::endl;
	p_jim->setParentsAndTheirKids(p_nico->mother, p_nico->father);
}


