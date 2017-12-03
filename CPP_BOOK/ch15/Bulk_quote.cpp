class Bulk_quote:public Quote{
	public:
		double net_price(size_t cnt) const override{
			if(cnt > min_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	private:
		size_t min_qty;
		double discount;
}
