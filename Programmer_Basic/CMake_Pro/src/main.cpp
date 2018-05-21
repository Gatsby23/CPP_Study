#include <iostream>

class Blah{
	public:
		void SomeFunc() const{ std::cout << "const " << std::endl;}
};

int main()
{	
	Blah blah;
	blah.SomeFunc();
	return 0;
}
