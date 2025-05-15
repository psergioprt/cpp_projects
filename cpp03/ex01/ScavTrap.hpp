/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:11:03 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/15 14:48:44 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap( void );
		
		ScavTrap( const ScavTrap& other );
		ScavTrap& operator=( const ScavTrap& other );

		virtual void	attack(const std::string& target);
		void	guardGate( void );
};
#endif
