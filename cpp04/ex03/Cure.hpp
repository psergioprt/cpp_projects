/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:29:45 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 12:10:38 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& other);
		Cure &operator=(const Cure& other);
		
		AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
