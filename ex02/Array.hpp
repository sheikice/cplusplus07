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

template<typename T>
Array<T>::Array(): _size(0)
{
	_data = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& other): _size(other._size)
{
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
	
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what(void) const throw()
{
	return "Index is out of bounds";
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

#endif
