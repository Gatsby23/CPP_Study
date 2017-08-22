class CDemo{
	private:
		int n;
	public:
		CDemo(int i = 0):n(i) { }
		CDemo operator++();				//前置形式
		CDemo operator--();				//后置形式
		operator int() { return n; }	//用于强制类型转换重载
		friend CDemo operator--(CDemo&);
		friend CDemo operator++(CDemo&, int);
};

CDemo CDemo::operator++(){				//前置++
	n++;
	return *this;
}

CDemo CDemo::operator++(int k){			//后置++
	CDemo tmp(*this);					//记录修改前的对象
	n++;
	return tmp;							//返回修改前的对象
}

CDemo operator--(CDemo &d){				//前置--
	d.n--;
	return d;
}

CDemo operator--(CDemo &d, int){		//后置--
	CDemo tmp(d);
	d.n--;
	return tmp;
}
