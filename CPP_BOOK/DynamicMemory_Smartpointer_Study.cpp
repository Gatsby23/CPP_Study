/*
 * 1.对shared_ptr进行学习,主要学习内容是在于学会能否使两个对象共用底层元素
 * 这里实际上是一个典型的对数组类型的数据结构重构的例子
 * 

class StrBlob{
	public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> i1);
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		//添加或删除元素
		void push_back(const std::string &t){ data->push_back(t); }
		void pop_back();
		//元素访问
		std::string& front();
		std::string& back();
	private:
		std::shared_ptr<std::vector<std::string>> data;
		//如果data[i]不影响,则抛出一个异常
		void check(size_type i, const std::string &msg) const;
		
};

//构造函数
StrBlob::StrBlob():data(make_shared<vector<string>>()){ }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)){ }

//检查数组访问元素是否过界
void StrBlob::check(size_type i, const string &msg) const{
	if(i >= data->size())
		throw out_of_range(msg);
}

//进行元素访问
string& StrBlob::front(){
	//如果vector为空，check会抛出一个异常
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back(){
	//一样先做检查
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back(){
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}*/

/*
 * 2. 这里是对普通指针初始化对象和智能指针初始化对象进行学习
 * */

//这里写的是版本一: 利用普通指针进行构造
/*
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void print_vector(vector<int>* vector_pointer){
	for(const auto &item : *vector_pointer)
		std::cout << item << " ";
	std::cout << std::endl;
}

vector<int>* store_vector(){
	vector<int> *vector_pointer = new(nothrow) vector<int>();
	int item;
	while(std::cin >> item)
		vector_pointer->push_back(item);
	return vector_pointer;
}

int main()
{
	vector<int> *vector_pointer = store_vector();
	print_vector(vector_pointer);
	delete vector_pointer;
	return 0;
}*/

//这里是版本二: 利用shared_pointer进行构造
/*
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vector(void){
	return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> spv){
	int v;
	while(cin >> v)
		spv->push_back(v);
}

void print_ints(shared_ptr<vector<int>> spv){
	for(const auto &v : *spv)
		cout << v << " ";
	cout << endl;
}

int main()
{
	auto spv = new_vector();
	
	read_ints(spv);

	print_ints(spv);
	
	return 0;
}*/

// 学习new和动态数组的分配问题
/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const char *c1 = "Hello ";
	const char *c2 = "World";

	//字符串所需空间等于字符数+1
	char *r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(r, c1);									//拷贝第一个字符串常量
	strcat(r, c2);									//拷贝第二个字符串常量
	cout << r << endl;

	string s1 = "hello ";
	string s2 = "world";
	strcpy(r, (s1+s2).c_str());

	cout << r << endl;
	//释放动态数组
	delete[] r;

	return 0;
}*/

//处理变长长度的数组
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	char c;

	//分配20个字符的动态数组
	//最多存放19个字符
	char *r = new char[20];
	int l  = 0;

	while(cin.get(c)){
		if(isspace(c))
			break;
		r[l++] = c;		//存放如动态数组
		if(l == 20){	//已读入19个字符
			cout << "达到数组容量上限" << endl;
			break;
		}
	}
	r[l] = 0;
	cout << r << endl;

	//释放动态数组
	delete[] r;
	return 0;
}
