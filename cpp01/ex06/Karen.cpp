/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:20:17 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/06 15:50:48 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
	std::cout << "starting karen!" << std::endl;
}

Karen::~Karen()
{
	std::cout << "exiting karen!" << std::endl;
}

void	Karen::debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain( std::string level )
{
	typedef void	(Karen::*KarenFunction)();

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	KarenFunction functions[] =
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};
	int	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
		i++;
	}
}
