/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:27:54 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 16:09:06 by pauldos-         ###   ########.fr       */
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

	std::cout << "\n[Origina Data]" << std::endl;
	std::cout << "Original address: " << &data << std::endl;
	std::cout << "Original id: " << data.id << std::endl;
	std::cout << "Original name: " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\n[Serialization]" << std::endl;
	std::cout << "Serialized integer (raw address): " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "\n[Deserialization]" << std::endl;
	std::cout << "Deserialized Pointer: " << deserialized << std::endl;
	std::cout << "Deserialized id: " << deserialized->id << std::endl;
	std::cout << "Deserialized name: " << deserialized->name << std::endl;

	std::cout << "\n[Validate Data]" << std::endl;
	if (deserialized == &data)
		std::cout << "SUCCESS: Deserialized pointer matches original!" << std::endl;
	else
		std::cout << "ERROR: Something is wrong!" << std::endl;

	std::cout << "\n[Update deserialized values]" << std::endl;
	deserialized->id = 24;
	deserialized->name = "Deserialization update name";
	std::cout << "Original ID: " << data.id << std::endl;
	std::cout << "Updated ID: " << deserialized->id << std::endl;
	std::cout << "Original Name: " << data.name << std::endl;
	std::cout << "Updated Name: " << deserialized->name << std::endl;
	return 0;
}
