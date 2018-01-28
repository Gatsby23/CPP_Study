
// contadapt/stack1.cpp
/*
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;

	// push three elements into the stack
	st.push(1);
	st.push(2);
	st.push(3);

	// pop and print two elements from the stack
	cout << st.top() << " ";
	st.pop();
	cout << st.top() << " ";
	st.pop();

	// modify top element
	st.top() = 77;

	// push two new elements
	st.push(4);
	st.push(5);

	// pop one element without processing it
	st.pop();

	// pop and print remaining elements
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}*/

// contadapt/stack2.cpp
/*
#include <iostream>
#include <exception>
#include "Stack.hpp"	// use special stack class
using namespace std;

int main()
{
	try{
		Stack<int> st;

		// put three elements into the stack
		st.push(1);
		st.push(2);
		st.push(3);
		
		// pop and print two elements from the stack
		cout << st.pop() << ' ';
		cout << st.pop() << ' ';

		// modify top element
		st.top() = 77;

		// push two new elements
		st.push(4);
		st.push(5);

		// pop one element without processing it
		st.pop();

		// pop and print three elements
		// - ERROR: one element too many
		cout << st.pop() << ' ';
		cout << st.pop() << endl;
		cout << st.pop() << endl;
	}catch(const exception& e){
		cerr << "EXCEPTION: " << e.what() << endl;
	}

}*/

// contadapt/queue1.cpp
/*
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue<string> q;

	// insert three elements into the queue
	q.push("These: ");
	q.push("are ");
	q.push("more than ");

	// read and print two elements from the queue
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();

	// insert two new elements
	q.push("four ");
	q.push("words!");

	// skip one element
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front() << endl;
	q.pop();

	// print number of elements in the queue
	cout << "number of elements in the queue: " << q.size() << endl;

}*/

// contadapt/priorityqueue1.cpp
/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<float> q;

	// insert three elements into the priority queue
	q.push(66.6);
	q.push(22.2);
	q.push(44.4);

	// read and print two elements
	cout << q.top() << ' ';
	q.pop();
	cout << q.top() << endl;
	q.pop();

	// insert three more elements
	q.push(11.1);
	q.push(55.5);
	q.push(33.3);
	
	// skip one element
	q.pop();

	// pop and print remaining elements
	while(!q.empty()){
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}*/

// contadapt/bitset1.cpp
/*
#include <bitset>
#include <iostream>
using namespace std;

int main()
{
	// enumeration type for the bits
	// - each bit represents a color
	enum Color = { red, yellow, green, blue, white, black, ..., numColors };

	// create bitset for all bits/colors
	bitset<numColors> usedColors;

	// set bits for two colors
	usedColors.set(red);
	usedColors.set(blue);

	// print some bitset data
	cout << "bitfield of used colors:	" << usedColors << endl;
	cout << "number   of used colors:	" << usedColors.count() << endl;
	cout << "bitfield of unused colors: " << ~usedColors << endl;

	// if any color is used
	if(usedColors.any()){
		// loop over all colors
		for(int c = 0; c < numColors; ++c){
			if(usedColors[(Color)c])
				...;
		}
	}
}*/

// contadapt/bitset2.cpp
#include <bitset>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
	// print some numbers in binary represenation
	cout << "267 as binary short:	"
		 << bitset<numeric_limits<unsigned short>::digits>(267) << endl;

	cout << "267 as binary long:	"
		 << bitset<numeric_limits<unsigned long>::digits>(267) << endl;

	cout << "10,000,000 with 24 bits: "
		 << bitset<24>(1e7) << endl;

	// write binary representation into string
	string s = bitset<42>(12345678).to_string();
	cout << "12,345,678 with 42 bits: " << s << endl;

	// transform binary representation into integral number
	cout << "\"1000101011\" as number: "
		 << bitset<100>("100101011").to_ullong() << endl;
}
