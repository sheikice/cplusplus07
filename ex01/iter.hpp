#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename FUNC>
void iter(T* arr, const size_t len, FUNC func)
{
	if (!arr)
	{
		std::cout << "Null ptr passed as parameter\n";
		return ;
	}
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}
#endif
