#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	for(int a = 2; a != N; ++a)
		for(int b = 2; b != a; ++b)
			for(int c = b; c != a; ++c)
				for(int d = c; d != a; ++d)
					if(a*a*a == b*b*b + c*c*c + d*d*d)
						std::cout << "The Cube " << a << " a: " << b << " b: " << c << " c: " << d << std::endl;
	return 0;
}
