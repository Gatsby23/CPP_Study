class Quote{
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price):bookNo(book), price(sales_price){}

		std::string isbn() const { return bookNo; }
		//返回给定数量的书籍的销售总额,派生类改写并使用不同的折扣计算方法
		virtual double net_price(std::size_t n) const { return n*price; }
		virtual void debug(){ cout << "bookNo=" << bookNo << " price=" << price << endl; }
		virtual ~Quote()=default;											//对析构函数进行动态绑定

	private:
		std::string bookNo;													//书籍的ISBN编号
	
	protected:
		double price=0.0;													//代表普通状态下不打折的价格		
};

class Bulk_quote:public Quote{
	Bulk_quote(const string &book="", double sales_price = 0, size_t qty = 0, double disc_rate = 0):
			Quote(book,sales_price), min_qty(qty), discount(disc_rate){ }

	double net_price( size_t cnt ) const{
		if( cnt > min_qty )
			return cnt * (1 - discount) * price;
		else
			return cnt * price;	
	}

	virtual void debug(){
		Quote::debug();													//bookNo为private,不能直接访问，只能调用基类的degub()函数来显示
		cout << "min_qty" << min_qty << " discount=" << discount << endl;
	}

	private:
		size_t min_qty;
		double discount;
}
