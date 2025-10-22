/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:29:55 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/22 12:29:03 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



class BitcoinExchange
{
	private:
		int _value;

	public:
		BitcoinExchange();
		BitcoinExchange(const int value);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		int output() const;
};


