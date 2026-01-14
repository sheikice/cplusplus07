#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void showArray(const T& val)
{
    std::cout << val << '\n';
}

template <typename T>
void	reset(T& val)
{
	val = 0;
}

void	showIntArray(int val)
{
	std::cout << val << '\n';
}

int main(void)
{
	const size_t size = 5;
	std::string array[size] = {"first", "second", "third", "fourth", "fifth"};
	int tab[size] = {4, 3, 2, 1, 0};

	std::cout << "\n[TEST 1: show string array]\n";
	iter(array, size, showArray<std::string>);

	std::cout << "\n[TEST 2: show int array before and after reset to 0]\n";
	std::cout << "Before:\n";
	iter(tab, size, showArray<int>);
	iter(tab, size, reset<int>);
	std::cout << "After:\n";
	iter(tab, size, showIntArray);
	std::cout << "\n";

	return 0;
}
