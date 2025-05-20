/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:07:20 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 09:57:45 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog( void );
		~Dog( void );

		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		void	makeSound() const;

		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};
#endif
