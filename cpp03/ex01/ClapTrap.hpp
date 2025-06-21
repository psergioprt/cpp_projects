/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:55:16 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/21 13:23:26 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	//	unsigned int	_maxHitPoints; //althought not required, I added this to create a top boundary
	public:
		ClapTrap();
		ClapTrap( std::string name);
		~ClapTrap( void );

		ClapTrap (const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
#endif
