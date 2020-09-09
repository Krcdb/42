#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	m_name(name), m_weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void
HumanB::attack()
{
	std::cout << this->m_name << " attacks with his " << this->m_weapon->getType() << std::endl;
}

void
HumanB::setWeapon(Weapon &weapon)
{
	this->m_weapon = &weapon;
}
