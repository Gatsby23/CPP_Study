//
// Created by gatsby on 2019-01-14.
//
#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
typedef int Rank;																									// 秩的声明
#define DEFAULT_CAPACITY 3																							// 默认的初始容量
template<typename T>
class Vector{
protected:
	Rank _size;																										// 规模
	int _capacity;																									// 容量
	T* _elem;																										// 数据区
	void copyFrom(T const* A, Rank lo, Rank hi);																	// 复制数组区间A[lo, hi)
	void expand();																									// 空间不足时进行扩容
	void shrink();																									// 装填因子过小时进行压缩操作
public:
	// 构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)															// 容量为0, 规模为s,所有初始量为v
	{ _elem = new T[_capacity = c]; for(_size = 0; _size < s; _elem[_size++] = v); }
	Vector(T const* A, Rank n){ copyFrom(A, 0, n); }																// 数组整体复制
	Vector(T const* A, Rank lo, Rank hi){ copyFrom(A, lo, hi); }													// 数组区间复制
	Vector(Vector<T> const& V){ copyFrom(V._elem, 0, V._size); }													// 向量整体复制
	Vector(Vector<T> const& V, Rank lo, Rank hi){ copyFrom(V._elem, lo, hi); }										// 向量区间复制
	~Vector(){ delete []_elem;	}																					// 释放内部空间
	// 只读访问接口
	Rank size() const { return _size; }																				// 知道规模
	bool empty() const { return !_size;	}																			// 判断是否为空
	int disordered() const;		
	Rank find(T const& e) const { return find(e, 0, _size); }														// 无序向量空间整体查找元素
	Rank find(T const& e, Rank lo, Rank hi) const;																	// 无序向量区间查找
	// 可写访问接口
	T& operator[](Rank r) const;																					// 重载下标操作符, 可以类似于数组形式访问元素
	Vector<T> & operator=(Vector<T> const& );																		// 重载赋值操作符, 以便直接克隆向量
	T remove(Rank r);																								// 删除秩为r的元素
	int remove(Rank lo, Rank hi);																					// 删除秩在区间[lo, hi)之内的元素
	Rank insert(Rank r, T const& e);																				// 插入元素
	Rank insert(T const& e){ return insert(_size, e); }																// 默认作为末元素插入
	int depduplicate();																								// 无序去重
	// 遍历
	void traverse(void(*) (T&));																					// 遍历（使用函数指针, 只读或局部修改）
	template<typename VST> void traverse(VST&);																		// 遍历（使用函数对象，可做全局修改）
};
#endif //VECTOR_VECTOR_H
// 复制方法
template<typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi){																// 以数组区间A[lo, hi)为蓝本复制向量
	_elem = new T[_capacity = 2 * (hi - lo)];																		// 分配空间
	_size = 0;																										// 规模清零
	while(lo < hi)
		_elem[_size++] = A[lo++];																					// 元素逐一复制
}
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V){																// 重载
	if(_elem) delete[] _elem;																						// 释放原有空间
	copyFrom(V._elem, 0, V.size());																					// 整体复制
	return *this;
}
template<typename T>
void Vector<T>::expand(){																							// 向量空间不足时扩容
	if(_size < _capacity)	return;																					// 尚未满员, 不必扩容
	if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;													// 不低于最小容量
	T* oldElem = _elem; _elem = new T[_capacity << 1];																// 容量加倍
	for(int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];																						// 复制原向量内容到新向量当中
	delete [] oldElem;
}
template<typename T>
void Vector<T>::shrink(){																							// 装填因子过小时压缩向量占空间
	if(_capacity < DEFAULT_CAPACITY << 1) return;																	// 不至于收缩到DEFAULT_CAPACITY 以下
	if(_size << 2 > _capacity)	return;																				// 以25%为界
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];																					// 容量减半
	for(int i = 0; i < _size; i++) _elem[i] = oldElem[i];															// 复制原向量的内容
	delete []oldElem;
}
template<typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const{															// 无序容量的查找操作
	while((lo < hi--) && (e != _elem[hi]));																			// 从后向前，顺序查找
	return hi;
}
template<typename T>																								// 将e作为r元素插入
Rank Vector<T>::insert(Rank r, T const& e){
	expand();																										// 若有必要则扩容
	for(int i = _size; i>r; i--) _elem[i] = _elem[i-1];																// 自后向前,后继元素顺次向后移动一个单元
	_elem[r] = e; _size++;																							// 添加新元素并且容量增加
	return r;																										// 返回秩 
}
template<typename T> 
int Vector<T>::remove(Rank lo, Rank hi){																			// 删除区间[lo, hi）
	if(lo == hi) return 0;																							// 出于效率, 单独处理退化情况, 
	while(hi < _size) _elem[lo++] = _elem[hi++];																	// [hi, _size)顺次前移hi-lo个单元
	_size = lo;
	shrink();
	return hi - lo;
}
template<typename T>
T Vector<T>::remove(Rank r){
	T e = _elem[r];
	remove(r, r+1);
	return e;
}


template<typename T>
void Vector<T>::traverse(void (*visit) (T&))																		// 使用的函数指针机制
{ for(int i = 0; i < _size; i++) visit(_elem[i]); }																	// 遍历向量


template<typename T> 
template<typename VST>
void Vector<T>::traverse(VST& visit)																				// 借助函数对象机制
{ for(int i = 0; i < _size; i++) visit(_elem[i]); }

template<typename T> struct Increase
{virtual void operator()(T& e) {e++;} };

template<typename T>
void increase(Vector<T> &V){
	V.traverse(Increase<T>());
}
