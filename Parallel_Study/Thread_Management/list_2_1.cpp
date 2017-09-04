#include <thread>
#include <iostream>

void do_something(int &i){
	++i;
	std::cout << i << std::endl;
}

struct func{
	int &i;
	func(int &i_):i(i_){}

	void operator()(){
		for(unsigned j = 0; j < 1000000; ++j)
				do_something(i);
	}
};

void oops(){
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread1(my_func);
	std::thread my_thread2(my_func);
	my_thread1.join();
	my_thread2.join();
}

int main()
{
	oops();
}
