/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:14:03 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 22:09:30 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& other);
		WrongAnimal &operator=( const WrongAnimal& other);
		~WrongAnimal( void );
		
		std::string getType() const;
		void makeSound() const;
};
#endif
