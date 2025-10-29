/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:57:47 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/29 18:28:35 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _exchangeRates;
		
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		bool dateFormatChecker(const std::string& date) const;
		bool valueChecker(const std::string& num) const;
		std::string myTrim(const std::string &s) const;


	public:
		BitcoinExchange();
		~BitcoinExchange();

		void openExchangeRateFile(std::string exchangeRateFile);
		void openFileToEvaluate(std::string fileToEvaluate);

		double getRateForDate(const std::string &date) const;
};
