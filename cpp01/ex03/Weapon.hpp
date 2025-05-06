/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:53:24 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/06 10:53:28 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type); //constructor
		~Weapon(); //destructor
	
		//getters
		const	std::string&	getType() const;
	
		//setters
		void	setType(const std::string& type);
};

#endif
