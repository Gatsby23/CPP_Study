template <typename T>
class vector{
	public:
			void push_back(T const&);
			void clear();
	private:
			T* elements;
};

template<typename T>
class vector{
	public:
			void clear();
			
	private:
			T* elements;
};

template<typename T>
void vector<T>::clear(){		//函数实现放在这边
	//函数体
}
