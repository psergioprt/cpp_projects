/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:42:55 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/22 12:10:41 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _value(0){}
BitcoinExchange::BitcoinExchange(const int value) : _value(value){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _value(other._value){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_value = other._value;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

int BitcoinExchange::output() const
{
	return _value;
}

