//定义一个20个元素的vector,保存0到9每个整数的两份拷贝
vector<int> ivec;
for( vector<int>::size_type i = 0; i != 10; ++i){
	ivec.push_back(i);
	ivec.push_back(i);	//每个数重复保存一次
}

//iset包含来自ivec的不重复的元素;　miset包含20个元素
set<int> iset(ivec.cbegin(), ivec.cend());
multiset<int> miset(ivec.cbegin(), ivec.cend());
cout << ivec.size() << endl;		//打印出来20
cout << iset.size() << endl;		//打印出来10
cout << miset.size() << endl;		//打印出来20

