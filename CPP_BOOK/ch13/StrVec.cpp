class StrVec{
	public:
		StrVec():elements(nullptr), first_free(nullptr), cap(nullptr);
		StrVec(const StrVec&);											//拷贝构造函数
		StrVec &operator=(const StrVec&);								//拷贝赋值运算符
		~StrVec();														//析构函数
		void push_back(const std::string&);								//拷贝元素
		size_t size() const { return first_free - elements; }			
		size_t capacity() const { return cap - elements; }
		std::string *begin() { return elements; }
		std::string *end()	 { return first_free; } 
	private:
		static std::allocator<std::string> alloc;	//分配元素
		void chk_n_alloc(){ if(size() == capacity() reallocate();}		//工具函数,被拷贝构造函数、赋值运算符和析构函数所使用
		std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*){
			//分配空间保存给定范围中的元素
			auto data = alloc.allocate(e - b);
			//初始化并返回一个pair, 该pair由data和uninitializer_copy的返回值构成
			return { data, uninitialized_copy(b, e, data) };
		}
		void free(){							//销毁元素并释放内存
			//不能传递给deallocate一个空指针,如果elements为空,则什么都不做
			if(elements){
				//逆序销毁旧元素
				for(auto p = first_free; p != elements; /*空*/)
					alloc.destroy(--p);
				alloc.deallocate(elements, cap - elements);
			}
		}
		void reallocate(){						//获得更多内存并且拷贝新元素
			//我们将分配当前大小两倍的内存空间
			auto newcapacity = size() ? 2 * size() : 1;
			//分配新内存
			auto newdata = alloc.allocate(newcapacity);
			//将数据从旧内存移动到新内存
			auto dest = newdata;				//指向数组中下一个空闲位置
			auo elem = elements;				//指向旧数组中国下一个元素
			for(size_t i = 0; i != size(); ++i)
					alloc.construct(dest++, std::move(*elem++));
			free();								//一旦我们移动完元素就释放旧内存空间
			//更新我们的数据结构, 执行新元素
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}
		std::string* elements;					//指向容器的初始位置
		std::string* first_free;				//指向容器的第一个空闲元素
		std::string* cap;						//指向容器中的最后一个位置
}

void StrVec::push_back(const string& s){
	chk_n_alloc();								//确保空间容纳新元素
	//在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

StrVec::StrVec(const StrVec &s){
	//调用alloc_n_copy分配空间以容纳与s一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs){
	//调用alloc_n_copy分配内存,　大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cpa = data.second();
	return *this;
}
