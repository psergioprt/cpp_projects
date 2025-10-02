/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:04:33 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/02 08:46:45 by pauldos-         ###   ########.fr       */
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
		Array() : _size(0), _data(NULL){}
		Array(unsigned int n) : _size(n), _data(new T[n]()){}
		~Array() { delete [] _data;}
		Array(const Array &other) : _size(other._size), _data(NULL)
		{
			if (_size > 0)
			{
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					this->_data[i] = other._data[i];
			}
		}
		Array& operator=(const Array& other)
		{
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
		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};
		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _data[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _data[index];
		}

		unsigned int size() const;
};

#endif
