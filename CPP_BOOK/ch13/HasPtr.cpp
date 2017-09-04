#include <iostream>
#include <string>

using namespace std;

class HasPtr{
	public:
		//构造函数分配新的string和新的计数器，将计数器置为1
		HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)){}

		//拷贝构造函数拷贝所有三个数据成员,并递增计数器
		HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use){ ++*use; }	//拷贝构造函数
		HasPtr& operator=(const HasPtr&);									//拷贝赋值运算符
		HasPtr& operator=(const string&);									//赋予新string
		string& operator*();												//解引用
		~HasPtr();
	private:
		string *ps;
		int i;
		size_t *use;														//用来记录有多少个对象共享*ps的成员
};

HasPtr::~HasPtr(){
	if(--*use == 0){														//如果引用计数变为0
		delete ps;															//释放string的内存
		delete use;															//释放计数器的内存
	}
}

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	++*rhs.use;																//递增右侧运算对象的引用计数
	if(--*use == 0){														//然后递减本对象的引用计数
		delete ps;															//如果没有其他用户
		delete use;															//释放本对象分配的成员
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;															//返回本对象
}

HasPtr& HasPtr::operator=(const string &rhs){
	*ps = rhs;
	return *this;
}

string& HasPtr::operator*(){
	return *ps;
}

int main(int argc, char **argv)
{
	HasPtr h("Hi, Mom~");
	HasPtr h2 = h;															//未分配新的string，h2和h指向相同的string
	h = "Hi, dad";
	cout << "h: " << *h << endl;
  	cout << "h2: " << *h2 << endl;	
	return 0;	
}
