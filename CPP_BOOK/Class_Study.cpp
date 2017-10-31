//===============================================================================================
//1.依据类的操作,定义类的数据成员
//----------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sales_data{
	private:
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
	public:
		string isbn() const { return bookNo; }
		Sales_data& combine(const Sales_data&);
	    double avg_price() const;	
};

Sales_data& Sales_data::combine(const Sales_data& rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return * this;
}

istream &read(istream &is, Sales_data &item){
	double price = 0;
	is >> item.booKNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item){
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}


Sales_data add(const Sales_data& lhs, const Sales_data& rhs){
	Sales_data sum  = lhs;
	sum.combine(rhs);
	return sum;
}
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

int main()
{
	Sales_data total;//保存下一条记录的标量
	//读入第一条交易数据,并且保证有数据可以处理
	if(read(cin, total)){
		Sales_data trans;		//保存和的变量
		//读入并处理交易记录
		while(read(cin, trans)){
			//如果我们仍在处理相同的书
			if(total.isbn() = trans.isbn())
				total += trans;	//更新销售总额
			else{
				print(cout, total);
				cout << endl;
				total = trans;			//total现在表示下一本书的销售额
			}
		}
		print(cout, total);
	    cout << endl;			//打印最后一本书的结果
	}else{
		//没有输入, 警告读者
		cerr << "No Data?!" << endl;
		return -1;
	}
	return 0;
}

//===============================================================================================
//2.还是考察对类的对象和操作的理解
//-----------------------------------------------------------------------------------------------
/*
#include <iostream>
#include <string>

using namespace std;

class Person{
	private:
		string _name;
		string _address;
	public:
		string isName() const { return _name; }
		string isAddress() const { return _address;}
};*/

//===============================================================================================
//3.对构造函数的理解
//-----------------------------------------------------------------------------------------------
//3. 对Sales_data添加构造函数
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data{
	public:
		Sales_data() = default;
		Sales_data(const string &s):bookNo(s){ }
		Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
	    Sales_data(istream &is){ is >> *this; }	
	private:
		string bookNo;
		unsigned units_sold;
		double revenue;
};

istream& read(istream& is, Sales_data& item){
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	return is;
}

ostream& print(ostream& os, const Sales_data& item){
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

int main()
{
	Sales_data book1;
	Sales_data book2("123");
	Sales_data book3(cin);
	print(cout, book1);
}*/
