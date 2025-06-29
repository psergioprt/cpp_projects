/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:06:20 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 21:39:41 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	protected:
		std::string _ideas[100];
	public:
		Brain( void );
		Brain( const Brain& other);
		Brain &operator=( const Brain& other);
		~Brain();

		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};
#endif
