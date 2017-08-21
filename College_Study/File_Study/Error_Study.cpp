#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	//freopen("t.txt", "r", stdin);		//cin被改动到从t.txt中读取数据
	freopen("test.txt", "w", stdout);	//将标准输出重定向到test.txt
	if(y==0)
		cerr << "error." << endl;
	else
		cout << x / y;					//输出结果到test.txt
	return 0;
}
