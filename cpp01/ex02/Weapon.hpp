#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type); //constructor
		~Weapon(); //destructor
	
		//getters
		const	std::string&	getType() const;
	
		//setters
		void	setType(const std::string& type);
};

#endif
