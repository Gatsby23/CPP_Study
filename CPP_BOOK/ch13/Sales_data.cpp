class Sales_data{
	public:
		  //其他成员和构造函数的定义
		  //与合成的拷贝构造函数等价的拷贝构造函数说明
		  Sales_data(const Sales_data&);
	private:
		  std::string bookNo;
		  int units_sold = 0;
		  double revenue = 0.0;
};

//与Sales_data的合成拷贝构造函数等价
Sales_data::Sales_data(const Sales_data &orig):bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue){}

Sales_data& Sales_data::operator=(const Sales_data &rhs){
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return this;
}
