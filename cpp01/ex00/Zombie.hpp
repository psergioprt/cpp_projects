/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:45:27 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 09:07:16 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name); //Constructor
		~Zombie();//Destructor
	
		//getters
		std::string	get_name(void) const;
		//setters
		void	set_name(const std::string &str);

		void	announce(void) const;

};
Zombie* newZombie (std::string name);
void	randomChump(std::string);

#endif
