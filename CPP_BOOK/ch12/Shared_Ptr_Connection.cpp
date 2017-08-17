#include <iostream>
#include <memory>

using namespace std;

struct destination();
struct connection();

connection connect(destination *pd){
	cout << "打开链接" << endl;
	return connection();
}

void disconnect(connection c){
	cout << "关闭链接" << endl;
}

//未使用shared_ptr的版本
void f(destination &d){
	cout << "直接管理connect" << endl;
	connection c = connect(&d);
	//忘记调用disconnect关闭链接
	cout << endl;
}

//使用shared_ptr版本
void f1(destination &d){
	cout << "用shared_ptr来管理connect" << endl;
	connection c = connect(&d);
	
	shared_ptr<connection> p(&c, end_connection);
	//忘记调用disconnect关闭链接了
	cout << endl;
}

int main(int argc, char **argv)
{
	destination d;
	f(d);
	f1(d);
	
	return 0;
}
