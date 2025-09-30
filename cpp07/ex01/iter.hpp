/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/30 16:03:03 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T arr[], size_t length, void (*f) (T &))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T>
void iter(T arr[], size_t length, void (*f) (T const &))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T>
void print_element(T const& x)
{
	std::cout << x << std::endl;
}

#endif
