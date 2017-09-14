class Disc_quote: public Quote{
	public:
		Disc_quote(const std::string &book="", double sales_price = 0.0, size_t qty = 0, double disc = 0.0):Quote(book, sales_price), quantity(qty), discount(disc){}
		double net_price(size_t cnt) const = 0;
	protected:
		size_t quantity;
		double discount;
};

class Bulk_quote: public Disc_quote{
	Bulk_quote(const string &book="", double sales_price = 0, size_t qty = 0, double disc_rate = 0):Disc_quote(book, sales_price, qty, disc_rate){ };
	double net_price( size_t cnt ) const{
		if( cnt > quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}	
};
