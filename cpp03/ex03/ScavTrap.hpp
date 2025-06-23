/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:55:35 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 11:23:16 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap( void );
		
		ScavTrap( const ScavTrap& other );
		ScavTrap& operator=( const ScavTrap& other );

		void	attack(const std::string& target);
		void	guardGate( void );

	protected:
		static int getDefaultEnergyPoints();
};
#endif
