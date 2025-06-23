/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:56:27 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 07:31:38 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string.h>

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap( std::string name);
		~FragTrap( void );
		FragTrap( const FragTrap& other);
		FragTrap& operator=( const FragTrap& other);
		
		void	highFivesGuys( void );
};

#endif
