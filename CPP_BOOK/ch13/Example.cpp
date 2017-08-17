class hasPtr{
	public:
		hasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) {}
		//对ps指向的string,每个hasPtr对象都有自己的拷贝
		hasPtr(const hasPtr &p): ps(new std::string(*p.ps)), i(p.i){}
		hasPtr& operator=(const hasPtr &);
		~hasPtr() {delete ps;}
	private:
		std::string *ps;
		int i;
};


