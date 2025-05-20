/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:51:29 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 09:38:08 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		~Brain();
		
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);

		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};
#endif
