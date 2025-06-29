/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:36 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 01:22:46 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain* _brain;
	public:
		Dog( void );
		Dog( const Dog &other );
		Dog &operator=( const Dog &other );

		virtual ~Dog( void );
		virtual void	makeSound() const;

		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};
#endif
