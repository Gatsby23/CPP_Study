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
 
}
