#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void add_family( map<string, vector<string>> &families, const string &family ){
	if(families.find(family) == families.end())
		families[family] = vector<string>();
}

void add_child(map<string, vector<string>> &families, const string &family, const string &child){
	families[family].push_back(child);	
}

int main(int argc, char* argv[])
{
	map<string, vector<string>> families;
	add_family(families, "张");
	add_child(families, "张", "强");
	add_child(families, "王", "五");
	add_family(families, "王");

	for (auto f : families){
		cout << f.first << "家的孩子: ";
		for(auto c : f.second)
			cout << c << " ";
		cout << endl;
	}
	
	return 0;
}
