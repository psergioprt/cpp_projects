/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:47:34 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/24 16:59:43 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Karen karen;

		karen.complain(argv[1]);
		//karen.complain("DEBUG");
		//karen.complain("INFO");
		//karen.complain("WARNING");
		//karen.complain("ERROR");
	}
	else
		std::cout << "Usage: <command> <arg>" << std::endl;
	return 0;
}
