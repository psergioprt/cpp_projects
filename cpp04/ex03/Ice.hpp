/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:30:36 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 12:39:17 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice &operator=(const Ice& other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
