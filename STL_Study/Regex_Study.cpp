// regex/regex1.cpp
/*
#include <regex>
#include <iostream>
using namespace std;

void out(bool b){
	cout << (b ? "found" : "not found") << endl;
}

int main()
{
	// find XML/HTML-tagged value(using default syntax)
	regex reg1("<.*>.*</.*>");
	bool found = regex_match("<tag>value</tag>", reg1);
	out(found);

	// find XML/HTML-tagged value (tags before and after the value must match):
	regex reg2("<(.*)>.*</\\1>");
	found = regex_match("<tag>value</tag>", reg2);
	out(found);

	// use C-String as regular expression(needs explicit cast to regex)
	found = regex_match("<tag>value</tag>", regex("<(.*)>.*</\\1>"));
	out(found);
	cout << endl;

	// regex_match() versus regex_search():
	found = regex_match("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>"));
	out(found);
	found = regex_match("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*"));
	out(found);

	found = regex_search("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*"));
	out(found);
}*/

// regex/regex2.cpp

/*
#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string data = "XML tag: <tag-name>the value</tag-name>.";
	cout << "data:			" << data << "\n\n";

	smatch m;	// for returned details of the match
	bool found = regex_search(data, m, regex("<(.*)>(.*)</(\\1)>"));

	// print match details
	cout << "m.empty():		" << boolalpha << m.empty() << endl;
	cout << "m.size():		" << m.size() << endl;
	if(found){
		cout << "m.str():			" << m.str() << endl;
		cout << "m.length():		" << m.length() << endl;
		cout << "m.position():		" << m.position() << endl;
		cout << "m.prefix().str():	" << m.prefix().str() << endl;
		cout << "m.suffix().str():	" << m.suffix().str() << endl;
		cout << endl;

		// iterating over all matches(using the match index):
		for(int i = 0; i < m.size(); ++i){
			cout << "m[" << i << "].str():		" << m[i].str() << endl;
			cout << "m.str(" << i << "):		" << m.str(i) << endl;
			cout << "m.position(" << i << "):	" << m.position(i) << endl;
		}
		cout << endl;

		// iterating over all matches(using iterators):
		cout << "matches:" << endl;
		for(auto pos = m.begin(); pos != m.end(); ++pos){
			cout << " " << *pos << " ";
			cout << "(length: " << pos->length() << ")" << endl;
		}
	}
}*/

/*
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string data = "<person>\n"
				  "<first>Nico</first>\n"
				  "<last>Josuttis</last>\n"
				  "</person>\n";
	regex reg("<(.*)>(.*)</(\\1)>");

	// iterate over all matches
	auto pos = data.cbegin();
	auto end = data.cend();
	smatch m;
	for(; regex_search(pos, end, m, reg); pos = m.suffix().first){
			cout << "match:	" << m.str() << endl;
			cout << "tag:	" << m.str(1) << endl;
			cout << "value:	" << m.str(2) << endl;
	}
}*/


//regexiter1.cpp
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string data = "<person>\n"
				  "<first>Nico</first>\n"
				  "<last>Josuttis</last>\n"
				  "</person>\n";

	regex reg("<(.*)>(.*)</(\\1)>");

	// iterate over all matches(using a regex_iterator)
	sregex_iterator pos(data.cbegin(), data.cend(), reg);
	sregex_iterator end;
	for(; pos != end; ++pos){
		cout << "match:		" << pos->str() << endl;
		cout << " tag:		" << pos->str(1) << endl;
		cout << " value:	" << pos->str(2) << endl;
	}

	// use a regex_iterator to process each matched substring as element in an algorithm:
	sregex_iterator beg(data.cbegin(), data.cend(), reg);

	for_each(beg, end, [](const smatch& m){
				cout << "match:		" << m.str() << endl;
				cout << " tag:		" << m.str(1) << endl;
				cout << " value:	" << m.str(2) << endl;
			});
}


