//------------------------------------------------------
//这里是对书上的示例代码进行书写，主要目的是为了熟悉template模板
/*
template<typename T> class Blob{
	public:
		typedef T value_type;
		typedef typename std::vector<T>::size_type size_type;
		//构造函数
		Blob();
		Blob(std::initializer_list<T> il);
		//Blob中的元素数目
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		//添加或删除元素
		void push_back(const T &t) { data->push_back(t); }
		//移动元素
		void push_back(const T &&t) { data->push_back(std::move(t)); }
		void pop_back();
		//元素访问
		T& back();
		T& operator[](size_type i);
	private:
		std::shared_ptr<std::vector<T>> data;
		//若data[i]无效，则抛出msg
		void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const{
	if( i >= data.size() )
			throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back(){
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i){
	//如果i太大,check会抛出异常,阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back(){
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()){ }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)){ }
*/

/*
 * 这里学习Blob_ptr主要学习理解的是模板本身不是类型，需要具体实例化后才算做类
 * */
template<typename T> class Blob_Ptr{
	public:
		Blob_ptr(): curr(0){ }
		Blob(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) { }
		T& operator*() const{
			auto p = check(curr, "deference past end");
			return (*p)[curr];									//*p为本对象指向的vector
		}
		//递增或递减
		BlobPtr& operator++();									//前置运算符
		BlobPtr& operator--();
	private:
		//若检查成功, check返回一个指向vector的shared_ptr
		std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
		std::weak_ptr<std::vector<T>> wptr;
		std::size_t curr;

}
