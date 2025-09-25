/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:23:09 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/25 16:45:58 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y)
{
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif
