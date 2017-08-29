class HasPtr{
	public:
		HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0){}
		//对ps指向的string,每个HasPtr对象都有自己的拷贝
		HasPtr(const HasPtr &p): ps(new std::string(*p.ps), i(p.i)){}
		HasPtr& operator=(const HasPtr &);
		~HasPtr(){ delete ps;}
	
	private:
		std::string *ps;
		int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	auto newp = new string(*rhs.ps);			//拷贝底层的string
	delete ps;									//释放旧内存
	ps = newp;									//从右侧运算对象拷贝数据到本对象
	i = rhs.i;
	return *this;								//返回本对象
}



class HasPtr2{
	public:
		//构造函数分配新的string和新的计数器，将计数器置为1
		HasPtr(const std::string &s = std::string()): ps(new std::string(s)), use(new std::size_t(1)){}
		//拷贝构造函数拷贝所有三个数据成员,并递增计数器
		HasPtr(const HasPtr &p):
				ps(p.ps), i(p.i), use(p.use){ ++*use; }
		HasPtr& operator=(const HasPtr&);
		~HasPtr();
	private:
		std::string *ps;
		int i;
		std::size_t *use;						//用来记录有多少个对象共享*ps的成员
};

HasPtr2& HasPtr2::operator=(const HasPtr &rhs){
	if(--*use == 0){							//如果引用计数为0
		delete ps;								//释放string内存
		delete use;								//释放计数器内存
	}
}

HasPtr2& HasPtr::operator=(const HasPtr2 &rhs){
	++*rhs.use;
	if(--*use == 0){							//递减本对象的引用计数
		delete ps;								//如果没有其他用户,释放本对象分配的成员
		delete use;
	}

	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;								//返回本对象
}
