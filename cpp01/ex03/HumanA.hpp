/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:53:43 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/06 10:53:50 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();

		void attack() const;
};

#endif
