#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> a{1, 2, 3, 4};
	int total = 0;
	for_each(a.begin(), a.end(), [&](int &x){total += x; x *= 2;});
	cout << total << endl;
	for_each(a.begin(), a.end(), [](int x){cout << x << " ";});
	function<int(int)> fib = [&fib](int n){ return n <= 2 ?1 :fib(n-1) + fib(n-2);};
	cout << fib(5) << endl;
	return 0;
}
