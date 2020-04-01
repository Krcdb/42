#include "Pony.hpp"

Pony::Pony(std::string const m_name, std::string const m_location): 
	name(m_name), location(m_location)
{
	std::cout << "A little pony named " << this->name << " is born on the ";
	std::cout << this->location << std::endl;
}

Pony::~Pony()
{
	std::cout << this->name << " is dead... RIP in peace little boy\n";
}

void		Pony::talk_bb()
{
	std::cout << this->name << " try talk. But he can't, he's a pony :/\n";
	std::cout << "Everyone on the " << this->location << " are laughs at him !\n";
}
