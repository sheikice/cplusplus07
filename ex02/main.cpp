#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	// MY TESTS
	{
		Array<char> tab(10);
		unsigned int size = tab.size();

		for (unsigned int i = 0; i < size; i++)
			tab[i] = 'a' + i;

		Array<char> dup(tab);
		Array<char> *ptr = new Array<char>(dup);

		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << "tab[" << i << "] = " << tab[i] << ", ";
			std::cout << "dup[" << i << "] = " << dup[i] << ", ";
			std::cout << "ptr[" << i << "] = " << (*ptr)[i] << "\n\n";
		}

		delete ptr;
		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << "tab[" << i << "] = " << tab[i] << ", ";
			std::cout << "dup[" << i << "] = " << dup[i] << "\n\n";
		}

	}
    return 0;
}
