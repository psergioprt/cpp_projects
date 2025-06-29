/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:56 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 01:20:01 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		AAnimal( const AAnimal &other);
		AAnimal& operator=(const AAnimal &other);

		virtual ~AAnimal( void );
		std::string getType() const;
		virtual void	makeSound() const = 0;
};
#endif
