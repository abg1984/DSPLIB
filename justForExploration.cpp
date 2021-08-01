
#include <iostream>
#include <vector>
#include "MeasurePerformanceCommand.h"

template <typename T>
void foo(T&& bar)
{
	auto x = std::forward<T>(bar);
}

template <typename Callable, typename T>
void func(Callable funcObj, const std::vector<T>& x)
{
	for (int i = 0; i < 5; ++i)
	{
		funcObj(x[i]);
	}
}

int main(void)
{
	std::vector<int> aVec{ 1,2,3,4,5,6,7,8,9 };

	auto printVal = [](int val) 
	{ 
		std::cout << val << " "; 
	};

	func(printVal, aVec);

	foo(aVec);
	foo(std::move(aVec));

	return EXIT_SUCCESS;
}
