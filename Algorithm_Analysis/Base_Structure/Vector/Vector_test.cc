#include "Vector.h"
#include <iostream>
int main()
{
	std::cout << "Test for the vector study: " << std::endl;
	
	Vector<int> myVector;
	
	myVector.insert(0);
	myVector.insert(1);
	myVector.insert(2);

	std::cout << "Now, the size of the vector is: " << myVector.size() << std::endl;
	std::cout << "Does number 6 in the vector ? " << myVector.find(6) << std::endl;
}
