/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:04:33 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/01 12:40:45 by pauldos-         ###   ########.fr       */
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
		Array();
		Array(unsigned int n) : _size(n), _data(new T[n]()){}
		~Array() { delete [] _data;}
		Array(const Array& other);
		Array& operator=(const Array& other)
		{
			if (*this != &other)
				this = other;
			return *this;
		}


		unsigned int size() const;
};

#endif
