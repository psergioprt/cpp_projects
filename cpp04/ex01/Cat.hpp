/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:17 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 21:42:23 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat( void );
		Cat( const Cat &other);
		Cat &operator=( const Cat &other);
		virtual ~Cat( void );
		
		virtual void makeSound() const;

		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};
#endif
