#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family){
	families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &family, const string &child, const string &birthday){
	families[family].push_back({child, birthday});
}

int main(int argc, char* argv[])
{
	map<string, vector<pair<string, string>>> families;
	add_family(families,"张");
	add_child(families, "张", "强", "1970-1-1");
	add_child(families, "张", "刚", "1980-1-1");
	add_child(families, "王", "五", "1990-1-1");
	add_family(families, "王");
	for(auto f: families){
		cout << f.first << "家的孩子: ";
		for(auto c : f.second)
			cout << c.first << "(生日 " << c.second << "), ";
		cout << endl;
	}
	return 0;
}
