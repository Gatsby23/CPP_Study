#include <iostream>
#include "String.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	String s1("One"), s2("Two");
	cout << s1 << " " << s2 << endl << endl;
	String s3(s2);
	cout << s1 << " " << s2 << " " << s3 << endl << endl;
	s3 = s1;
	cout << s1 << " " << s2 << " " << s3 << endl << endl;
	s3 = String("Three");
	cout << s1 << " " << s2 << " " << s3 << endl << endl;

	vector<String> vs;
	vs.push_back(4);
	vs.push_back(s1);
	vs.push_back(std::move(s2));
	vs.push_back(String("Three"));
	vs.push_back("Four");
	for_each(vs.begin(), vs.end(), [](const String &s){ cout << s << " ";});
	cout << endl;

	return 0;
}
