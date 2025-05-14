/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:05:45 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/14 11:09:35 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string.h>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap( std::string name);
		~FragTrap( void );
		FragTrap( const FragTrap& other);
		FragTrap& operator=( const FragTrap& other);
		
		void	highFivesGuys( void );
};

#endif
