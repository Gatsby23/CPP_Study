/*
 * 1. 对Array运用实例的学习
 * *
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include "print.hpp"
using namespace std;

int main()
{
	//create array with 10 ints
	array<int, 10> a = { 11, 22, 33, 44};

	PRINT_ELEMENTS(a);

	// modify last two elements
	a.back() = 9999999;
	a[a.size()-2] = 42;
	// process sum of all elements
	cout << "sum: "
		 << accumulate(a.begin(), a.end(), 0) << endl;

	//negate all elements
	transform(a.begin(), a.end(),		//source
			  a.begin(),				//destination
			  negate<int>());			//operation
	PRINT_ELEMENTS(a);
}*/

//一个vector的简单用法
/*
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	//create empty vector for strings
	vector<string> sentence;

	//reserve memory for five elements to avoid reallocation
	sentence.reserve(5);

	//append some elements
	sentence.push_back("Hello, ");
	sentence.insert(sentence.end(), {"how", "are", "you", "?"}); 

	// print elements separated with spaces
	copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(cout, " "));
	cout << endl;

	// print 'technical data'
	cout << " max_size():	"	<< sentence.max_size() << endl;
	cout << " size():	"	<< sentence.size()	   << endl;
	cout << " capacity():	" << sentence.capacity() << endl;

	//swap second and fourth element
	swap(sentence[1], sentence[3]);

	//insert element "always" before element "?"
	sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

	//assign "!" to the last element
	sentence.back()	= "!";

	// print elements separated with spaces
	copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(cout, " "));
	cout << endl;

	// print some "technical data" again
	cout << " size():	"	<< sentence.size()	<<	endl;
	cout << " capacity():	" << sentence.capacity() << endl;

	// delete last two elements
	sentence.pop_back();
	sentence.pop_back();
	// shrink capacity (since C++11)
	sentence.shrink_to_fit();

	//print some "technical data" again
	cout << " size():	" << sentence.size()	<< endl;
	cout << " capacity():	" << sentence.capacity() << endl;
}*/

//Deque的功效
/*
#include<iostream>
#include<deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	//create empty deque of strings
	deque<string> coll;

	//insert several elements
	coll.assign(3, string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	//print elements separated by newlines
	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
	cout << endl;

	//remove first and last elements
	coll.pop_front();
	coll.pop_back();

	// insert "another" into every element but the first
	for(unsigned i = 1; i < coll.size(); ++i)
		coll[i] = "another " + coll[i];

	//change size to four elements
	coll.resize(4, "resized string");

	//print elements separated by newlines
	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
}*/


//List运用实例
/*
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void printLists(const list<int>& l1, const list<int>& l2){
	cout << "list1: ";
	copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << "list2: ";
	copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
}

int main()
{
	//create two empty lists
	list<int> list1, list2;

	//fill both lists with elements
	for(int i = 0; i < 6; ++i){
		list1.push_back(i);
		list1.push_front(i);
	}
	printLists(list1, list2);

	// insert all elements of list1 before the first element with 3 of list2
	// -find() returns an iterator to the frist element with value 3
	list2.splice(find(list2.begin(), list2.end(), 3)				// destination position
				 , list1);											// source list
	printLists(list1, list2);

	//move first element of list2 to the end
	list2.splice(list2.end(),					//destination position 
				 list2,							//source list 
				 list2.begin());				//source position
	printLists(list1, list2);

	//sort second list, assign to list1 and remove duplicates
	list2.sort();
	list1 = list2;
	list2.unique();
	printLists(list1, list2);

	// merge both sorted lists into the first list
	list1.merge(list2);
	printLists(list1, list2);
}*/

//cont/forwardlistfind1.cpp
/*
#include <iostream>
#include <forward_list>
#include "print.hpp"
using namespace std;

int main()
{
	forward_list<int> list = { 1, 2, 3, 4, 5, 97, 98, 99 };

	//find the position before the first even element
	auto posBefore = list.before_begin();
	for(auto pos = list.begin(); pos != list.end(); ++pos, ++posBefore){
		if(*pos %2 == 0)
			break;			//element found
	}

	list.insert_after(posBefore, 42);
	PRINT_ELEMENTS(list);
}*/

// cont/forwardlistsplice1.cpp
/*
#include <iostream>
#include <forward_list>
#include "print.hpp"
using namespace std;

int main()
{
	forward_list<int> l1 = { 1, 2, 3, 4, 5 };
	forward_list<int> l2 = { 97, 98, 99 };

	//find 3 in l1
	auto pos1 = l1.before_begin();
	for(auto pb1 = l1.begin(); pb1 != l1.end(); ++pb1, ++pos1){
		if(*pb1 == 3){
			break;	//found
		}
	}

	// find 99 in 12
	auto pos2 = l2.before_begin();
	for(auto pb2 = l2.begin(); pb2 != l2.end(); ++pb2, ++pos2){
		if(*pb2 == 99){
			break;	//found
		}
	}

	//splice 3 from l1 to l2 before 99
	l1.splice_after(pos2, l2,							// destination
					pos1);								// source
	PRINT_ELEMENTS(l1, "l1: ");
	PRINT_ELEMENTS(l2, "l2: ");
}*/

// forward_list 运用实例
/*
#include <forward_list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

void printLists(const string& s, const forward_list<int>& l1, const forward_list<int>& l2){
	cout << s << endl;
	cout << "list1: ";
	copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << "list2: ";
	copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	//create two forward lists
	forward_list<int> list1 = {1, 2, 3, 4};
	forward_list<int> list2 = {77, 88, 99};
	printLists("initial:", list1, list2);

	//insert six new element at the beginning of list2
	list2.insert_after(list2.before_begin(), 99);
	list2.push_front(10);
	list2.insert_after(list2.before_begin(), {10, 11, 12, 13});
	printLists("6 new elems: ", list1, list2);

	//insert all elements of list2 at the begining of list1
	list1.insert_after(list1.before_begin(), list2.begin(), list2.end());
	printLists("list2 into list1: ", list1, list2);

	//delete second element and elements after element with value 99
	list2.erase_after(list2.begin());
	list2.erase_after(find(list2.begin(), list2.end(), 99), list2.end());
	printLists("delete 2nd and after 99:", list1, list2);
	
	//sort list1, assign it to list2, and remove duplicates
	list1.sort();
	list2 = list1;
	list2.unique();
	printLists("sorted and unique:", list1, list2);

	//merge both sorted lists into list1
	list1.merge(list2);
	printLists("merged: ", list1, list2);
}*/

/*

#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> c;
	
	c.insert(1);
	c.insert(2);
	c.insert(3);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	cout << "equal_range(3): " << *c.equal_range(3).first << " "
							   << *c.equal_range(3).second << endl;
	cout << endl;
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_range(5): " << *c.equal_range(5).first << " "
							   << *c.equal_range(5).second << endl;
}*/

//Set 和 MultiSet的运用实例
/*
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	//type of collection
	//no duplicates
	//elements are integral values
	
	//descending order
	set<int, greater<int>> coll1;

	//insert eleemnts in random order using different member functions
	coll1.insert({4, 3, 5, 1, 6, 2});
	coll1.insert(5);

	//print all elements
	for(int elem : coll1){
		cout << elem << " ";
	}
	cout << endl;

	//insert 4 again and process return value
	auto status = coll1.insert(4);
	if(status.second){
		cout << "4 inserted as element "
			 << distance(coll1.begin(), status.first) + 1 << endl;
	}else{
		cout << "4 already exists" << endl;
	}

	//assign elements to another set with  ascending order
	set<int> coll2(coll1.cbegin(), coll1.cend());

	//print all elements of the copy using stream iterators
	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//remove all elements up to element with value 3
	coll2.erase(coll2.begin(), coll2.find(3));
	
	//remove all elements with value 5
	int num;
	num = coll2.erase(5);
	cout << num << " element(s) removed" << endl;

	//print all elements
	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

}*/

// cont/setcmp1.cpp
/*
#include <iostream>
#include <set>
#include "print.hpp"
using namespace std;

//type for runtime sorting criterion
class RuntimeCmp{
	public:
		enum cmp_mode {normal, reverse};
	private:
		cmp_mode mode;
	public:
		// constructor for sorting criterion
		// -default criterion uses value normal
		RuntimeCmp(cmp_mode m = normal) : mode(m){}
		// comparison of elements
		// -member function for any element type
		template<typename T>
		bool operator()(const T& t1, const T& t2) const{
			return mode==normal ? t1<t2 : t2<1;
		}
		//comparsion of sorting criteria
		bool operator==(const RuntimeCmp& rc) const{
			return mode == rc.mode;
		}
};

//type of a set that uses this sorting criterion
typedef set<int, RuntimeCmp> IntSet;

int main()
{
	// create, fill and print set with normal element order
	// -uses default sorting
	IntSet coll1 = { 4, 7, 5, 1, 6, 2, 5 };
	PRINT_ELEMENTS(coll1, "coll1: ");

	//create sorting criterion with reverse element order
	RuntimeCmp reverse_order(RuntimeCmp::reverse);

	//create, fill, and print set with reverse element order
	IntSet coll2(reverse_order);
	coll2 = { 4, 7, 5, 1, 6, 2, 5 };
	PRINT_ELEMENTS(coll2, "coll2: ");

	// assign elements AND sorting criterion
	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS(coll1, "coll1: ");

	//just to make sure...
	if(coll1.value_comp() == coll2.value_comp()){
		cout << "coll1 and coll2 have the same sorting criterion" << endl;
	}else{
		cout << "coll1 and coll2 have a different sorting criterion" << endl;
	}
}*/

// cont/map1.cpp
/*
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	map<string, double> coll{ {"tim", 9.9}, {"struppi", 11.77} };

	//square the value of each element
	for_each(coll.begin(), coll.end(), [](pair<const string, double>& elem){
			 elem.second *= elem.second; });
	//print each element
	for_each(coll.begin(), coll.end(), [](const map<string, double>::value_type& elem){
				cout << elem.first << ": " << elem.second << endl;
			});
}*/

//将map当做关联式数组来使用
/*
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// create map/ associative array
	// keys are strings
	// -values are floats
	typedef map<string, float> StringFloatMap;

	StringFloatMap stocks;										//create empty container

	//insert some elements
	stocks["BASF"] = 369.50;
	stocks["VW"] = 413.50;
	stocks["Daimler"] = 819.00;
	stocks["BMW"] = 834.00;
	stocks["Siemens"] = 842.20;

	//print all elements
	StringFloatMap::iterator pos;
	cout << left;						//left-adjust values
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
		cout << "stock: " << setw(12) << pos->first << "price: " << pos->second << endl;			//这里setw设置字宽度，默认右对齐
	cout << endl;

	//boom all prices doubled
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
		pos->second *= 2;

	//print all elements
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
		cout << "stock: " << setw(12) << pos->first << "price: " << pos->second << endl;
	cout << endl;

	// rename key from "VW" to "Volkswagen"
	// -provided only by exchanging element
	stocks["Volkswagen"] = stocks["VW"];
	stocks.erase("VW");

	//print all elements
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
		cout << "stock: " << setw(12) << pos->first << "price: " << pos->second << endl;
}*/

//将Multimap当做字典
/*
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// create multimap as string/string dictionary
	multimap<string, string> dict;
	
	// insert some elements in random order
	dict.insert({ {"day", "Tag"}, {"strange", "fremd"}, {"car", "Auto"}, {"smart", "elegant"}, {"trait", "Merkmal"}, {"strange", "seltsam"},
			    {"smart", "raffiniert"}, {"smart", "klug"}, {"clever", "raffiniert"} });

	//print all elements
	cout.setf(ios::left, ios::adjustfield);
	cout << ' ' << setw(10) << "english " << "german " << endl;
	cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;
	for(const auto& elem : dict)
		cout << ' ' << setw(10) << elem.first << elem.second << endl;
	cout << endl;

	// print all values for key "smart"
	string word("smart");
	cout << word << ": " << endl;
	for(auto pos = dict.lower_bound(word); pos != dict.upper_bound(word); ++pos)
		cout << "	" << pos->second << endl;

	// print all keys for value "raffiniert"
	word = ("raffiniert");
	cout << word << ": " << endl;
	for(const auto& elem : dict){
		if(elem.second == word)
			cout << "	" << elem.first << endl;
	}

}*/

//查找具有某特定value的元素
//cont/mapfind1.cpp
/*
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	// map with floats as key and value
	// - initializing keys and values are automatically converted to float
	map<float, float> coll = {{1, 7}, {2, 4}, {3, 2}, {4, 3}, {5, 6}, {6, 1}, {7, 3} };

	//search an element with key3.0(logarithmic comlexity)
	auto posKey = coll.find(3.0);
	if(posKey != coll.end())
		cout << "key 3.0 found (" << posKey->first << ":" << posKey->second << ")" << endl; 
	
	//search an element with value3.0(linear complexity)
	auto posVal = find_if(coll.begin(), coll.end(), [](const pair<float, float>& elem){ return elem.second == 3.0; });
	if(posVal != coll.end())
		cout << "vale 3.0 found (" << posVal->first << ":" << posVal->second << ")" << endl;
}*/

// cont/mapcmp1.cpp
/*
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// function object to compare string
// -allows you to set the comparison criterion at runtime
// -allows you to compare case insensitive
class RuntimeStringCmp{
	public:
		// constants for the comparison criterion
		enum cmp_mode{normal, nocase};
	private:
		// actual comparison mode
		const cmp_mode mode;

		//auxiliary function to compare case insensitive
		static bool nocase_compare(char c1, char c2){
			return toupper(c1) < toupper(c2);
		}
	
	public:
		//constructor: initializes the comparison criterion
		RuntimeStringCmp(cmp_mode m = normal) : mode(m){}

		// the comparison
		bool operator()(const string& s1, const string& s2) const{
			if(mode == normal)
				return s1 < s2;
			else
				return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
		}
};

// container type:
// -map with
//		- string keys
//		- string values
//		- the special comparison object type
typedef map<string, string, RuntimeStringCmp> StringStringMap;

//function that fills and print such containers
void fillAndPrint(StringStringMap& coll);

int main()
{
	//create a container with the default comparison criterion
	StringStringMap coll1;
	fillAndPrint(coll1);

	// create an object for case-insensitive comparisons
	RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

	// create a container with the case-insensitive comparisons criterion
	StringStringMap coll2(ignorecase);
	fillAndPrint(coll2);
}

void fillAndPrint(StringStringMap& coll){
	//insert elements in random order 
	coll["Deutschland"] = "Germany";
	coll["deutsch"] = "German";
	coll["Haken"] = "snag";
	coll["arbeiten"] = "work";
	coll["Hund"] = "dog";
	coll["gehen"] = "go";
	coll["Unternehmen"] = "enterprise";
	coll["unternehmen"] = "undertake";
	coll["gehen"] =  "walk";
	coll["Bestatter"] = "undertaker";
	
	//print elements
	cout.setf(ios::left, ios::adjustfield);
	for(const auto& elem : coll)
		cout << setw(15) << elem.first << " " << elem.second << endl;
	cout << endl;
}
*/

// cont/hashval.hpp

#include <functional>

// from boost
template<typename T>
inline void hash_combine(std::size_t& seed, const T& val){
	seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

//auxiliary generic functions to create a hash value using a seed
template<typename T>
inline void hash_val(std::size_t& seed, const T& val){
	hash_combine(seed, val);
}

template<typename T, typename... Types>
inline void hash_val(std::size_t& seed, const T& val, const Types&... args){
	hash_combine(seed, val);
	hash_val(seed, args...);
}

//auxiliary generic function to create a hash value out of a heterogeneous list of arguments
template<typename... Types>
inline std::size_t hash_val(const Types&... args){
	std::size_t seed = 0;
	hash_val(seed, args...);
	return seed;
}

// cont/unordset1.cpp
/*
#include <iostream>
#include <unordered_set>
#include <numeric>
#include "print.hpp"
using namespace std;

int main()
{
	// create and initialize unordered set
	unordered_set<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 77};

	// print elements
	// -elements are in arbitrary order
	PRINT_ELEMENTS(coll);

	// insert some additional elements
	// -might cause rehashing and create different order
	coll.insert({-7, 17, 33, -11, 17, 19, 1, 13});
	PRINT_ELEMENTS(coll);

	// remove element with specific value
	coll.erase(33);

	// insert sum of all existing values
	coll.insert(accumulate(coll.begin(), coll.end(), 0));
	PRINT_ELEMENTS(coll);

	// check if value 19 is in the set
	if(coll.find(19) != coll.end())
		cout << "19 is available" << endl;

	//remove all negative values
	unordered_set<int>::iterator pos;
	for( pos = coll.begin(); pos != coll.end(); ){
		if(*pos < 0)
			pos = coll.erase(pos);
		else
			++pos;
	}
	PRINT_ELEMENTS(coll);
}*/


// cont/unordmultiset1.cpp
/*
#include <iostream>
#include <unordered_set>
#include "print.hpp"
using namespace std;

int main()
{
	// create and initialize, expand, and print unordered multiset
	unordered_multiset<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19, 77};
	coll.insert({-7, 17, 33, -11, 17, 19, 1, 13});
	PRINT_ELEMENTS(coll);

	//remove all elements with specific value
	coll.erase(17);

	//remove one of the elements with specific value
	auto pos = coll.find(13);
	if(pos != coll.end())
		coll.erase(pos);
	PRINT_ELEMENTS(coll);
}*/

//重点！提供自己的hash函数和等价准则
/*
#include <unordered_set>
#include <string>
#include <iostream>
//#include "hashval.hpp"
#include "print.hpp"

using namespace std;

class Customer{
	private:
		string fname;
		string lname;
		long no;
	public:
		Customer(const string& fn, const string& ln, long n): fname(fn), lname(ln), no(n){}
		friend ostream& operator<<(ostream& strm, const Customer& c){
			return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
		}
		
		friend class CustomerHash;
		friend class CustomerEqual;
};

class CustomerHash{
	public:
		std::size_t operator() (const Customer& c) const{
			return hash_val(c.fname, c.lname, c.no);
		}
};

class CustomerEqual{
	public:
		bool operator()(const Customer& c1, const Customer& c2) const{
			return c1.no == c2.no;
		}
};

int main()
{
	//unordered set with own hash function and equivalence criterion
	unordered_set<Customer, CustomerHash, CustomerEqual> custset;

	custset.insert(Customer("nico", "josuttis", 42));

	PRINT_ELEMENTS(custset);
}*/

/*
#include <string>
#include <iostream>
#include <unordered_set>
#include "print.hpp"
using namespace std;

class Customer{
	private:
		string fname;
		string lname;
		long   no;
	public:
		Customer(const string& fn, const string& ln, long n): fname(fn), lname(ln), no(n){}
		string firstname() const{
			return fname;
		}
		string lastname() const{
			return no;
		}
		friend ostream& operator << (ostream& strm, const Customer& c){
			return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
		}
};

int main()
{
	//lambda for user-defined hash function
	auto hash = [](const Customer& c){
		return hash_val(c.firstname(), c.last_name(), c.number());
	}

	//lambda for user-defined equality criterion
	auto eq = [](const Customer& c1, const Customer& c2){
		return c1.number() == c2.number();
	}

	//create unordered set with user-defined behavior
	unordered_set<Customer, decltype(hash), decltype(eq)> custset(10, hash, eq);

	custset.insert(Customer("nico", "josuttis", 42));
	PRINT_ELEMENTS(cutset);
}*/

// 这里看第二个：对buket接口的使用
// cont/buckets.hpp

#include <iostream>
#include <iomanip>
#include <utility>
#include <iterator>
#include <typeinfo>

//generic output for pairs(map elments)
template<typename T1, typename T2>
std::ostream& operator<<( std::ostream& strm, const std::pair<T1, T2>& p){
	return strm << "[" << p.first << "," << p.second << "]";
}

template<typename T>
void printHashTableState(const T& cont){
	// basic layout data:
	std::cout << "size:					" << cont.size() << "\n";
	std::cout << "buckets:				" << cont.bucket_count() << "\n";
	std::cout << "load factor:			" << cont.load_factor() << "\n";
	std::cout << "max load factor:		" << cont.max_load_factor() << "\n";

	// iterator category
	if(typeid(typename std::iterator_traits<typename T::iterator>::iterator_category) == typeid(std::bidirectional_iterator_tag))
		std::cout << "chaining style:	double-linked" << "\n";
	else
		std::cout << "chaining style:	singly-linked" << "\n";

	// elements per buket:
	std::cout << "data: " << "\n";
	for(auto idx = 0; idx != cont.bucket_count(); ++idx){
		std::cout << "b[" << std::setw(2) << idx << "]: ";
		for(auto pos = cont.begin(idx); pos != cont.end(idx); ++pos){
			std::cout << *pos << " ";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

/*
#include <unordered_set>
#include <iostream>

int main()
{
	// create and initialize an unordered set
	std::unordered_set<int> intset = {1, 2, 3, 5, 7, 11, 13, 17, 19};
	printHashTableState(intset);

	//insert some additional values(might cause rehashing)
	intset.insert({-7, 17, 33, 4});
	printHashTableState(intset);
}
*/

//cont/unordered 
//这里相当于对unordered中的bucked一种可视化，很有意思
/*
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	// create and initialize an unordered multimap as dictionary
	std::unordered_multimap<string, string> dict = {
		{"day", "Tag"}, {"strange", "fremd"},
		{"car", "Auto"}, {"smart", "elegant"},
		{"trait", "Merkmal"}, {"strange", "seltsam"}
	};
	printHashTableState(dict);

	//insert some additional values(might cause rehashing)
	dict.insert({{"smart", "raffiniert"}, {"smart", "klug"}, {"clever", "raffiniert"}});
	printHashTableState(dict);

	//modify maximum load factor(might cause rehashing)
	dict.insert({{"smart", "raffiniert"}, {"smart", "klug"}, {"clever", "raffiniert"}});
	printHashTableState(dict);

	//modify maximum load factor(might cause rehashing)
	dict.max_load_factor(0.7);
	printHashTableState(dict);
}*/

// cont/refsem1.cpp
/*
#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <memory>

class Item{
	private:
		std::string name;
		float		price;
	public:
		Item(const std::string& n, float p = 0): name(n), price(p){}
		
		std::string getName() const{
			return name;
		}

		void setName(const std::string& n){ name = n; }
		float getPrice() const{ return price; }
		void setPrice(float p){ price = p; }
};

template<typename Coll>
void printItems(const std::string& msg, const Coll& coll){
	std::cout << msg << std::endl;
	for(const auto& elem: coll){
		std::cout << ' ' << elem->getName() << ": " 
				  << elem->getPrice() << std::endl;
	}
}

int main()
{
	using namespace std;

	// two different collections sharing Items
	typedef shared_ptr<Item> ItemPtr;
	set<ItemPtr> allItems;
	deque<ItemPtr> bestsellers;

	// insert objects into the collections
	// -bestsellers are in both collections
	bestsellers = { ItemPtr(new Item("Kong Yize", 20.10)),
					ItemPtr(new Item("A Midsummer Night's Dream", 14.99)),
					ItemPtr(new Item("The Maltese Falcon", 9.88)) };
	allItems = { ItemPtr(new Item("water", 0.44)),
				 ItemPtr(new Item("Pizza", 2.22)) };
	allItems.insert(bestsellers.begin(), bestsellers.end());

	// print contents of both collections
	printItems("bestsellers:", bestsellers);
	printItems("all:", allItems);
	cout << endl;

	// double price of bestsellers
	for_each(bestsellers.begin(), bestsellers.end(), [](shared_ptr<Item>& elem){ elem->setPrice(elem->getPrice() * 2); });

	// replace second bestseller by first item with name "Pizza"
	bestsellers[1] = *(find_if(allItems.begin(), allItems.end(), [](shared_ptr<Item> elem){ return elem->getName() == "Pizza"; }));

	// set price of first bestseller
	bestsellers[0]->setPrice(44.77);

	// print contents of both collections
	printItems("bestsellers: ", bestsellers);
	printItems("all:", allItems);
}*/

// iter/itercategory1.cpp
/*
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> coll;

	// insert elements from -3 to 9
	for(int i = -3; i <= 9; ++i)
		coll.push_back(i);

	// print number of elements by processing the distance between begining and end
	// -NOTE: uses operator-for iterators
	cout << "number/distance:	" << coll.end() - coll.begin() << endl;

	// print all elements
	// -NOTE: uses operator< instead of operator !=
	vector<int>::iterator pos;
	for(pos = coll.begin(); pos < coll.end(); ++pos)
		cout << *pos << ' ';
	cout << endl;

	// print all elements
	// -NOTE: use operator[] instead of operator*
	for(int i = 0; i < coll.size(); ++i)
		cout << coll.begin()[i] << ' ';

	// print every second element
	// - NOT: uses operator += 
	for(pos = coll.begin(); pos < coll.end() - 1; pos += 2)
		cout << *pos << ' ';
	cout << endl;
}*/

/*
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	list<int> coll;

	// insert elements from 1 to 9
	for(int i = 1; i <= 9; ++i)
		coll.push_back(i);

	list<int>::iterator pos = coll.begin();

	// print actual element
	cout << *pos << endl;

	// step three elements forward
	advance(pos, 3);

	// print actual element
	cout << *pos << endl;

	// step one element backward
	advance(pos, -1);

	// print actual element 
	cout << *pos << endl;
}*/

// iter/distance1.cpp
/*
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	list<int> coll;

	// insert elements from -3 to 9
	for(int i = -3; i <= 9; ++i)
		coll.push_back(i);

	// search element with value 5
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);
	if(pos != coll.end())
		// process and print difference from the begining
		cout << "difference between begining and 5: " << distance(coll.begin(), pos) << endl;
	else
		cout << "5 not found" << endl;
}*/

//### 9.3.4 iter_swap()
//这两个简单辅助函数用来交换两个迭代器所指的元素值
/*
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "print.hpp"
using namespace std;

int main()
{
	list<int> coll;
	
	//insert elements from 1 to 9
	for(int i = 1; i <= 9; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll);

	// swap first and second value
	iter_swap(coll.begin(), next(coll.begin()));

	PRINT_ELEMENTS(coll);

	//swap first and last value
	iter_swap(coll.begin(), prev(coll.end()));

	PRINT_ELEMENTS(coll);
}*/

// iter/reviter1.cpp
/*
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print(int elem){
	cout << elem << " ";
}

int main()
{
	// create list with elments from 1 to 9
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// print all elements in normal order
	for_each(coll.begin(), coll.end(), print);
	cout << endl;

	// print all elements in reverse order
	for_each(coll.rbegin(), coll.rend(), print);
	cout << endl;
}*/

// iter/reviter2.cpp
/*
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// create list with elements from 1 to 9
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// find position of elements wtih value 5
	vector<int>::const_iterator pos;
	pos = find(coll.cbegin(), coll.cend(), 5);

	// print value to which iterator pos refers
	cout << "pos:	" << *pos << endl;

	// convert iterator to reverse iterator rpos
	vector<int>::const_reverse_iterator rpos(pos);

	// print value to which reverse iterator rpos refers
	cout << "rpos:	" << *rpos << endl;
}*/

// iter/reviter4.cpp
/*
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	// create list with elements from 1 to 9
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// find position of element with value 5
	list<int>::const_iterator pos;
	pos = find(coll.cbegin(), coll.cend(), 5);

	// print value of the element
	cout << "pos:	" << *pos << endl;

	// convert iterator to reverse iterator
	list<int>::const_reverse_iterator rpos(pos);

	// print value of the element to which the reverse iterator refers
	cout << "rpos:	" << *rpos << endl;

	// convert reverse iterator back to normal iterator
	list<int>::const_iterator rrpos;
	rrpos = rpos.base();

	// print value of the element to which the normal iterator refers
	cout << "rrpos:	" << *rrpos << endl;
}*/

// iter/backinserter1.cpp
/*
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "print.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	// create back inserter for coll
	// -inconvenient way
	back_insert_iterator<vector<int> > iter(coll);

	// insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	PRINT_ELEMENTS(coll);

	// create back inserter and insert elements
	// - convenient way
	back_inserter(coll) = 44;
	back_inserter(coll) = 55;
	PRINT_ELEMENTS(coll);

	// use back inserter to append all elements again
	// -reserve enough memory to avoid reallocation
	coll.reserve(2*coll.size());
	copy(coll.begin(), coll.end(), back_inserter(coll));	//注意这里用的不是push_back()插入函数
	PRINT_ELEMENTS(coll);
}*/

// Front Insert
/*
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>
#include "print.hpp"
using namespace std;

int main()
{
	list<int> coll;

	// create front iterator for coll
	// -inconvenient way
	front_insert_iterator<list<int> > iter(coll);

	//insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create front inserter and insert elements
	// - convenient way
	front_inserter(coll) = 44;
	front_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);

	// use front inserter to insert all elements again
	copy(coll.begin(), coll.end(), front_inserter(coll));

	PRINT_ELEMENTS(coll);
}*/

/*
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "print.hpp"
using namespace std;

int main()
{
	set<int> coll;

	// create insert for coll
	// - inconvenient way
	insert_iterator<set<int> > iter(coll, coll.begin());

	// insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll, "set:	");

	// create inserter and insert elements
	// -convenient way
	inserter(coll, coll.end()) = 44;
	inserter(coll, coll.end()) = 55;

	PRINT_ELEMENTS(coll, "set:	");

	// use inserter to insert all elements into a list
	list<int> coll2;
	copy(coll.begin(), coll.end(), inserter(coll2, ++coll2.begin()));
	PRINT_ELEMENTS(coll2, "list:	");

	//use inserter to reinsert all elments into the list before the second element
	copy(coll.begin(), coll.end(), inserter(coll2, ++coll2.begin()));
	PRINT_ELEMENTS(coll2, "list:	");
}
*/

//ostream 迭代器的用法：
// iter/ostreamiter1.cpp
//
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

 int main()
{
	// create ostream iterator for stream cout
	// - values are separated by a newline character
	ostream_iterator<int> intWriter(cout, "\n");

	//write elements with the usual iterator interface
	*intWriter = 42;
	intWriter++;
	*intWriter = 77;
	intWriter++;
	*intWriter = -5;

	//create collection with elements from 1 to 9
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//write all elements without any delimiter
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout));
	cout << endl;

	//write all elements with "<" as delimiter
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " < "));
	cout << endl;
}*/

// iter/istreamiter1.cpp
/*
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	// create istream iterator that reads integers from cin
	istream_iterator<int> intReader(cin);

	// create end-of-stream iterator
	istream_iterator<int> intReaderEOF;

	// while able to read tokens with istream iterator
	// - write them twice
	while(intReader != intReaderEOF){
		cout << "Once:		" << *intReader << endl;
		cout << "Once again:	" << *intReader << endl;
		++intReader;
	}
}*/

/*
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	istream_iterator<string> cinPos(cin);
	ostream_iterator<string> coutPos(cout, " ");

	// while input is not at the end of the file
	// - write every third string
	while(cinPos != istream_iterator<string>()){
		// ignore the following two strings
		advance(cinPos, 2);

		//read and write the third string
		if(cinPos != istream_iterator<string>())
			*coutPos++ = *cinPos++;
	}
	cout << endl;
}*/

// iter/assoiter.hpp
/*
#include <iterator>

//class template for insert iterator for associative and unordered containers
template<typename Container>
class asso_insert_iterator: 
public std::iterator<std::output_iterator_tag, typename Container::value_type>{
	protected:
		Container& container;			//	container in which elements are inserted
	public:
		//constructor
		explicit asso_insert_iterator(Container& c): container(c){}

		// assignment operator
		// - inserts a value into the container
		asso_insert_iterator<Container>&
		operator=(const typename Container::value_type& value){
			container.insert(value);
			return *this;
		}

		// dereferencing is a no-op that returns the iterator itself
		asso_insert_iterator<Container>& operator*(){
			return *this;
		}

		// increment operation is a no-op that returns the iterator itself
		asso_insert_iterator<Container>& operator++(){
			return *this;
		}

		asso_insert_iterator<Container>& operator++(int){
			return *this;
		}
};

//convenience function to create the inserter
template<typename Container>
inline asso_insert_iterator<Container> asso_inserter(Container& c){
	return asso_insert_iterator<Container>(c);
}

// iter/assoiter1.cpp
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include "print.hpp"

int main()
{
	std::unordered_set<int> coll;

	// create inserter for coll
	// - inconvenient way
	asso_insert_iterator<decltype(coll)> iter(coll);

	// insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// use inserter with an algorithm
	std::vector<int> vals = { 33, 67, -4, 13, 5, 2 };
	std::copy(vals.begin(), vals.end(), asso_inserter(coll));
	PRINT_ELEMENTS(coll);
}*/

// fo/sequence1.cpp
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "print.hpp"

using namespace std;

class IntSequence{
	private:
		int value;
	public:
		IntSequence(int initialValue)		// constructor
			:value(initialValue){}
		int operator()(){					// function call
			return ++value;
		}
};

int main()
{
	list<int> coll;
	
	// insert values from 1 to 9
	generate_n(back_inserter(coll), 9, IntSequence(1));

	PRINT_ELEMENTS(coll);

	// replace to last element but one with values starting at 42
	generate(next(coll.begin()), prev(coll.end()), IntSequence(42));

	PRINT_ELEMENTS(coll);
}
