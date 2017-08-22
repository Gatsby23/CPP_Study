#include <iostream>

using namespace std;

void printBinary(int value);

int main()
{
		printBinary(17);
		return 0;
}

 void printBinary(int value){
	int bitOfBinary = sizeof(value) * 8;
	unsigned int mask = 1 << (bitOfBinary - 1);
	for(int i = 1; i <= bitOfBinary; i++){
		int temp = value & mask;
		if(temp == 0)
			cout << 0;
		else
			cout << 1;
		mask >>= 1;
	}
}
