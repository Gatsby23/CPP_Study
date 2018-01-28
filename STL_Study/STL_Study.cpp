/*
 * 这里是对序列式容器学习，
 * */

//1. 这里主要是对vector学习。允许随机访问，在尾部附加或移除元素都很快速，但在中部或起始部安插比较费时，因为安插后所有的元素都必须移动
/*
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> coll;						//vector container for integer elements

	//append elements with values 1 to 6
	for(int i = 1; i <= 6; ++i)
		coll.push_back(i);

	//print all elements followed by a space
	for(int i = 0; i < coll.size(); ++i)
		cout << coll[i] << ' ';

	cout << endl;
	return 0;
}*/

//2.对deque容器学习。double-ended-queue, dynamic array.在头部和尾部安插元素都比较迅速，在中间部分安插比较费时，必须移动其他元素
/*
#include <deque>
#include <iostream>

using namespace std;

int main()
{
	deque<float> coll;						//deque container for floating-point elemnents
	//insert elements from 1.1 to 6.6 each at the front
	for(int i = 1; i <= 6; ++i)
		coll.push_front(i*1.1);				//insert at front
	//print all elements followed by a space
	for(int i = 0; i < coll.size(); ++i)
		cout << coll[i] << ' ';
	cout << endl;
}*/

//3. array 大小指定，不可以改变元素个数
/*
#include <array>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//array container of 5 string elements;
	array<string, 5> coll = {"hello", "world"};

	//print each element with its index on a line
	for(int i = 0; i < coll.size(); ++i)
		cout << i << ": " << coll[i] << endl;
}*/

//4.List学习: list<>是由双向列表实现，list当中的每个元素都需要一部分指示前导元素和后继元素
//list<>不提供随机访问,访问速度线性变化，较慢。但在任何位置上执行增加或删除元素都比较迅速（中段移动元素比vector和deque快很多）

//#include <list>
//#include <iostream>

//using namespace std;

//int main()
//{
	/*
	list<char> coll;								//list container for character elements
	
	//append elements from 'a' to 'z'
	for(char c = 'a'; c <= 'z'; ++c)
		coll.push_back(c);

	//print all elements:
	//-use range-based for loop
	for(auto elem : coll)
		cout << elem << ' ';	//这里是对coll的一部分的拷贝，可以修改如下
	
	 *
	 * for(auto &elem : coll )
	 *		... //这里可以对对应的元素进行修改，但如果只想对元素进行读取,不想修改元素该怎么做?
	 *

	 *
	 * template<typename T>
	 * void printElements(const T& coll){
	 *	for(const auto &elem : coll)
	 *		std::cout << elem << std::endl;
	 * 

	cout << endl;*/
	/*
	list<char> coll;							//list container for character elements
	//append elements from 'a' to 'z'
	for(char c = 'a'; c <= 'z'; ++c)
		coll.push_back(c);

	//print all elements
	//-while there a elements
	//-print and remove the first element
	while(!coll.empty()){
		cout << coll.front() << ' ';
		coll.pop_front();
	}
	cout << endl;
	*/
//}

//forward list
//5.forward list 本质上是一个受限制的list，不支持"后退移动"或"效率低下"的操作
/*
#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
	//create forward-list container for some prime numbers;
	forward_list<long> coll = {2, 3, 5, 7, 11, 13, 17};

	//resize two times
	//-note:poor performances
	coll.resize(9);
	coll.resize(10, 99);

	//print all elements
	for(const auto elem : coll)
		cout << elem << ' ';
	cout << endl;
}*/

// 6.Multiset实例
/*#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	multiset<string> cities{"Braunschweig", "Hanover", "Frankfurt", "New York", "Chicago", "Toronto", "Paris", "Frankfurt"};

	//print each element:
	for(const auto& elem : cities)
		cout << elem << " ";
	cout << endl;

	//insert additional values:
	cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

	//print each element:
	for(const auto &elem: cities)
		cout << elem << " ";
	cout << endl;
}*/

// 7. multimap实例
/*
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	multimap<int, string> coll;						//container for int/string values
	
	// insert some elements in arbitrary order
	// - a value with key 1 gets insertd twice
	coll = {{5, "tagged"}, {2, "a"}, {1, "this"}, {4, "of"}, {6, "strings"}, {1, "is"}, {3, "multimap"} };

	// print all element values
	// - element member second is the value
	for(auto elem : coll)
		cout << elem.second << ' ';

	cout << endl;
}*/

//8. unordmultiset.cpp
/*
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	unordered_multiset<string> cities{ "Braunschweig", "Hanover", "Frankfurt", "New York", "Chicago", "Toronto", "Paris", "Frankfurt" };
	
	//print each element:
	for(const auto& elem : cities)
		cout << elem << " ";
	cout << endl;

	//insert additional values
	cities.insert( {"London", "Munich", "Hanover", "Braunschweig"} );

	// print each elements
	for(const auto &elem : cities)
		cout << elem << " ";
	cout << endl;
}*/

// 9.unordmap 实例
/*
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	unordered_map<string, double> coll{{"tim", 9.9}, {"struppi", 11.77}};

	//square the value of each element
	for(pair<const string, double> &elem : coll)
		elem.second *= elem.second;

	// print each element(key and value):
	for(const auto &elem : coll)
		cout << elem.first << ": " << elem.second << endl;

	return 0;
}*/

/*
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//type of the container:
	// - unordered_map: elments are key/value pairs
	// - string: key have type string
	// - float: values have type float
	unordered_map<string, float> coll;
	
	//insert some elements into the collection
	// - using the syntax of an associative array
	coll["VAT1"] = 0.16;
	coll["VAT2"] = 0.07;
	coll["Pi"]   = 3.1415;
	coll["an arbitrary number"] = 4983.223;
	coll["Null"] = 0;

	//change value
	coll["VAT1"] += 0.03;

	//print difference of VAT values
	cout << "VAT difference: " << coll["VAT1"] - coll["VAT2"] << endl;

}*/

// 这里是对容器的专有成员函数begin()和end()学习
/*
#include <list>
#include <iostream>

using namespace std;

int main()
{
	list <char> coll;		//list container for character elements
	
	// append elements from 'a' to 'z'
	for( char c = 'a'; c <= 'z'; ++c)
		coll.push_back(c);

	// print all elments
	// - iterate over all elements
	list<char>::const_iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos)
		cout << *pos << ' ';
	cout << endl;
}*/

// 观察更多几个关联式及无序容器的实例

// 1、C++11 之前的set
/*
#include <set>
#include <iostream>

int main()
{
	//type of the collection
	typedef std::set<int> IntSet;

	IntSet coll;									//Set container for int values
	//insert elements from 1 to 6 in arbitrary order
	// - note that there are two calls of insert() with value 1
	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1);
	coll.insert(6);
	coll.insert(2);

	// print all elements 
	// - iterate over all elements
	IntSet::const_iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << ' ';
	std::cout << std::endl;
}*/

//2、使用无序的Multiset
/*
#include <unordered_set>
#include <iostream>

in main()
{
	//unordered multiset container for int values
	std::unordered_multiset<int> coll;
	
	//insert some elements
	coll.insert({1, 3, 5, 7, 11, 13, 17, 19, 23, 27, 1});

	//print all elements
	for(auto elem : coll)
		std::cout << elem << " ";
	std::cout << std::endl;

	//insert one more element
	coll.insert(25);

	//print all elements again
	for(auto elem : coll)
		std::cout << std::endl;
	std::cout << std::endl;
}*/

//1. 这里看一个简单的STL算法中的用法
/*
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	// create vector with elements from 1 to 6 in arbitrary order
	vector<int> coll = { 2, 5, 4, 1, 6, 3};
	
	//find and print minimum and maximum elements
	auto minpos = min_element(coll.cbegin(), coll.cend());
	cout << "min: " << *minpos << endl;
	auto maxpos = max_element(coll.cbegin(), coll.cend());
	cout << "max: " << *maxpos << endl;

	//sort all elements
	sort(coll.begin(), coll.end());

	// find the first element with value 3
	// - no cbegin()/cend() because later we modify the elements pos 3 referes to 
	auto pos3 = find(coll.begin(), coll.end(),							// range
					 3);
	// reverse the order of the found element with value 3 and all following elements
	reverse(pos3, coll.end());

	// print all elements
	for(auto elem : coll)
		cout << elem << " ";
	cout << endl;
}*/

//2.这里看当平台不支持C++11标准的情况下，替换的程序该怎么写
/*
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	//create vector with elements from 1 to 6 in arbitrary order
	vector<int> coll;
	coll.push_back(2);
	coll.push_back(5);
	coll.push_back(4);
	coll.push_back(1);
	coll.push_back(6);
	coll.push_back(3);

	//find and print minimum and maximum elements
	vector<int>::const_iterator minpos = min_element(coll.begin(), coll.end());
	cout << "min: " << *minpos << endl;
	
	vector<int>::const_iterator maxpos = max_element(coll.begin(), coll.end());
	cout << "max: " << *maxpos << endl;

	// sort all elements
	sort(coll.begin(), coll.end());

	//find the first element with value 3
	vector<int>::iterator pos3;
	pos3 = find(coll.begin(), coll.end(),				//range
			    3);

	//reverse the order of the found element with value 3 and all following elements
	reverse(pos3, coll.end());

	//print all elements
	vector<int>::const_iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos)
		cout << *pos << ' ';
	cout << endl;
}*/

// 3. 对容器内区间操作的学习
/*
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<int> coll;

	//insert elements from 20 to 40
	for(int i = 20; i <= 40; ++i)
		coll.push_back(i);

	// find position of element with value 3
	// - there is none, so pos3 get coll.end()
	auto pos3 = find(coll.begin(), coll.end(),				//range
					 3);									//value

	//reverse the order of elements between found element and the end
	//-because pos3 is coll.end(), it reverses an empty an emptry range.
	reverse(pos3, coll.end());

	//find position of values 25 and 35
	list<int>::iterator pos25, pos35;
	pos25 = find(coll.begin(), coll.end(),					//range
				 25);										//value
	pos35 = find(coll.begin(), coll.end(),					//range
				 35);										//value

	// print the maximum of the corresponding range
	// - note: including pos25 but excluding pos35
	cout << "max: " << *max_element(pos25, pos35) << endl;

	//process the elements including the last position
	cout << "max: " << *max_element(pos25, ++pos35) << endl;	//想想看这里是为什么会有变化?
}*/

/*
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> coll2;

	//resize destination to have enough room for the overwriting algorithm
	coll2.resize(coll1.size());

	//copy elements from first into second collection
	//-overwrites existing elements in destination
	copy(coll1.cbegin(), coll1.cend(), coll2.begin());

	//create third collection with enough room
	//-initial size is passed as parameter
	deque<int> coll3(coll1.size());

	//copy elements from first into third collection
	copy(coll1.cbegin(), coll1.cend(), coll3.begin());
}*/

/*
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>
using namespace std;

int main()
{
	list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	//copy the elements of coll1 into coll2 by appending them
	vector<int> coll2;
	copy(coll1.cbegin(), coll1.cend(),					// source 
		 back_inserter(coll2));							// destination

	// copy the elements of coll1 into coll3 by inserting them at the front
	// - reverses the order of the elements
	deque<int> coll3;
	copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));

	//copy elements of coll1 into coll4
	// -only inserter that works for associative collections
	set<int> coll4;
	copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
}*/
/*
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	vector<string> coll;

	// read all words from the standard input
	// - source: all strings until end-of-file(or error)
	// - destination: coll(inserting)
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(coll));

	// sort elements
	sort(coll.begin(), coll.end());

	// print all elements without duplicates
	// - source: coll
	// - destination: standard output(with newline between elements)
	unique_copy(coll.cbegin(), coll.cend(),								//source
			    ostream_iterator<string>(cout, "\n"));					//destination

}*/

/*
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9
	for(int i = 1; i <= 9; i++)
		coll.push_back(i);

	//print all element in reverse order
	copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout, " "));
	cout << endl;
}*/

//这里主要是对weak_ptr的学习
/*这是书上例子的代码，没有扩展，下面看下标准答案中的写法
class StrBlobPtr{
	public:
		StrBlobPtr(): curr(0){ }
		StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz){ }
		std::string& deref() const;
		StrBlobPtr& incr();												//前缀递增
	private:
		//若检查成功，check返回一个指向vector的shared_ptr
		std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

		//保存一个weak_ptr，意味着底层vector可能会被销毁
		std::weak_ptr<std::vector<std::string>> wptr;
		std::size_t curr;												//在数组中当前位置
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const{
	auto ret = wptr.lock();												//vector是否还存在
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}*/

// 这里学习的是如何用一个合法的迭代器对STL的算法的扩充(后面再看看)
// stl/print.hpp
/*
#include <iostream>
#include <string>

//PRINT_ELEMENTS()
// - prints optional string optstr followed by 
// - all elements of the collection coll
// - in one line, separated by space

template<typename T>
inline void PRINT_ELEMENTS(const T& coll, cosnt std::string& optstr=""){
	std::cout << optstr;
	for(const auto& elem : coll)
		std::cout << elem << ' ';
	std::cout << std::endl;
}
*/
//这里主要看的是STL算法造成的吃惊行为
//stl/remove1.cpp
/*
#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<int> coll;

	//insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i){
		coll.push_front(i);
		coll.push_back(i);
	}

	//print all elements of the collection
	cout << "pre:	";		
	copy(coll.cbegin(), coll.cend(),					//source 
		 ostream_iterator<int>(cout, " "));				//destination
	cout << endl;

	// remove all elements with value 3
	remove(coll.begin(), coll.end(),					//range
		   3);

	// print all elements of the collection
	cout << "post:	";
	copy(coll.cbegin(), coll.cend(),					//source
		 ostream_iterator<int>(cout, " "));
	cout << endl;
 }*/

// stl/remove2.cpp
/*
#include <algorithm>
#include <iterator>
#include <list>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<int> coll;

	//insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i){
		coll.push_front(i);
		coll.push_back(i);
	}

	// print all elements of the collection
	copy(coll.cbegin(), coll.cend(),										// resource
		 ostream_iterator<int>(cout, " "));									// destination	->这个语法一定要学会
	cout << endl;

	//remove all elements with value 3
	//- retain new end;
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

	// print resulting elements of the collection
	copy(coll.begin(), end,
		ostream_iterator<int>(cout, " "));
	cout << endl;

	//print number of removed elements
	cout << "number of elements: "
		 << distance(end, coll.end()) << endl;

	//remove "removed" elements
	coll.erase(end, coll.end());

	//print all elements of the modified collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}*/

/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//function that prints the passed argument
void print(int elem){
	cout << elem << ' ';
}

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9
	for(int i = 1; i <= 9; ++i)
		coll.push_back(i);

	//print all elements
	for_each(coll.cbegin(), coll.cend(),							// source 
			print);													// operation
	cout << endl;
}*/

// stl/transform1.cpp
/*
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>


template<typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr=""){
	std::cout << optstr;
	for(const auto& elem : coll)
		std::cout << elem << ' ';
	std::cout << std::endl;
}

int square(int value){
	return value * value;
}

int main()
{
	std::set<int> coll1;
	std::vector<int> coll2;

	//insert elements from 1 to 9 into coll1
	for(int i = 1; i <= 9; ++i)
		coll1.insert(i);

	PRINT_ELEMENTS(coll1, "initialized: ");

	//transform each element coll1 to coll2
	//-square transformed values
	std::transform(coll1.cbegin(), coll1.cend(),		// source
				   std::back_inserter(coll2),			// destination
				   square);								// operation
	PRINT_ELEMENTS(coll2, "squared: ");
}*/

// stl/prime1.cpp
// 这里学习的是単参判断式
/*
#include <list>
#include <algorithm>
#include <iostream>
#include <cstdlib>					// for abs()函数利用
using namespace std;

//predicate, which returns whether an integer is a prime number
bool isPrime(int number){
	//ignore negatie sign
	number = abs(number);

	//0 and 1 are no prime numbers
	if(number == 0 || number == 1)
		return false;
	
	//find divisor that divides without a reminder
	int divisor;
	for(divisor = number/2; number % divisor != 0; --divisor);

	//if no divisor greater than 1 is found, it is a primer number
	return divisor == 1;
}

int main()
{
	list<int> coll;

	//insert elements from 24 to 30
	for(int i = 24; i <= 30; ++i)
		coll.push_back(i);

	//search for prime number
	auto pos = find_if(coll.cbegin(), coll.cend(),				// range
					   isPrime);								// predicate

	if(pos != coll.end()){
		// found
		cout << *pos << " is first prime number found" << endl;
	}else{
		// not found
		cout << "no prime number found." << endl;
	}
}*/

/*
#include <algorithm>
#include <deque>
#include <string>
#include <iostream>
using namespace std;

class Person{
	public:
		string firstname() const;
		string lastname() const;
		...
};

//  binary function predicate
//- returns whether a person is less than another person

bool personSortCriterion(const Person& p1, const Person& p2){
	// a person is less than another person
	// - if the last name is less
	// - if the last name is equal and the first name is less
	return p1.lastname() < p2.lastname() ||  (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
}

int main()
{
	deque<Person> coll;
	...
	sort(coll.begin(), coll.end(),					// range
		 personSortCriterion);						// sort criterion
}*/

//stl/lambda1.cpp
//这里主要通过lambda函数来实现找到数值在x和y之间的第一个元素

/*
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	deque<int> coll = {1, 3, 19, 5, 13, 7, 11, 2, 17};

	int x =	5;
	int y = 12;
	auto pos = find_if(coll.cbegin(), coll.cend(),		//range
					   [=](int i ){ return i > x && i < y; });
	cout << "first elem > 5 and < 12: " << *pos << endl;
}*/

// 以Lambda作为序列准则来进行判断
// stl/sort2.cpp

/*
#include <algorithm>
#include <deque>
#include <string>
#include <iostream>
using namespace std;

class Person{
	public:
		string firstname() const;
		string lastname() const;
		...
};

int main()
{
	deque<Person> coll;
	...
	
	// sort Persons according to lastname( and the firstname ): 
	sort(coll.begin(), coll.end(),												//range
		 [] (const Person &p1, const Person &p2){								//sort criterion
		 return p1.lastname() < p2.lastname() || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname()) 
		 });
	...
}*/

//stl/foreach2.cpp
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// simple function object that prints the passed argument
class PrintInt{
	public:
		void operator()(int elem) const{
			cout << elem << " ";
		}
};

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9
	for(int i = 1; i <= 9; ++i){
		coll.push_back(i);
	}

	//print all elements
	for_each(coll.cbegin(), coll.cend(),	//range
			 PrintInt());					//operation
	cout << endl;
}
*/
/*
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;


template<typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr=""){
	std::cout << optstr;
	for(const auto& elem : coll)
		std::cout << elem << ' ';
	std::cout << std::endl;
}

// function object that adds the value with which it is initialized
class AddValue{
	private:
		int theValue;										//the value to add
	public:
		// constructor initializes the value to add
		AddValue(int v): theValue(v){}

		// the "function call" for the element adds the value
		void operator()(int &elem) const{
			elem += theValue;
		}
};

int main()
{
	list<int> coll;
	
	//insert elements from 1 to 9
	for(int i = 1; i <= 9; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll, "initialized:			");

	//add value 10 to each elements
	for_each(coll.begin(), coll.end(),						// range 
			 AddValue(10));									// operation

	PRINT_ELEMENTS(coll, "after adding 10:		");

	//add value of first element to each element
	for_each(coll.begin(), coll.end(),						// range
			 AddValue(*coll.begin()));						// operation
	PRINT_ELEMENTS(coll, "after adding first element:	");
}*/

//stl/fo1.cpp
/*
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include "print.hpp"
using namespace std;

int main()
{
	deque<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19};

	PRINT_ELEMENTS(coll, "initialized: ");

	//negate all values in coll
	transform(coll.cbegin(), coll.cend(),					//source
			  coll.begin(),									//destination
			  negate<int>());								//operation
	PRINT_ELEMENTS(coll, "negated:		");

	//square all vlaues in coll
	transform(coll.cbegin(), coll.cend(),					//first source
			  coll.cbegin(),								//second source
			  coll.begin(),									//destination
			  multiplies<int>());							//operation multiplies对象函数将两个序列中的对象一次相乘
	PRINT_ELEMENTS(coll, "squared:		");
}*/

//stl/binder.cpp
/*
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
#include "print.hpp"

using namespace std;
using namespace std::placeholders;								//保证能够使用_1或_2作为占位符

int main()
{
	set<int, greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> coll2;

	//NOTE: due to the sorting criterion greater<> elements have reverse order:
	PRINT_ELEMENTS(coll1, "initialized:		");

	//transform all elements into coll2 by multiplying them with 10
	transform(coll1.cbegin(), coll1.cend(),						// source 	
			  back_inserter(coll2),								// destination
			  bind(multiplies<int>(), _1, 10));					// operation
	PRINT_ELEMENTS(coll2, "transformed:	");

	//replace value equal to 70 with 42
	replace_if(coll2.begin(), coll2.end(),						// range
			   bind(equal_to<int>(), _1, 70),					// replace criterion
			   42);												// new value
	PRINT_ELEMENTS(coll2, "replaced:		");

	//remove all elements with values between 50 and 80
	coll2.erase(remove_if(coll2.begin(), coll2.end(),
						  bind(logical_and<bool>(),
							  bind(greater_equal<int>(), _1, 50),
							  bind(less_equal<int>(), _1, 80))),
				coll2.end());
	PRINT_ELEMENTS(coll2, "removed:			");
}
*/

// fo/foreach3.cpp
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function object to process the mean value
class MeanValue{
	private:
		long num;				// number of elements
		long sum;				// sum of all element values
	public:
		// constructor
		MeanValue(): num(0), sum(0){}

		// "function call"
		// - process one more element of the sequence
		void operator()(int elem){
			++num;						// increment count
			sum += elem;				// add value
		}

		// return mean value
		double value(){
			return static_cast<double>(sum) / static_cast<double>(num);
		}
};


int main()
{
	vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8};

	// process and print mean value
	MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
	cout << "mean value:	" << mv.value() << endl;
}*/

/*
#include <iostream>
#include <list>
#include <algorithm>
#include "print.hpp"
using namespace std;

class Nth{																	// function object that return true for the nth call
	private:
		int nth;															// call for which to return true
		int count;															// call counter
	public:
		Nth(int n) : nth(n), count(0){ }
		bool operator()(int){
			return ++count == nth;
		}
};

int main()
{
	list<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	PRINT_ELEMENTS(coll, "coll:		");

	// remove third element
	list<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(), Nth(3));
	coll.erase(pos, coll.end());

	PRINT_ELEMENTS(coll, "3rd removed:	");		//这里有点奇怪,后面再看看
}*/

// fo/bind1.cpp
/*
#include <functional>
#include <iostream>

int main()
{
	auto plus10 = std::bind(std::plus<int>(), std::placeholders::_1, 10);
	std::cout << "10:	" << plus10(7) << std::endl;
	auto plus10times2 = std::bind(std::multiplies<int>(), std::bind(std::plus<int>(), std::placeholders::_1, 10), 2);
	std::cout << "+10 *2" << plus10times2(7) << std::endl;

	auto pow3 = std::bind(std::multiplies<int>(), std::bind(std::multiplies<int>(), std::placeholders::_1, std::placeholders::_1), std::placeholders::_1);
	std::cout << "x*x*x" << pow3(7) << std::endl;

	auto inversDivide = std::bind(std::divides<double>(), std::placeholders::_2, std::placeholders::_1);
	std::cout << "invdiv:	" << inversDivide(49, 7) << std::endl;
}*/
/*
#include <iostream>
#include <algorithm>
#include <functional>
#include <locale>
#include <string>
using namespace std;
using namespace std::placeholders;

char myToupper(char c){
	std::locale loc;
	return std::use_facet<std::ctype<char> >(loc).toupper(c);
}

int main()
{
	string s("Internationalization");
	string sub("Nation");

	// search substring case insensitive
	string::iterator pos;
	pos = search(s.begin(), s.end(), sub.begin(), sub.end(), bind(equal_to<char>(), bind(myToupper, _1), bind(myToupper, _2)));
	if(pos != s.end())
		cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;
}*/
/*
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

class Person{
	private:
		string name;
	public:
		Person(const string& n): name(n){}
		void print() const{ cout << name << endl; }
		void print2(const string& prefix) const{ cout << prefix << name << endl; }
};

int main()
{
	vector<Person> coll = { Person("Tick"), Person("Trick"), Person("Track") };

	// call member function print() for each person
	for_each(coll.begin(), coll.end(), bind(&Person::print, _1));
	cout << endl;

	// call member function print2() with additional argument for each person
	for_each(coll.begin(), coll.end(), bind(&Person::print2, _1, "Person:	"));
	cout << endl;

	// call print2() for temporary Person
	bind(&Person::print2, _1, "This is:	")(Person("nico"));
}*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include "fopow.hpp"
using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// print 3 raised to the power of all elements
	transform(coll.begin(), coll.end(), ostream_iterator<float>(cout, " "), bind(fopow<float, int>(), 3, _1));
	cout << endl;

	// print all elements raised to the power of 3
	transform(coll.begin(), coll.end(), ostream_iterator<float>(cout, " "), bind(fopow<float, int>(), _1, 3));
	cout << endl;
}*/

/*
#include <iostream>

int main()
{
	auto plus10 = [](int i){ return i+10 };
	std::cout << "+10:	" << plus10(7) << std::endl;
	auto plus10times2 = [](int i){ return (i+10)*2;	 };
	std::cout << "+10 *2:	" << plus10times2(7) << std::endl;
	auto pow3 = [](int i){ return i*i*i; }
	std::cout << "x*x*x:	" << pow3(7) << std::endl;
	auto inversDivide = [](double d1, double d2){ return d2 / d1; };
	std::cout << "invidiv:	" << inversDivde(49, 7) << std::endl;
}*/

// fo/lambda2.cpp
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// process and print mean value
	long sum = 0 ;
	for_each(coll.begin(), coll.end(),			// range
			 [&sum](int elem){ sum += elem; });
	double mv = static_cast<double>(sum)/static_cast<double>(coll.size());
	cout << "mean value:	" << mv << endl;
}*/

// fo/lambda3.cpp
/*
#include <iostream>
#include <list>
#include <algorithm>
#include "print.hpp"
using namespace std;

int main()
{
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	PRINT_ELEMENTS(coll, "coll:		");

	// remove third element
	list<int>::iterator pos;
	int count = 0;
	pos = remove_if(coll.begin(), coll.end(),				//range
					[count](int) mutable{ return ++count == 3; });
	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "3rd,removed:	");
}*/

// fo/lambda4.cpp
/*
#include <iostream>
#include <algorithm>
#include <locale>
#include <string>
using namespace std;

char myToupper(char c){
	std::locale loc;
	return std::use_facet<std::ctype<char> >(loc).toupper(c);
}

int main()
{
	string s("Internationalization");
	string sub("Nation");

	// search substring case insensitive
	string::iterator pos;
	pos = search(s.begin(), s.end(), sub.begin(), sub.end(), [](char c1, char c2){ return myToupper(c1)==myToupper(c2); });
	if(pos != s.end())
		cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;
}*/

// fo/lambda5.cpp
/*
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

class Person{
	private:
		string name;
	public:
		Person(const string& n): name(n){}
		void print() const{
			cout << name << endl;
		}
		void print2(const string& prefix) const{
			cout << prefix << name << endl;
		}

};

int main()
{
	vector<Person> coll = { Person("Tick"), Person("Trick"), Person("Track") };

	// call member function print() for each person
	for_each(coll.begin(), coll.end(), [](const Person& p){ p.print();	});
	cout << endl;

	// call member function print2() with additional argument for each person
	for_each(coll.begin(), coll.end(), [](const Person& p){ p.print2("Person: "); });
}*/

// 这里的例子是示范如何输出每一个元素
/*
#include "algostuff.hpp"
using namespace std;

void print(int elem){
	cout << elem << ' ';
}

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll, 1, 9);

	// call print() for each element
	// for_each(coll.cbegin(), coll.cend(), [](int elem){ cout << elem << " "; });
	for_each(coll.cbegin(), coll.cend(), print);
	cout << endl;
};
*/
// 下面看如何改变每一个元素

/*
#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll, 1, 9);

	// add 10 to each element
	for_each(coll.begin(), coll.end(), [](int& elem){ elem+= 10; });
	PRINT_ELEMENTS(coll);

	// add value of first element to each element
	for_each(coll.begin(), coll.end(), [=](int& elem){ elem += *coll.begin(); });
	PRINT_ELEMENTS(coll);
}
*/

/*

#include "algostuff.hpp"
using namespace std;

// function object to process the mean value
class MeanValue{
	private:
		long num;			// number of elements
		long sum;			// sum of all element values
	public:
		// constructor
		MeanValue() : num(0), sum(0){ }

		// function call
		void operator()(int elem){
			num++;			// increment count
			sum += elem;	// add value
		}

		// return mean value(implicit type conversion)
		operator double(){
			return static_cast<double>(sum) / static_cast<double>(num);				
		}
};

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll, 1, 8);

	// process and print mean value
	double mv = for_each(coll.begin(), coll.end(), MeanValue());
	cout << "Mean Value:	" << mv << endl;
}*/

// algo/count1.cpp
/*
#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	int num;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// count elements with value 4
	num = count(coll.cbegin(), coll.cend(), 4);
	cout << "number of elements equal to 4:	" << num << endl;
	
	// count elements with even value
	num = count_if(coll.cbegin(), coll.cend(), [](int elem){ return elem % 2 == 0; });
	cout << "number of elements with even value: " << num << endl;

	// count elements that are greater than value 4
	num = count_if(coll.cbegin(), coll.cend(), [](int elem){ return elem > 4; });

	cout << "number of elements greater than 4:	" << num << endl;
}*/

/*
#include <cstdlib>
#include "algostuff.hpp"
using namespace std;

bool absLess(int elem1, int elem2){
	return abs(elem1) < abs(elem2);
}

int main()
{
	deque<int> coll;
	
	INSERT_ELEMENTS(coll, 2, 6);
	INSERT_ELEMENTS(coll, -3, 6);

	PRINT_ELEMENTS(coll);

	// process and print minimum and maximum
	cout << "minimum: "
		 << *min_element(coll.cbegin(), coll.cend()) << endl;

	cout << "maximum: "
		 << *max_element(coll.cbegin(), coll.cend()) << endl;

	// print min and max and their distance using minmax_element()
	auto mm = minmax_element(coll.cbegin(), coll.cend());
	cout << "min: " << *(mm.first) << endl;		// print minimum
	cout << "max: " << *(mm.second) << endl;	// print maximum
	cout << "distance: " << distance(mm.first, mm.second) << endl;

	// process and print minimum and maximum of absolute values
	cout << "minimum of absolute values: " << *min_element(coll.cbegin(), coll.cend(), absLess) << endl;
	cout << "maximum of absolute values: " << *max_element(coll.cbegin(), coll.cend(), absLess) << endl;
}*/

// algo/find1.cpp
/*
#include "algostuff.hpp"
using namespace std;
int main()
{
	list<int> coll;
	INSERT_ELEMENTS(coll, 1, 9);
	INSERT_ELEMENTS(coll, 1, 9);

	PRINT_ELEMENTS(coll, "coll:	");

	// find first element with value 4
	list<int>::iterator pos1;
	pos1 = find(coll.begin(), coll.end(), 4);

	// find second element with value 4
	// -note: continue the search behind the first 4(if any)
	list<int>::iterator pos2;
	if(pos1 != coll.end())
		pos2 = find(++pos1, coll.end(), 4);

	// print all elements from first to second 4(both included)
	// -note: now we need the position of the first 4 again(if any)
	if(pos1 != coll.end() && pos2 != coll.end()){
		copy(--pos1, ++pos2, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}*/

// algo/find2.cpp
/*
#include "algostuff.hpp"
using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> coll;
	vector<int>::iterator pos;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll:	");

	// find first element greater than 3
	pos = find_if(coll.begin(), coll.end(), bind(greater<int>(), _1, 3));

	// print its position
	cout << "the "
		 << distance(coll.begin(), pos) + 1
		 << ". element is the first greater than 3" << endl;

	// find first element divisible by 3
	pos = find_if(coll.begin(), coll.end(), [](int elem){ return elem%3 == 0; });
	
	// print its position
	cout << "the "
		 << distance(coll.begin(), pos) + 1 
		 << ". element is the first divisible by 3" << endl;

	// find first element not < 5
	pos = find_if_not(coll.begin(), coll.end(), bind(less<int>(), _1, 5));
	cout << "first value >= 5: " << *pos << endl;
}*/

/*
#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;

	coll = { 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
	PRINT_ELEMENTS(coll);

	// find three consecutive elements with value 7
	deque<int>::iterator pos;
	pos = search_n(coll.begin(), coll.end(), 3, 7);

	// print result
	if(pos != coll.end())
		cout << "three consecutive elements with value 7 "
			 << "start with " << distance(coll.begin(), pos) + 1 
			 << ". elements" << endl;
	else
		cout << "no four consecutive elements with value 7 found " 
			 << endl;

	// find four consecutive odd elements
	pos = search_n(coll.begin(), coll.end(),			// range
				   4,									// count
				   0,									// value
				   [](int elem, int value){ return elem%2 == 1; });

	// print result
	if(pos != coll.end()){
		cout << "first four consecutive odd elements are:	";
		for(int i = 0; i < 4; ++i, ++pos)
			cout << *pos << ' ';
	}
	else
		cout << "no four consecutive elements with value > 3 found";
	cout << endl;
}*/

// algo/search1.cpp
#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	list<int> subcoll;

	INSERT_ELEMENTS(coll, 1, 7);
	INSERT_ELEMENTS(coll, 1, 7);
	INSERT_ELEMENTS(subcoll, 3, 6);

	PRINT_ELEMENTS(coll, "coll:	");
	PRINT_ELEMENTS(subcoll, "subcoll:	");

	// search first occurrence of subcoll in coll
	deque<int>::iterator pos;
	pos = search( coll.begin(), coll.end(), subcoll.begin(), subcoll.end() );


	// loop while subcoll found as subrange of coll
	while( pos != coll.end() ){
		// print position of first element
		cout << "subcoll found starting with element "
			 << distance(coll.begin(), pos) + 1
			 << endl;

		// search next occurrence of subcoll
		++pos;
		pos = search(pos, coll.end(), subcoll.begin(), subcoll.end() );
	}
}
