<<<<<<< HEAD
typedef int Rank;																		//秩
#define DEFAULT_CAPACITY 3																//默认的初始容量(实际应用中设置为更大)

template <typename T>class Vector{														//向量模板类
protected:
	Rank _size; int _capacity; T* _elem;												//规模，容量、数据区
	void copyFrom(T const* A, Rank lo, Rank hi);										//复制数组区间A[lo, hi)
	void expand();																		//空间不足时扩容
	void shrink();																		//装填因子过小时缩减
	bool bubble(Rank lo, Rank hi);														//扫描交换
	void bubbleSort(Rank lo, Rank hi);													//起泡排序算法
	Rank max(Rank lo, Rank hi);															//选取最大的元素
	void selectionSort(Rank lo, Rank hi);												//归并算法
	void merge(Rank lo, Rank mi, Rank hi);												//归并算法
	void mergeSort(Rank lo, Rank hi);													//归并排序算法
	Rank partition(Rank lo, Rank hi);													//轴点构造算法
	void quickSort(Rank lo, Rank hi);													//快速排序算法
	void heapSort(Rank lo, Rank hi);													//堆排序(稍后看)
public:
	//构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){								//容量为c、规模为s、所有蒜素初始为v
		_elem = new T[_capacity = c];
		for(_size = 0; _size < s; _elem[_size++] = v);									// s <= c
	}
	Vector(T const* A, Rank n){ copyFrom(A, 0, n); }									//数组整体复制
	Vector(T const* A, Rank lo, Rank hi){ copyFrom(A, lo, hi); }						//区间整体复制
	Vector(Vector<T> const& V){ copyFrom(V._elem, 0, V._size); }						//向量整体复制
	Vector(Vector<T> const& V, Rank lo, Rank hi){ copyFrom(v._elem, lo, hi); }			//区间复制

	//析构函数
	~Vector(){ delete []_elem; }														//释放内部空间
	//只读访问接口
	Rank size() const { return _size; }													//规模
	bool empty() const { return !_size; }												//判空
	int disordered() const;																//判断向量是否排序
 
=======
typedef int Rank;										//秩
#define DEFAULT_CAPACITY 3								//默认的初始容量(实际应用中可设置为更大)

template<typename T>class Vector{						//向量模板类
	protected:
		Rank _size; int _capacity; T* _elem;			//规模、容量、数据区
		void copyFrom(T const* A, Rank lo, Rank hi);	//赋值数组区间[lo, hi)
		void exapnd();									//空间不足时扩容
		void shrink();									//装填因子过小时压缩
		bool bubble(Rank lo, Rank hi);					//扫描交换
		void bubbleSort(Rank lo, Rank hi);				//起泡排序算法
		Rank max(Rank lo, Rank hi);						//选取最大的元素
		void selectionSort(Rank lo, Rank hi);			//选择排序算法
		void merge(Rank lo, Rank mi, Rank hi);			//归并算法
		void mergeSort(Rank lo, Rank hi);				//归并排序算法
		Rank partition(Rank lo, Rank hi);				//轴点构造算法
		void quickSort(Rank lo, Rank hi);				//快速排序算法
		void heapSort(Rank lo, Rank hi);				//堆排序(稍后完全堆讲解)

	public:
		//构造函数
		Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)	//容量为c、规模为s、所有元素初始化为v
		{ _elem = new T[_capacity = c]; for(_size = 0; _size < s; _elem[_size++] = v); }	//s<=c
		Vector(T const* A, Rank n) { copyFrom(A, 0, n); }		//数组整体复制
		Vector(T const* A, Rank lo, Rank hi){ copyFrom(A, lo, hi); }	//区间
		Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }	//向量整体复制
		Vector( Vector<T> const& V, Rank lo, Rank hi){ copyFrom(V._elem, lo, hi); }	//区间
		
		//析构
		~Vector(){ delete[] _elem;}						//释放内部空间

		//只读访问接口
		Rank size() const {  return _size; }			//规模
		bool empty() const { return !_size; }			//判断非空
		int disordered() const;							//判断向量是否排序
}

template<typename T>
void Vector<T>::expand(){								//向量空间不足时扩容
	if(_size < _capacity) return;						//尚未满足时，不必扩容
	_capacity = max(_capacity, DEFAULT_CAPACITY);		//不低于最小容量
	T* oldElem = _elem; _elem = new T[capacity <<= 1];	//容量加倍
	for(int i = 0; i < _size; i++)						//复制向量内容
		_elem[i] = oldElem[i];							//T为基本类型,或已重载赋值操作符"="
	delete [] oldElem;									//释放原空间
}

template<typename T> // 0 <= r < _size
T& Vector<T>::operator[]( Rank r) const { return _elem[r]; }

template<typename T> Rank Vector<T>::insert(Rank r, T const& e){
	expand();	//若有必要，扩容
	for(int i = _size; i > r; i--)						//自后向前
		_elem[i] = _elem[i - 1];						//后继元素顺次后移一个单元
	_elem[r] = e; _size++;								//置入新元素，更新容量
	return r;											//返回秩
}

template<typename T> int Vector<T>::remove(Rank lo, Rank hi){
	if(lo == hi) return 0;								//处于效率考虑，单独处理退化情况
	while(hi < _size) _elem[lo++] = _elem[hi++];		//[hi, _size)顺次前移hi-lo位
	_size = lo; shrink();								//更新规模，有必要缩容
	return hi - lo;										//返回被删除元素的数目
}

template<typename T>									//删除向量中秩为r的元素, 0<= r < _size
T vector<T>::remove(Rank r){
	T e = _elem[]r;										//备份被删除的元素
	remove(r, r+1);										//调用区间删除算法
	return e;											//返回被删除元素
}

template<typename T>									//0 <= lo < hi <= _size
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const{
	while((lo < hi--) && (e!= _elem[hi]))              //逆向查找
	return hi;										   // hi < lo 意味着失败, 否则hi即命中元素的秩
}

template<typename T>
int Vector<T>::deduplicate(){
	int old_size = _size;
	Rank i = 1;
	while(i < _size)
		(find(_elem[i], 0, i) < 0) ? i++ :remove(i);
	return oldSize - _size;
}

template<typename T>
void Vector<T>::traverse(void (*visit)(T&)){
	for(int i = 0; i < _size; i++)
		visit(_elem[i]);
>>>>>>> 97ee67a8a08a5963941d7a54978cd8dbe1f5c097
}
