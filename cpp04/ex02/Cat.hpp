/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:17 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 01:21:24 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
