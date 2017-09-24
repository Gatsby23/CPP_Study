class Limited_quote : public Quote{
	public:
		double net_price(size_t cnt) const override{
			if(cnt <= min_qty)
				return cnt * (1 - discount) * price;
			else
				return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
		}
	private:
		size_t min_qty;
		double discount;
}
