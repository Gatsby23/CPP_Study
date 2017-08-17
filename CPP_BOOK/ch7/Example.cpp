//--------------------------------------------------------------------------修改分割线---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

//1.回顾第1章和第2章中使用的Sales_item类
/*
struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};*/


//2.现在自己设计Sales_data类,保证:1.有isbn成员函数,返回对象的isbn编号2.有combine的成员函数,将一个对象加到另一个对象上3.一个名为add的函数,实现两个对象的加法4.一个read函数,将数据从istream读入到Sales_data函数中5.print函数,将Sales_data对象值输出到ostream中

//先从类的使用者出发考虑,看应该如何使用一个类,编写相当于类的测试函数

/*
Sales_data total;																	//保存当前求和结果变量
if(read(cin, total) ){																//读入第一笔交易
	Sales_data trans;																//保存下一条交易数据的变量
	while(read(cin, trans)){														//读入剩余交易
		if(total.isbn() == trans.isbn())											//检查isbn
			total.combine(trans);													//更新变量total当前的值
		else{
			print(cout, total) << endl;												//输出结果
			total = trans;															//处理下一本书
		}
	}
	print(cout, total) << endl;														//输出最后一笔交易
}else{
	cerr << "No data?!" << endl;													//通知用户
}
*/
/*
//对类Sales_dataa进行改进
struct Sales_data{
	//新成员:关于Sales_data对象的操作
	std::string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	//数据成员与前面定义相同
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;	
};

//Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream& Sales_data&a);

double Sales_data::avg_price() const {
	if(units_sold)
		return revenue/units_sold
	else	
		return 0;
}

Sales_data& combine(const Sales_data &rhs){											//把rhs的成员加到this对象的成员上
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;																	//返回调用该函数的对象
}
*/

//4.给类加上访问限制符,考虑在访问限制的条件下类的修改
/*
class Sales_data{
	public:
		Sales_data() = default;	
		Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
		Sales_data(const string &s):bookNo(s){}
		Sales_data(istream&)
		string isbn() const { return bookNo; }
		Sales_data &combine(const Sales_data&)
	private:
		double avg_price() const { return units_sold ? revenue / units_sold : 0; }
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};*/


//加上友元修饰符,观察友元对类非成员函数的访问情况
/*
class Sales_data{
	//一般在类的开头或结尾定义友元修饰符
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend istream &read(istream&, Sales_data&);
	friend ostream &print(ostream&, Sales_data&);
	//其他成员访问说明符和之前一致
	public:
		Sales_data() = default;
		Sales_data(const string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n) {}
		Sales_data(const string &s):bookNo(s){}
		Sales_data(istream&);
		string isbn() const { return bookNo; }
		Sales_data &combine(const Sales_data&);
	private:
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
istream &read(istream& Sales_data&);
ostream &print(ostream& const Sales_data&); */

//这里是一个new的失败版本,对于new失败的主要原因是内存不足
//演示new的第一种失败--未捕获bad_alloc的异常
/*
#include <iostream>
#include <new>						//new, bad_alloc

using namespace std;

int main()
{
	const int NUM_ARRAYS = 10;
	cout << "How large should the arrays of doubles be?";
	int capacity;
	cin >> capacity;
	
	double* arrayPtr[NUM_ARRAYS];
	int i;
	for(i = 0; i < NUM_ARRAYS; i++){
		arrayPtr[i] = new double[capacity];
		cout << "Allocated " << capacity
		<< " doubles for i = " << i << endl;
	}
	
	cout << "All " << NUM_ARRAYS << " arrays of " << capacity << " doubles were allocated successfully." << endl;
} 
*/

//Screen类的构建
/*
class Screen{
	public:
		typedef string::size_type pos;
		//类似于
		using pos = string::size_type;
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		string contents;
};
*/

// 加上Screen构造函数,开始进行Screen优化
// 修改07.05:加上光标所在位置字符

/*
class Screen{
	public:
		typedef string::size_type pos;		//等价于using pos = string::size_type;
		Screen() = default;					//因为Screen有另外一个构造函数,所以必须要声明默认构造函数
		
		//Cursor 被其类初始值初始化为0
		Screen(pos ht, post wd, char c):height(ht), width(wd), contents(ht*wd, c){}
		char get() const { return contents[cursor]; }
		inline char get(pos ht, pos wd) const;			//显示内联
		Screen &move(pos r, pos c);						//能在之后设定为内联
		void some_member() const;
		Screen &set(char);
		Screen &set(pos, pos, char);
		Screen &display(ostream &os) { do_display(os);	return *this; }
		const Screen &display(ostream &os){ do_display(os); return *this; }
	private:
		void do_display(ostream &os) const {os << contents;}
		pos cursor = 0;
		pos height = 0, width = 0;
		string contents;
		mutable size_t access_ctr;						//即使在一个const对象内也能修改
};

inline Screen &Screen::set(char c){
	contents[cursor] = c;								//设置当前光标所在位置的新值
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch){
	contents[r * width + col] = col;					//设置给定位置的新值
	return *this;										//将this对象作为左值返回
}

void Screen::some_member() const{
	++access_ctr;										//保存一个计数值,用于记录成员函数被调用的次数
	//该成员需要完成的其他的工作
}

inline Screen &Screen::move(pos r, pos c){
	pos row = r * width;								//计算行所在的位置
	cursor = row + c;									//在行内将光标移到指定的列
	return *this;
};

char Screen::get(pos r, pos wd) const {
	pos row = r * width;								//计算行所在的位置
	return contents[row + c];							//返回给定列的字符
}*/

// 对类类型理解->利用X和Y的声明和定义

/*
class Y;
class X{
	public:
		Y *_toYPointer;
};

class Y{
	public:
		X x;
};*/

/*
class Window_mgr{
public:
	//窗口中每个屏幕的编号
	using ScreenIdex = vector<Screen>::size_type;
	//按照编号将指定的Screen重置成空白
	void clear(ScreenIdex);
private:
	vector<Screen> screens{ Screen(24, 80, ' ') };
};

void Window_mgr::clear(ScreenIdex){
	//s是一个Screen的引用,指向我们想清空的那块屏幕
	Screen &s = screens[i];
	
	//将那个选定的Screen重置为空白
	s.contents = string(s.height * s.width, ' ');
}
*/

//使用委托构造函数实现之前构造函数

#include <iostream>
#include <string>

using namespace std;

class Sales_data{
		friend istream &read( istream &is, Sales_data &item );
		friend ostream &print( ostream &os, const Sales_data &item );
	
	public:
		//委托构造函数
		Sales_data(const string &book, unsigned num, double sellp, double salep):bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep){
			if(sellingprice)
				discount = saleprice / sellingprice;
			cout << "该构造函数接受书号、销售量、原价、实际价格四个信息" << endl;
		} 
		Sales_data():Sales_data("", 0, 0, 0){
			cout << "该构造函数无须接受任何信息" << endl;
		}
		
		Sales_data(const string &book): Sales_data(book, 0, 0, 0){
			cout << "该构造函数接受书号信息" << endl;
		}

		Sales_data(istream &is):Sales_data(){
			read(is, *this);
			cout << "该构造函数接受用户输入的信息" << endl;
		}
	
	private:
		string bookNo;						//书籍编号,隐式初始化为空串
		unsigned units_sold;				//销售量,显示初始化为0
		double sellingprice = 0.0;			//原始价格,显示初始化为0.0
		double saleprice = 0.0;				//实售价格,显示初始化为0.0
		double discount = 0.0;				//折扣,显示初始化为0.0
};

istream &read(istream &is, Sales_data &item){
	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
	return is;
}

ostream &print(ostream &os, const Sales_data &item){
	os << item.bookNo << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
	return os;
}

int main()
{
	Sales_data fist("978-7-121-15535-2", 85, 128, 109);
	Sales_data second;
	Sales_data third("978-7-121-15535-2");
	Sales_data last(cin);
	return 0;
}
