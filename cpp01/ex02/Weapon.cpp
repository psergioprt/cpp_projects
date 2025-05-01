#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon object named \"" << this->_type << "\" has been created!" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon object named \"" << this->_type << "\" has been destroyed" << std::endl;
}

const	std::string&	Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(const std::string& type)
{
	this->_type = type;
}
