/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:27:54 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 12:33:44 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Test object";

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized pointer: " << raw << std::endl;
}
