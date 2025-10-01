/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:04:33 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/01 17:12:32 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
	private:
		unsigned int _size;
		T* _data;

	public:
		Array() : _size(0), _data(NULL){ std::cout << "Default Constructor called\n"; }
		Array(unsigned int n) : _size(n), _data(new T[n]()){ std::cout << "Constructor called with size 5\n"; }
		~Array() { std::cout << "Destructor called\n"; delete [] _data; }
		Array(const Array &other) : _size(other._size), _data(NULL)
		{
			std::cout << "Copy constructor called with size: " << _size << std::endl;
			if (_size > 0)
			{
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					this->_data[i] = other._data[i];
			}
		}
		Array& operator=(const Array& other)
		{
			std::cout << "Assignement operator called with size " << _size << std::endl; 
			if (this != &other)
			{
				delete [] _data;
				_size = other._size;
				_data = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
				{
					_data[i] = other._data[i];
				}
			}
			return *this;
		}
		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
		}

		unsigned int size() const;
};

#endif
