#include "Zombie.hpp"

Zombie::Zombie():
	m_name(std::string()), m_type(std::string())
{
}

Zombie::Zombie(std::string name, std::string type):
	m_name(name), m_type(type)
{
}

Zombie::~Zombie()
{
	std::cout << this->m_name << " (" << this->m_type << ") : ";
	std::cout << "killed\n";
}

void	
Zombie::announce()
{
	std::cout << this->m_name << " (" << this->m_type << ") : ";
	std::cout << " Braaaaaiiiiiiiiiinnnnnnnnssss.....\n";
}
