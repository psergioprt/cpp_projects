/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:11:01 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/31 10:11:48 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: This program requires two arguments" << std::endl;
		return 0;
	}
	RPN a;
	a.splitToken(argv[1]);
	a.printToken();
	return 0;
}
