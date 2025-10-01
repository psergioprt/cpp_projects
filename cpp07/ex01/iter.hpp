/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/01 07:44:21 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// non-const elements (modifiable)
template <typename T>
void iter(T arr[], size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

// const elements (read-only)
template <typename T>
void iter(const T arr[], size_t length, void (*f) (T const &))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

#endif
