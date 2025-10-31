/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:09:09 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/31 10:09:16 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	BitcoinExchange c;
	std::string fileToEvaluate = argv[1];
	std::string exchangeRateFile = "data.csv";
	c.openExchangeRateFile(exchangeRateFile);
	c.openFileToEvaluate(fileToEvaluate);
	return 0;
}
