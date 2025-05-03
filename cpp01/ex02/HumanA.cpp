#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "Creating Human named \"" << this->_name << "\" with weapon \"" << this->_weapon.getType() << "\""<< std::endl; 
}

HumanA::~HumanA()
{
	std::cout << "Destroying Human name \"" << this->_name << "\" with weapon \"" << this->_weapon.getType() << "\"" << std::endl;
}

void	HumanA::attack() const
{
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
