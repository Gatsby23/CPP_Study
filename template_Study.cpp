/*
 * 5.4.1 Type Trait 目的
 * 这里是对std::is_pointer学习, std::is_pointer定义于<type_traits>,用来检查T是否是个pointer type。
 * 
#include <iostream>
#include <type_traits>


template<typename T>
void foo(const T &val){
	if(std::is_pointer<T>::value)
		std::cout << "foo() called for a pointer" << std::endl;
	else
		std::cout << "foo() called for a value" << std::endl;
}


	
 *	这里看一个错误的使用范例，原因在于,is_pointer<T>::value后面产生的类型是什么？后面代码会扩展成什么？
template<typename T>
void foo_wrong(const T& val){
	std::cout << (std::is_pointer<T>::value ? *val : val) << std::endl;
}


//foo() implementation for pointer types
template <typename T>
void foo_impl(const T &val, std::true_type){
	std::cout << "foo() called for pointer to " << *val << std::endl;
}

//foo() implementation for non-pointer types
template <typename T>
void foo_impl(const T& val, std::false_type){
	std::cout << "foo() called for value to " << val << std::endl;
}

template<typename T>
void foo(const T& val){
	foo_impl(val, std::is_pointer<T>());
}

int main()
{
	int num1 = 3;
	int *p_num = &num1;
	foo(p_num);
}
*
* 这里我们需要注意的是: type trait的优点在于它们是泛型代码的基石, 如我们对下面类型的修改
*
* void foo(short);				// provide integral version
* void foo(unsigned short);
* void foo(int);
*...
*
* void foo(float);				// provide floating-point version
* void foo(double);
* void foo(long double);
*/

/*
template<typename T>
void foo_impl(T val, true_type);		//provide integral version

template<typename T>
void foo_impl(T val, false_type);

template <typename T>
void foo(T val){
	foo_impl(val, std::is_integral<T>());
}*/

/*
 * Type trait 的另一个运用实例是,处理两个或多个类型中的共通类型, 如下代码所示：
 * */

/*
template<typename T1, typename T2>
typename std::common_type<T1, T2>::type min(const T1 &x, const T2 &y);


 * 如何将这种common_type返回出来的?这个操作付根据两个操作数的类型产生一个结果类型
 * 我们通过源码观察:
 * 
template <typename T1, typename T2>
struct common_type<T1, T2>{
	typedef decltype(true ? declval<T1>() : declval<T2>()) type;
}
*/

// 5.4.2　细究　Type Trait

/*
namespace std{
	template<typename T, T val>
	struct integral_constant{
		static constexpr T value = val;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		constexpr operator value_type(){ return value; }
	};
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
}*/

/*
 * 5.5 辅助函数
 * 5.5.1 挑选最小值和最大值
 *
 */

// util/minmax1.cpp

#include <algorithm>
#include <iostream>

//function that compares two pointers by comparing the values to which they point
//bool int_ptr_less(int *a, int *b){
//	return *a < *b;
// }

int main()
{
	int x = 17;
	int y = 42;
	int z = 33;
	int *px = &x;
	int *py = &y;
	int *pz = &z;

	//call max() with special comparison function
	//int *pmx = std::max(px, py, int_ptr_less);

	//call minmax() for initializer list with special comparison function
	std::pair<int*, int*> extremes = std::minmax({px, py, pz}, [](int *a, int *b){ return *a < *b; });
	std::cout << *extremes.first << ", " << *extremes.second << std::endl;
}



