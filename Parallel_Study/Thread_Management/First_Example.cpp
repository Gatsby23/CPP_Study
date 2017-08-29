#include <iostream>
#include <thread>

using namespace std;

void hello(){
	cout << "Hello Concurrent World!" << endl;
}

int main()
{
	thread t(hello);
	t.join();
}
