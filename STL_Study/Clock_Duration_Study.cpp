/*
 * Unix/Posix的Clock库
 * 

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	milliseconds ms(7255042);
	//split into hours, minutes, seconds, and milliseconds;

	hours hh = duration_cast<hours>(ms);
	minutes mm = duration_cast<minutes>(ms % chrono::hours(1));
	seconds ss = duration_cast<seconds>(ms % chrono::minutes(1));
	milliseconds msec = duration_cast<milliseconds>(ms % chrono::seconds(1));

	//and print durations and values
	cout << "raw: " << hh << "::" << mm << "::" << ss << "::" << msec << endl;
	cout << "     " << setfill('0') << setw(2) << hh.count() << "::" << setw(2) << mm.count() << "::"
								<< set2(2) << ss.count() << "::" << setw(3) << msec.count() << endl;
}
*/


//util/clock.hpp
/*
#include <chrono>
#include <iostream>
#include <iomanip>

template<typename C>
void printClockData(){
	using namespace std;

	cout << "- precision: ";
	//if time unit is less or equal one millisecond
	typedef typename C::period P;																		//type of time unit
	if(ratio_less_equal<P, milli>::value){
		//convert to and print as millseconds;
		typedef typename ratio_multiply<P, kilo>::type TT;
		cout << fixed << double(TT::num)/TT::den << "milliseconds" << endl;
	}else{
		// print as seconds
		cout << fixed << double(P::num)/P::den << " seconds" << endl;
	}
	cout << "- is_steady: " << boolalpha << C::is_steady << endl;
}

int main()
{
	std::cout << "system_clock: " << std::endl;
	printClockData<std::chrono::system_clock>();

	std::cout << "\nhigh_resolution_clock: " << std::endl;
	printClockData<std::chrono::high_resolution_clock>();

	std::cout << "\nsteady_clock: " << std::endl;
	printClockData<std::chrono::steady_clock>();
}*/


//util/chrono1.cpp
/*
#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

std::string asString(const std::chrono::system_clock::time_point& tp){
	//convert to system time.
	std::time_t t = std::chrono::system_clock::to_time_t(tp);					 //将timepoint转换成一个"传统C和POSIX提供的时间类型time_t"的对象
	std::string ts = std::ctime(&t);											//convert to calendar time
	ts.resize(ts.size() - 1);
	return ts;
}

int main()
{
	//print the epoch of this system clock
	std::chrono::system_clock::time_point tp;
	std::cout << "epoch: " << asString(tp) << std::endl;

	//print current time
	tp = std::chrono::system_clock::now();
	std::cout << "now:	" << asString(tp) << std::endl;
	
	//print the minimum time of this system clock:
	tp = std::chrono::system_clock::time_point::min();
	std::cout << "min:	" << asString(tp) << std::endl;

	//print maximum time of this system clock:
	tp = std::chrono::system_clock::time_point::max();
	std::cout << "max:	" << asString(tp) << std::endl;
}*/

//util/timpoint.hpp
//
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

//convert timepoint of system clock to calendar time string
inline
std::string asString(const std::chrono::system_clock::time_point& tp){
	//convert to system time
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	std::string ts = ctime(&t);													//convert to calendar time
	ts.resize(ts.size() - 1);													//skip trailing newline
	return ts;
}

//convert calendar time to timepoint of system clock
inline
std::chrono::system_clock::time_point makeTimePoint(int year, int mon, int day, int hour, int min, int sec = 0){
	struct std::tm t;
	t.tm_sec = sec;						// second of minute(0..59 and 60 for leap seconds)
	t.tm_min = min;						// minute of hour(0...59);
	t.tm_hour = hour;					// hour of day(0...23);
	t.tm_mday = day;					// day of month(0...31);
	t.tm_mon = mon-1;					// month of year(0...11);
	t.tm_year = year - 1900;			// year since 1900;
	t.tm_isdst = -1;					// determine wheter daylight saving time
	std::time_t tt = std::mktime(&t);
	if(tt == -1){
		throw "no valid system time";
	}
	return std::chrono::system_clock::from_time_t(tt);
}

int main()
{
	auto tp1 = makeTimePoint(2010, 01, 01, 00, 00);
	std::cout << asString(tp1) << std::endl;

	auto tp2 = makeTimePoint(2011, 05, 23, 13, 44);
	std::cout << asString(tp2) << std::endl;

}
