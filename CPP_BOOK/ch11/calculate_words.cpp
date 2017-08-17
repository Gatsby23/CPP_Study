map<string, size_t> word_count;																						//string 到size_t的空map
set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "and", "but", "or", "an", "a"};
string word;
while(cin >> word)
	//只统计不在exclude中的单词
	if( exclude.find(word) == exclude.edn() )
		++word_count[word];																								//提取word的计数器并将其增加1
for(const auto &w : word_count )    																					//对map中的每个元素进行提取
	cout << w.first << " occurs " << w.second << ( (w.second > 1) ? " times" : " time" ) << endl;						//打印出结果


