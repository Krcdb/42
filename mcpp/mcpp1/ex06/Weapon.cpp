#include "Weapon.hpp"

Weapon::Weapon():
	m_type(std::string())
{
}


Weapon::Weapon(std::string type):
	m_type(type)
{
}

Weapon::~Weapon()
{
}

std::string
Weapon::getType()
{
	return(this->m_type);
}

void
Weapon::setType(std::string new_type)
{
	this->m_type = new_type;
}
