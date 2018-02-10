// string/string1.cpp
/*
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string filename, basename, extname, tmpname;
	const string suffix("tmp");

	// for each command-line arugment( which is an ordinary C-string)
	for(int i = 1; i < argc; ++i){
		// process argument as filename
		filename = argv[i];

		// search period in filename
		string::size_type idx = filename.find('.');
		if(idx == string::npos)
			// filename does not contain any period
			tmpname = filename + '.' + suffix;
		else{
			// split filename into base name and extension
			// - base name contains all characters before the period
			// - extension contains all characters after the period
			basename = filename.substr(0, idx);
			extname = filename.substr(idx+1);
			if(extname.empty()){
				// contains period but no extension: append tmp
				tmpname = filename;
				tmpname += suffix;
			}else if(extname == suffix){
				// replace extension tmp with xxx
				tmpname = filename;
				tmpname.replace(idx+1, extname.size(), "xxx");
			}else{
				// replace any extension with tmp
				tmpname = filename;
				tmpname.replace(idx+1, string::npos, suffix);
			}
		}
		
		// print filename and temporary name
		cout << filename << " => " << tmpname << endl;
	}
}*/

// string/string2.cpp

/*
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	const string delims(" \t,.;");
	string line;

	// for every line read successfully
	while(getline(cin, line)){
		string::size_type begIdx, endIdx;

		// search beginning of the first word
		begIdx = line.find_first_not_of(delims);

		// while beginning of a word found
		while(begIdx != string::npos){
			// search end of the actual word
			endIdx = line.find_first_of(delims, begIdx);
			if(endIdx == string::npos){
				// end of word is end of line
				endIdx = line.length();
			}

			// print characters in reverse order
			for(int i = endIdx-1; i >= static_cast<int>(begIdx); --i)
				cout << line[i];
			cout << ' ';

			// search begining of the next word
			begIdx = line.find_first_not_of(delims, endIdx);
		}
		cout << endl;
	}
}*/

// string/stringnumconv1.cpp
/*
#include <string>
#include <iostream>
#include <limits>
#include <exception>

int main()
{
	try{
		// convert to numeric type
		std::cout << std::stoi(" 77") << std::endl;
		std::cout << std::stod(" 77.7") << std::endl;
		std::cout << std::stoi("-0x77") << std::endl;

		// use index of characters not processed
		std::size_t idx;
		std::cout << std::stoi(" 42 is the truth", &idx) << std::endl;
		std::cout << " idx of first unprocessed char: " << idx << std::endl;

		// use base 16 and 8
		std::cout << std::stoi(" 42", nullptr, 16) << std::endl;
		std::cout << std::stol("789", &idx, 8) << std::endl;
		std::cout << " idx of first unprocessed char: " << idx << std::endl;

		// convert numeric value to string
		long long ll = std::numeric_limits<long long>::max();
		std::string s = std::to_string(ll);						// converts maximum long long to string
		std::cout << s << std::endl;

		// try to convert back
		std::cout << std::stoi(s) << std::end;					// throws out_of_range
	}catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}*/


// string/stringiter1.cpp
// 这里是通过一个简单语句将string内的所有字符转换为大小写
/*
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
using namespace std;

int main()
{
	// create a string
	string s("The zip code of Braunschweig in Germany is 38100");
	cout << "original: " << s << endl;

	// lowercase all characters
	transform(s.cbegin(), s.cend(), s.begin(), [](char c){ return tolower(c); });
	cout << "lowered:	" << s << endl;

	// uppercase all characters
	transform(s.cbegin(), s.cend(), s.begin(), [](char c){ return toupper(c); });
	cout << "uppered:	" << s << endl;

	// search case-insensitive for Germany
	string g("Germany");
	string::const_iterator pos;

	pos = search(s.cbegin(), s.cend(), g.cbegin(), g.cend(), [](char c1, char c2){ return toupper(c1) == toupper(c2); });
	if(pos != s.cend()){
		cout << "substring \"" << g << "\" found at index " << pos - s.cbegin() << endl;
	}
}*/

// string/stringiter2.cpp
/*
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// create constant string
	const string hello("Hello, how are you? ");
	
	// initialize string s with all characters of string hello
	string s(hello.cbegin(), hello.cend());

	// range-based for loop that iterates through all the characters
	for(char c : s)
		cout << c;
	cout << endl;

	// reverse the order of all characters inside the string
	reverse(s.begin(), s.end());
	cout << "reverse:		" << s << endl;

	// sort all characters inside the string
	sort(s.begin(), s.end());
	cout << "ordered:	" << s << endl;

	// remove adjacent duplicates
	// - unique() reorders and returns new end
	// - erase() shrinks accordingly
	s.erase(unique(s.begin(), s.end()), s.end());
	cout << "no duplicates: " << s << endl;
}*/

// string/stringiter3.cpp
// 采用back inserter，从标准设备读取数据放入一个string
/*
#include <string> 
#include <iostream> 
#include <algorithm> 
#include <iterator> 
using namespace std; 
int main() 
{ 
	string input; 
	// don't skip leading whitespaces 
	cin.unsetf(ios::skipws); 
	
	// read all characters while compressing whitespaces 
	const locale& loc(cin.getloc());			
	locale unique_copy(istream_iterator<char>(cin), istream_iterator<char>(), back_inserter(input), [=](char c1, char c2){ return isspace(c1, loc) && isspace(c2, loc); }); 
	// process input /
	// / - here: write it to standard output 
	cout << input; 
}*/
/*
#ifndef ICSTRING_HPP
#define ICSTRING_HPP

#include <string>
#include <iostream>
#include <cctype>			// 译注: for toupper()

// replcae functions of the standard char_traits<char>
// so that strings behave in a case-insensitive way

struct ignorecase_traits: public std::char_traits<char>{
	// return whether c1 and c2 are equal
	static bool eq(const char& c1, const char& c2){
		return std::toupper(c1) == std::toupper(c2);
	}

	// return whether c1 is less than c2
	static bool lt(const char& c1, const char& c2){
		return std::toupper(c1) < std::toupper(c2);
	}

	// compare up to n characters of s1 and s2
	static int compare(const char* s1, const char* s2, std::size_t n){
		for(std::size_t i = 0; i < n; ++i)
			if(!eq(s1[i], s2[i]))
				return lt(s1[i], s2[i]) ? -1 : 1;
		return 0
	}

	// search c in s
	static const char* find(const char* s, std::size_t n, const char& c){
		for(std::size_t i = 0; i < n; ++i)
			if(eq(s[i], c))
				return &(s[i]);
		return 0;
	}
};

// define a special type for such strings
typedef std::basic_string<char, ignorecase_traits> icstring;

// define an output operator
// because the traits type is different from that for std::ostream

inline std::ostream& operator<< (std::ostream& strm, const icstring& s){
	// simply convert the icstring into a normal string
	return strm << std::string(s.data(), s.length());
}

#endif*/

#include "icstring.hpp"

int mian()
{
	using std::cout;
	using std::endl;

	icstring s1("hallo");
	icstring s2("otto");
	icstring s3("hALLo");

	cout << std::boolalpha;
	cout << s1 << " == " << s2 << " : " << (s1==s2) << endl;
	cout << s1 << " == " << s3 << " : " << (s1==s3) << endl;

	icstring::size_type idx = s1.find("All");
	if(idx != icstring::npos)
		cout << "index of \" All \" in \"" << s1 << "\": " << idx << endl;
	else
		cout << "\"All \" not found in \"" << s1 << endl;
}
