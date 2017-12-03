typedef int Rank;											//秩
#define DEFAULT_CAPACITY 3									//默认的初始容量

template<typename T>class Vector{							//向量模板类
	protected:
		Rank _size; int _capacity;	T* _elem;				//规模、容量、数据区
		void copyFrom(T const* A, Rank lo, Rank hi);		//赋值数组区间[lo, hi)
		void expand();										//空间不足时扩容
		void shrink();										//装填因子过小时压缩
		bool bubble(Rank lo, Rank hi);						//扫描交换
		void bubbleSort(Rank lo, Rank hi);					//起泡排序算法
		Rank max(Rank lo, Rank hi);							//选取最大的元素
		void selectionSort(Rank lo, Rank hi);				//选择排序算法
		void merge(Rank lo, Rank mi, Rank hi);				//归并算法
		void mergeSort(Rank lo, Rank hi);					//归并排序算法
		Rank partition(Rank lo, Rank hi);					//轴点构造算法
		void quickSort(Rank lo, Rank hi);					//快速排序算法
		void heapSort(Rank lo, Rank hi);					//堆排序
	public:
		//构造函数
		Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){	//容量为c、规模为s、所有元素初始化为v
			_elem = new T[_capacity = c];
			for(_size = 0; _size < s; _elem[_size++] = v)
		}//s<=c
		Vector(T const* A, Rank n){ copyFrom(A, 0, n); }	//数组整体复制
		Vector(T const* A, Rank lo, Rank hi){ copyFrom(A, lo, hi); }	//区间
		Vector(Vector<T> const& V){ copyFrom(V._elem, 0, V._size); }	//向量整体复制
		Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //区间

		//析构
		~Vector(){ delete[] _elem; }						//释放内部空间

		//只读访问接口
		Rank size() const { return _size; }					//规模
		bool empty() const { return !_size; }				//判断非空
		int disordered() const;								//判断向量是否排序

}

template<typename T>
void Vector<T>::expand(){
	if(_size < _capacity) return;
	_capacity = max(_capacity, DEFAULT_CAPACITY);
	T* oldElem = _elem; _elem = new T[capacity <= 1];
	for(int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete [] oldElem;
}

template<typename T>int Vector<T>::uniquify(){
	int oldSize = _size; int i = 0;						//从首元素开始
	while(i < _size - 1)
		(_elem[i] == _elem[i+1]) ? remove(i+1) : i++;
	return oldSize - _size;
}//注意：其中_size的减小, 由remove完成

template<typename T> int Vector<T>::uniquify(){
	Rank i = 0, j = 0;		//各对互异"相邻"元素的秩
	while(++j < _size)		//逐一扫描,直至末元素
		//跳过雷同者;发现不同元素时,向前移至紧邻于前者的右侧
		if(_elem[i] != _elem[j]) _elem[++i] = _elem[j];
	_size = ++i; shrink();	//直接截除尾部多余元素
	return j - i;
}//注意:通过remove(lo, hi)批量删除,依然不能达到高效率

template<typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const{
	return (rand() % 2) ? binSearch(_elem, e, lo, hi): fibSearch(_elem, e, lo, hi);
}

template<typename T>
static Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
	while(lo < hi){
		Rank mi = (lo+hi) >> 1;
		if (e < A[mi]) hi = mi;
		else if (A[mi] < e) lo = mi + 1;
		else  return mi;
	}
	return -1;
}

template<typename T>
static Rank fibSearch(T* A, T const &e, Rank lo, Rank hi){
	Fib fib(hi - lo);
	while(lo < hi){
		while(hi - lo < fib.get()) fib.prev();
		Rank mi = lo + fib.get() - 1;
		if(e < A[mi]) hi = mi;
		else if (A[mi] < e) lo = mi + 1;
		else return mi;							//在mi处命中
	}
	return -1;
}

template<typename T> 
static Rank binSearch(T* A, T const &e, Rank lo, Rank hi){
	while(1 < hi-lo){
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi;
	}
	return (e == A[lo]) ? lo : -1;				//返回命中元素的秩或者-1
}


