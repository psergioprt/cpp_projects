/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:48:59 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/25 09:49:02 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Functions.hpp"
#include "Base.hpp"

int main()
{
	Base* obj = generate();

	std::cout << "Identify with pointer: ";
	identify(obj);

	std::cout << "Identify with reference: ";
	identify(*obj);

	delete obj;


	return 0;
}
