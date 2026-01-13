#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;
	
	public:
		Array(void);
		~Array(void);
		Array(unsigned int);
		Array(const Array&);
		Array& operator=(const Array&);
		T& operator[](unsigned int);
		const T& operator[](unsigned int) const;
		unsigned int size(void) const;

	class OutOfBoundsException: public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
};

#endif
