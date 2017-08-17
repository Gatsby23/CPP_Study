#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string &trans( string &s){
	for( int p = 0; p < s.size(); p++ ){
		if(s[p] > 'A' && s[p] <= 'Z')
			s[p] -= ('A' - 'a');
		else if(s[p] == ',' || s[p] == '.')
			s.erase(p, 1);
	}
	
	return s;
}

int main( int argc, char* argv )
{
	ifstream in(argv[1]);
	if(!in){
		cout << "打开输入文件失败!" << endl;
	 	exit(1); 
	}
	
	map<string, size_t> word_count; 			//string到count的映射
	string word;
	while( in >> word )
		++word_count[trans(word)];				//这个单词的出现次数加1
	
	for(const auto &w : word_count )			//对map中的每个元素
		//打印结果	
		cout << w.first << "出现了"　<< w.second << "次"　<< endl;
	return 0;
}
