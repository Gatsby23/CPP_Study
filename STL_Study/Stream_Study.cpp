// Example:输入俩个浮点数，并输出其乘积
// io/io1.cpp
/*
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	double x, y;		// operands
	
	// print header string
	cout << "Multiplication of two floating point values" << endl;

	// read first operand
	cout << "first operand:	";
	if(!(cin >> x)){
		// input error
		// => error message and exit program with error status
		cerr << "error while reading the first floating value" << endl;
		return EXIT_FAILURE;
	}
	
	// read second operand
	cout << "second operand:	";
	if(!(cin >> y)){
		// input error
		// => error message and exit program with error status
		cerr << "error while reading the second floating value"
			 << endl;
		return EXIT_FAILURE;
	}
	
	// print operand and result
	cout << x << " times " << y << " equals " << x * y << endl;

}*/

// io/timemanipulator1.cpp
/*
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
using namespace std;

int main()
{
	// process and print current date and tim
	auto now = chrono::system_clock::now();
	time_t t = chrono::system_clock::to_time_t(now);
	tm* nowTM = localtime(&t);
	cout << put_time(nowTM, "data:	%x\ntime:	%X\n") << endl;

	// read date:
	tm* date;
	cout << "new date:	";
	cin >> get_time(date, "%x");		// read date
	if(!cin){
		cerr << "invalid format read" << endl;
	}
}*/

// io/sum1a.cpp
/*
#include <istream>

namespace MyLib{
	double readAndProcessSum(std::istream& strm){
		using std::ios;
		double value, sum;
		//写法一:
		// save current state of exception flags
		ios::iostate oldExceptions = strm.exceptions();

		// let failbit and badbit throw exceptions
		// -NOTE: failbit is also set at end-of-file
		strm.exceptions(ios::failbit|ios::badbit);

		try{
			// while stream is OK
			// - read value and add it to sum
			sum = 0;
			while(strm >> value){
				sum += value;
			}
		}catch(...){
			// if exception not caused by end-of-file
			// restore old state of exception flags
			// -rethrow exception
			if(!strm.eof()){
				strm.exceptions(oldExceptions);
				throw;
			}
		}

		// restore old state of exception flags
		strm.exceptions(oldExceptions);
		*/
		
		/*

		// while stream is OK
		// - read value and add it to sum
		sum = 0;
		while(strm >> value){
			sum += value;
		}
		if(!strm.eof()){
			throw std::ios::failure("input error in readAndProcessSum()");
		}
		// return sum
		return sum;
	}
}

// io/summain.cpp
#include <iostream>
#include <exception>
#include <cstdlib>

namespace MyLib{
	double readAndProcessSum(std::istream&);
}

int main()
{
	using namespace std;
	double sum;

	try{
		sum = MyLib::readAndProcessSum(cin);
	}catch(const ios::failure& error){
		cerr << "I/O exception:	" << error.what() << endl;
		return EXIT_FAILURE;
	}catch(const exception& error){
		cerr << "standard exception: " << error.what() << endl;
		return EXIT_FAILURE;
	}catch(...){
		cerr << "Unknown exception" << endl;
		return EXIT_FAILURE;
	}

	// print sum
	cout << "sum: " << sum << endl;
}*/

// io/charact1.cpp
/*
#include <iostream>
using namespace std;

int main()
{
	char c;

	// while it is possible to read a character
	while(cin.get(c)){
		// print it
		cout.put(c);
	}
}*/

// io/fstream1.cpp
/*
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// forward declarations
void writeCharsetToFile(const string& filename);
void outputFile(const string& filename);

int main()
{
	writeCharsetToFile("charset.out");
	outputFile("charset.out");
}

void writeCharsetToFile(const string& filename){
	// open output file
	ofstream file(filename);

	// file opened?
	if(!file){
		// No, abort program
		cerr << "can't open output file \"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	
	// write character set
	for(int i = 32; i < 256; ++i){
		file << "value:	" << setw(3) << i << "	" 
			 << "char:	" << static_cast<char>(i) << endl;
	}
} // close file automatically

void outputFile(const string& filename){
	// open input file
	ifstream file(filename);

	// file opened?
	if(!file){
		// No, abort program
		cerr << "can't open input file \"" << filename << "\""
			 << endl;
		exit(EXIT_FAILURE);
	}

	// copy file contents to cout
	char c;
	while(file.get(c)){
		cout.put(c);
	}
}*/

// io/stream2.cpp
/*
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// write string to temporarily created file stream(Since C++11)
	std::string s("hello");
	std::ofstream("fstream.tmp") << s << std::endl;

	// write C-string to temporarily created file stream
	// -Note: wrote a pointer value before C++11
	std::ofstream("fstream2.tmp", std::ios::app) << "world" << std::endl;
}*/

// io/cat1.cpp
/*
#include <fstream>
#include <iostream>
using namespace std;

// for all filenames passed as command-line arguments
// - open, print contents and close file
int main(int argc, char* argv[])
{
	ifstream file;
	
	// for all command-line arguments
	for(int i = 1; i < argc; ++i){
		// open file
		file.open(argv[i]);

		// write file contents to cout
		char c;
		while(file.get(c)){ cout.put(c); }

		// clear eofbit and failbit due to end-of-file
		file.clear();

		// close file
		file.close();
	}
}*/

// io/cat2.cpp
//
// header files for file I/O
/*
#include <iostream>
#include <fstream>

void printFileTwice(const char* filename){
	// open file
	std::ifstream file(filename);

	// print contents the first time
	std::cout << file.rdbuf();

	// seek to the begining
	file.seekg(0);

	// print the contents the second time
	std::cout << file.rdbuf();
}

int main(int argc, char* argv[])
{
	// print all files passed as a command-line argument twice
	for(int i = 1; i < argc; ++i){
		printFileTwic(argv[i]);
	}
}*/

// io/sstream1.cpp
/*
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

int main()
{
	ostringstream os;

	// decimal and hexadecimal value
	os << "dec:	" << 15 << hex << " hex: " << 15 << endl;
	cout << os.str() << endl;

	// append floating value and bitset
	bitset<15> b(5789);
	os << "float:	" << 4.67 << "	bitset:	" << b << endl;

	// overwrite with octal value
	os.seekp(0);
	os << "oct:	" << oct << 15;
	cout << os.str() << endl;
}*/

// io/sstream2.cpp
/*
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

tuple<string, string, string> parseName(string name){
	string s1, s2, s3;
	istringstream(name) >> s1 >> s2 >> s3;
	if(s3.empty())
		return tuple<string, string, string>(move(s1), "", move(s2));
	else
		return tuple<string, string, string>(move(s1), move(s2), move(s3));
}

int main()
{
	auto t1 = parseName("Nicolai M. Josuttis");
	cout << "firstname:	" << get<0>(t1) << endl;
	cout << "middle:	" << get<1>(t1) << endl;
	cout << "lastname:	" << get<2>(t1) << endl;
	auto t2 = parseName("Nico Josuttis");
	cout << "firstname:	" << get<0>(t2) << endl;
	cout << "middle:	" << get<1>(t2) << endl;
	cout << "lastname:	" << get<2>(t2) << endl;
}*/

// io/streambuffer1.cpp
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// stream for hexadecimal standarad output
	ostream hexout(cout.rdbuf());
	hexout.setf(ios::hex, ios::basefield);
	hexout.setf(ios::showbase);

	// switch between decimal and hexadecimal output
	hexout << "hexout:	" << 177 << "	" << endl;
	cout   << "cout:	" << 177 << "	" << endl;
	hexout << "hexout:	" << -49 << "	" << endl;
	cout   << "cout:	" << -49 << "	" << endl;
	hexout << endl;
}*/

// io/streambuffer2.cpp
/*
#include <iostream>
#include <fstream>

void hexMultiplicationTable(std::streambuf* buffer, int num){
	std::ostream hexout(buffer);
	hexout << std::hex << std::showbase;

	for(int i = 1; i <= num; ++i)
		for(int j = 1; j <= 10; ++j)
			hexout << i*j << std::endl;
} // does NOT close buffer

int main()
{
	using namespace std;
	int num = 5;

	cout << "We print " << num << " lines hexadecimal" << std::endl;

	hexMultiplicationTable(cout.rdbuf(), num);

	cout << "That was the output of " << num << " hexadecimal lines " << endl;
}
*/

// io/streamredirct1.cpp
/*
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

void redirect(ostream&);

int main()
{
	cout << "the first row" << endl;

	redirect(cout);

	cout << "the last row" << endl;
}

void redirect(ostream& strm){
	// save output buffer of the stream
	// -use unique pointer with deleter that ensures to restore
	// the original output buffer at the end of the function
	auto del = [&](streambuf* p){ strm.rdbuf(p); }
	unique_ptr<streambuf, decltype(del)> origBuffer(strm.rdbuf(), del);

	// redirect output into the file redirect.txt
	ofstream file("redirect.txt");
	strm.rdbuf(file.rdbuf());

	file << "one row for the file" << endl;
	strm << "one row for the stream" << endl;
}*/

// io/streamreadwrite1.cpp
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// open file "example.dat" for reading and writing
	filebuf buffer;
	ostream output(&buffer);
	istream input(&buffer);
	buffer.open("example.dat", ios::in | ios::out | ios::trunc);
	for(int i =1; i <=4; i++){
		// write one line
		output << i << ".line" << endl;

		// print all file contents
		input.seekg(0);					// seek to the beginning
		char c;
		while(input.get(c)){
			cout.put(c);
		}
		cout << endl;
		input.clear();					// clear eofbit and failbit
	}
}*/

// io/charcat2.cpp
/*
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	// input stream buffer iterator for cin
	istreambuf_iterator<char> inpos(cin);

	// end-of-stream iterator
	istreambuf_iterator<char> endpos;

	// output stream buffer iterator for cout
	ostreambuf_iterator<char> output(cout);

	// while input iterator is valid
	while(inpos != endpos){
		*outpos = *inpos;	// assign its value to the output iterator
		++inpos;
		++outpos;
	}
}*/

// io/outbuf1.hpp
/*
#include <streambuf>
#include <locale>
#include <cstdio>

class outbuf: public std::streambuf{
	protected:
		// central output function
		// - print characters in uppercase mode
		virtual int_type overflow(int_type c){
			if(c != EOF){
				// convert lowercase to uppercase
				c = std::toupper(c.getloc());

				// and write the character to the standard output
				if(std::putchar(c) == EOF){
					return EOF;
				}
			}
			return c;
		}
};*/

// io/outbuf1.cpp
//
#include <iostream>
#include <outbuf1.hpp>

int main()
{
	outbuf ob;					// create special output buffer
	std::ostream out(&ob);		// initialize output stream with that output buffer

	out << "31 hexadecimal:	" << std::hex << 31 << std::endl;
}
