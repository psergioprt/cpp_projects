/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:54:02 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 21:31:19 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
	public:
		HumanB(const std::string& name);
		~HumanB();
		
		//setter
		void setWeapon(Weapon& weapon);

		void attack() const;
};
#endif
