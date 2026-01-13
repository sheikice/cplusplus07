#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(const T* arr, const size_t len, void (*function)(const T&))
{
	if (!arr)
	{
		std::cout << "Null ptr passed as parameter\n";
		return ;
	}
	for (size_t i = 0; i < len; i++)
		function(arr[i]);
}

template <typename T>
void iter(T* arr, const size_t len, void (*function)(T&))
{
	if (!arr || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
		function(arr[i]);
}

#endif
