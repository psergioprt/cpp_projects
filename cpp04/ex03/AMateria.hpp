/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:56:57 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 10:40:11 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter; //Forward declaration

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const &type);

		virtual ~AMateria(); //virtual destructor

		AMateria(const AMateria& other); //copy constructor
		AMateria &operator=(const AMateria& other); //copy assignement operator

		std::string const & getType() const; //return the materia type

		virtual AMateria* clone() const = 0; //pure virtual function to make AMateria abstract
		virtual void use(ICharacter& target);
};

#endif
