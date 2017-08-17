//--------------------------------------------------------------------------修改分割线--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------第三章对于数组的一些操作------------------------------------------------------------------------------------------------------------------------------
/*
#include <iostream>
#include <assert.h>
using namespace std;

//经典操作:用typedef将类型标识符和数组关联起来
const int CAPACITY = 4;
typedef int IntArray[CAPACITY];

//Example3.1数组输出函数
void display( IntArray theArray, int numValues){
	//注意这里是numValues是小于数组容量的,主要将数组中的前numValues个值输出到屏幕上
	for(int i = 0; i < numValues; i++)
		cout << theArray[i] << "	";
	cout << endl;
}

void  read(IntArray theArray, int capacity, int numValues){
//将从键盘获取的值输入到数组中去

//经典操作: 先进行断言判断,需要输入的元素个数是不是满足数组容量要求
assert(numValues >= 0 && numValues <= capacity);

for(int i = 0; i < numValues; i++)
	cin >> theArray[i];
}

int main()
{
	IntArray a, b, c;
	
	cout << "Enter " << CAPACITY << " integer values for: " << endl;
	cout << "Array a: ";
	read(a, CAPACITY, CAPACITY);
	cout << "Array b: ";
	read(b, CAPACITY, CAPACITY);
	cout << "Array c: ";
	read(c, CAPACITY, CAPACITY);
	
	cout << "\n--------------------Part I of the demonstration-----------------------------\n\n"
		 << "The arrays are: " << endl;
	cout << "a: "; display(a, CAPACITY);
	cout << "b: "; display(b, CAPACITY);
	cout << "c: "; display(c, CAPACITY);
	
	//现在修改b中的数组元素, 但是使用一些越界的索引
	int below = -3, above = 6;
	b[below] = -999;
	b[above] = 999;
	
	cout << "\n-------------------Part II of the demonstration-----------------------------\n\n"
		 << "The arrays after out-of-range errors are: " << endl;
	cout << "a: "; display(a, CAPACITY);  
	cout << "b: "; display(b, CAPACITY);
	cout << "c: "; display(c, CAPACITY);
	cout << endl;
}*/

//---------------------------------------------------------------------修改分割线----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//new的几种初始失败的情况
//1.未捕获的bad_alloc异常情况
/*
#include <iostream>
#include <new>													//new, bad_alloc情况

using namespace std;

int main()
{
	const int NUM_ARRAYS = 99999;
	cout << "How large should the arrays of doubles be ?";
	
	int capacity;
	cin >> capacity;
	
	double* arrayPtr[NUM_ARRAYS];
	int i;
	for(i = 0; i < NUM_ARRAYS; i++){
		arrayPtr[i] = new double [capacity];
		cout << "Allocated " << capacity << " doubles for i = " << i << endl;	
	} 
	
	cout << "All " << NUM_ARRAYS << " arrays of " << capacity << " doubles were allocated successfully." << endl;
}
*/

//new的失败版本2
//演示new的第二种失败,使用try-catch机制处理bad_alloc异常.
/*
#include <iostream>
#include <new>									//new, bad_alloc

using namespace std;

int main()
{
	const int NUM_ARRAYS = 9999999;
	cout << "How large should the arrays of doubles be? ";
	int capacity;
	cin >> capacity;
	
	double* arrayPtr[NUM_ARRAYS];
	int i;
	
	try{
		for( i = 0; i < NUM_ARRAYS; i++){
			arrayPtr[i] = new double[capacity];	
			cout << "Allocated " << capacity << " doubles for i = " << i << endl;
		}
	}catch(bad_alloc ex){
		cout << "\nException: " << ex.what()
			 << " for i = " << i << endl;
		exit(1);	
	}
	cout << "All " << NUM_ARRAYS << " arrays of " << capacity 
	<< " doubles were allocated successfully." << endl;
}*/

//用nothrow版本进行内存修改->确定nothrow版本不会抛出异常
/*
#include <iostream>
#include <new>				//new, nothrow

using namespace std;

int main()
{
	const int NUM_ARRAYS = 99999999;
	cout << "How large should the arrays of doubles be ?";
	int capacity;
	cin >> capacity;
	
	double *arrayPtr[NUM_ARRAYS];
	int i;
	for(i = 0; i < NUM_ARRAYS; i++){
		arrayPtr[i] = new(nothrow) double[capacity];
		if(arrayPtr[i] == 0){					//空地址
			cout << "Allocation failed for i = " << i << endl;
			exit(1);
		}
		cout << "Allocated " << capacity << " doubles for i = " << i << endl;
	}
		
	cout << "All " << NUM_ARRAYS << " arrays of " << capacity << " doubles were allocated successfully." << endl;
}*/

//用过程式编程方法实现一个Time类
//Time.h
/*==Time.h=========================================================================================================================================
这个头文件里主要定义了用于处理时间的数据类型Time
基本操作包括:
	set:		设置时间
	display:	显示时间
	advance:	将时间前进某个给定量
	lessThan:	判断某个时间是否小于另一个时间
==================================================================================================================================================*/

#include <iostream>
using namespace std;

struct Time{
	unsigned Hour, 
			 Minute;
	char AMorPM;			//'A'or'P'
	unsigned milTime;		//等价的军用格式时间
};

void set(Time& t, unsigned hours, unsigned minutes, char AMPM);
/*-------------------------------------------------------------------------------------------------------------------------------------------------
将时间设置为一个给定的值
接受:			Time对象t
				hours, 以标准时间衡量的小时数
				minutes, 以标准时间衡量的分钟数
				APMP('A' if AM, 'P' if PM)
回传:			将数据成员设置为给定值后的Time t
--------------------------------------------------------------------------------------------------------------------------------------------------*/

void display(const Time &t, ostream& out);
/*--------------------------------------------------------------------------------------------------------------------------------------------------
使用输出流out显示标准或者军用格式的时间
接受:			Time t和ostream out
输出:			将时间t输出到out
回传:			将t的表示插入到ostream, 返回修改后的ostream out
---------------------------------------------------------------------------------------------------------------------------------------------------*/

void advance(Time &t, unsigned hours, unsigned minutes);
/*---------------------------------------------------------------------------------------------------------------------------------------------------
将时间前进一个给定的值
接受:			Time对象t
				hours, 要增加的小时数
				minutes, 要增加的分钟数
回传:			数据成员被增加了给定的值后的Time t
----------------------------------------------------------------------------------------------------------------------------------------------------*/

bool lessThan(const Time &t1, const Time &t2);
/*----------------------------------------------------------------------------------------------------------------------------------------------------
判断是否一个时间小于另一个时间
接受:			Time t1和t2
返回:			如果t1<t2返回true,否则返回false;
----------------------------------------------------------------------------------------------------------------------------------------------------*/

/**工具函数**/
int toMilitary(unsigned hours, unsigned minutes, char AMPM);
void toStandard(unsigned military, unsigned &hours, unsigned &minutes, char &AMPM);

//--------------------set()定义-----------------------------------------------------------------------------------------------------------------------
void set(Time &t, unsigned hours, unsigned minutes, char AMPM){
	if(hours >= 1 && hours <= 12 && minutes > 0 && minutes < 59 && (AMPM == 'A' || AMPM == 'P')){
		t.hour = hours;
		t.minutes = minutes;
		t.AMorPm = AMPM;
		t.milTime = toMilitary(hours, minutes, AMPM);
	}else
		cerr << "****************Can't set time with these values************************\n";
	//t保持未改变
}

//-----------------------------------display()的定义-----------------------------------------------------------------------------------------------
void display(const Time &t, ostream &out){
	out << t.hour << ':'
		<< (t.minute < 10 ? "0" : "") << t.minute
		<< ' ' << t.AMorPM << ".M.(" << t.milTime << " mil. Time)";
}

//----------------------------------advance()定义--------------------------------------------------------------------------------------------------
void advance(Time &t, unsigned hours, unsigned minutes){
	//使用军用格式时间前进
	t.milTime += 100 * hours + minutes;
	unsigned milHours = t.milTime / 100,
			 milMins = t.milTime & 100;
	
	//调整成正确格式
	milHours += milMins / 60;
	milMins %= 60;
	milHours %= 24;
	t.milTime = 100 * milHOurs + milMins;

	//现在设置标准格式时间
	toStandard(t.milTime, t.hour, t.minute, t.AMorPM);
}


//---------------------------------lessThan()的定义----------------------------------------------------------------------------------------------
bool lessThan(const Time &t1, const Time &t2){
	return t1.milTime < t2.milTime;
}


//工具函数的定义
int toMilitary(unsigned hours, unsigned minutes, char AMPM){
/*-----------------------------------------------------------------------------------------------------------------------------------------------
将标准格式时间转换为军用格式时间
接收:	 	hours, minutes, AMPM
返回:		等价的军用格式时间
-----------------------------------------------------------------------------------------------------------------------------------------------*/
	if(hours == 12)
		hours = 0;
	return hours*100 + minutes + (AMPM = 'P' ? 1200 : 0);
}

/*------------------------------------------------------------------------------------------------------------------------------------------------
将军用格式时间转换为标准格式时间
接收: military, 军用格式时间
返回: hours, minutes, AMPM---等价的标准时间格式
------------------------------------------------------------------------------------------------------------------------------------------------*/
void toStandard(unsigned military, unsigned &hours, unsigned &minutes, char &AMPM){
	hours = (military / 100) % 12;
	if(hours == 0)
		hours = 12;
	minutes = military % 100;
	AMPM = (military / 100) < 12 ? 'A' : 'P';
}





































