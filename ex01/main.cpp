#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void show(const T& val)
{
    std::cout << val << '\n';
}

template <typename T>
void	reset(T& val)
{
	val = 0;
}

int main(void)
{
	const size_t size = 5;
	std::string array[size] = {"first", "second", "third", "fourth", "fifth"};
	int tab[size] = {4, 3, 2, 1, 0};

	std::cout << "[TEST 1: show string array]\n";
	iter(array, size, show);

	std::cout << "[TEST 2: show int array before and after reset to 0]\n";
	std::cout << "Before:\n";
	iter(tab, size, show);
	iter(tab, size, reset);
	std::cout << "After:\n";
	iter(tab, size, show);
	std::cout << "\n";

	return 0;
}
