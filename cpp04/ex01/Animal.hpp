/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:56 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 21:33:30 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal( void );
		Animal( const Animal &other);
		Animal& operator=(const Animal &other);

		virtual ~Animal( void );
		std::string getType() const;
		virtual void	makeSound() const;
};
#endif
