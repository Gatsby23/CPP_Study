#include <iostream>
#include <map>
#include <string>

using namespace std;

class CStudent{
	public:
		struct CInfo{	//类的内部还可以定义类
			int id;
			string name;
		};

		int score;
		CInfo info;		//学生的其他信息
};

typedef multimap<int, CStudent::CInfo> MAP_STD;	//注意内部类的使用方法

int main()
{
	MAP_STD mp;
	CStudent st;
	string cmd;
	while(cin >> cmd){
		if(cmd == "Add"){
			cin >> st.info.name >> st.info.id >> st.score;
			mp.insert(MAP_STD::value_type(st.score, st.info));
		}else if(cmd == "Query"){
			int score;
			cin >> score;
			MAP_STD::iterator p = mp.lower_bound(score);
			if(p != mp.begin()){
				--p;
				score = p->first;	//比要查询分数低的最高分
				MAP_STD::iterator maxp = p;
				int maxId = p->second.id;
				for(; p!= mp.begin() && p->first == score; --p){
					if(p->second.id > maxId){
						maxp = p;
						maxId = p->second.id;
					}
				}
				if(p->first == score){
					if(p->second.id > maxId){
						maxp = p;
						maxId = p->second.id;
					}
				}
				cout << maxp->second.name << " " << maxp->second.id << " " << maxp->first << endl;
			}else
				cout << "Nobody" << endl;
		}
	}
	return 0;
}
