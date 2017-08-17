//------------------------------------------------------------------------修改分割线-----------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//1.重新编写Sales_data类,并向这个类中添加combine和isbn的成员
//2.Sales_data构造函数构建

/*
#include <iostream>
#include <string>

using namespace std;


class Sales_data{
	public:
		
		//Sales_data的构造函数
		Sales_data() = default;
		Sales_data(const string &s):bookNo(s){}
		Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
		Sales_data(std::istream &is);
			
		// isbn函数,返回bookNo;
		string isbn() const { return bookNo; }
		// combine函数用于把两个Isbn相同的销售记录合并在一起
		
		istream &read(istream &is, Sales_data &item){
			double price = 0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = price * item.units_sold;
			return is;
		}

		ostream &print(ostream &os, const Sales_data &item){
			os << item.isbn() << " " << item.units_sold << " "
			   << item.revenue << " " << item.avg_price();
			return os;			
		}

		Sales_data& combine( const Sales_data& rhs){
			units_sold += rhs.units_sold;						//累加书籍的销售量
			saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
			if(sellingprice != 0)
				discount = saleprice / sellingprice;			//重新计算实际折扣
			return *this;
		}
	private:
		string bookNo;											//书籍编号,隐式初始化为空串
		unsigned units_sold = 0;								//销售量,显示初始化为0
		double sellingprice = 0.0;								//原始价格,显示初始化为0.0
		double saleprice = 0.0;									//实售价格,显示初始化为0.0
		double discount = 0.0;									//折扣,显示初始化为0.0
};

//2.重修修改交易处理程序,保证其使用新加入的成员

int main()
{
	cout << "请输入交易记录(ISBN、销售量、原价、实际售价): " << endl;
	Sales_data total;											//保存下一条交易记录的变量
	//读入第一条交易记录,并确保有数据可以处理
	if(cin >> total){
		Sales_data trans;										//保存和的变量
		//读入并处理剩余交易记录
		while(cin >> trans){
			//如果我们仍在处理相同的书
			if(total.isbn() == trans.isbn())
				total.combine(trans);							//更新总销售额
			else{
				//打印前一本书的结果
				cout << total << endl;
				total = trans;									//total 现在表示下一本书的销售额
			}
		}
	cout << total << endl;										//打印最后一本书的结果
	}
	else{
		//没有输入!警告读者
		cerr << "No data?!" << endl;
		return -1;												//表示失败
	}
	return 0;
}
*/
//3.编写类
//编写一个Person类,用string对象存储人员的姓名和住址,并提供一些操作能返回姓名和住址
/*
class Person{
	public:
		Person() = default;
		Person(const string &name, const string &add){ strName = name; strAddress = add;}
		void getName() const { return strName; }
		void getAddress() const { return strAddress; }
	private:
		string strName;
		string strAddress;
};*/

class Sales_data{
	private:
		unsigned height = 0, width = 0;
		unsigned cursor = 0;
		string contents;
	public:
		Screen() = default;
		Screen(unsigned ht, unsigned wd):height(ht), width(wd), contents(ht*wd, ' '){}
		Screen(unsigned ht, unsigned wd, char c):height(ht), width(wd), contents(ht*wd, c){}
};
