#include "Zombie.hpp"

Zombie::Zombie()
{
	m_name = std::string();
}

Zombie::~Zombie()
{
}

std::string
Zombie::randomName(std::string::size_type length)
{
	static std::string chrs =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		static std::mt19937 rg(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));	
		static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

	std::string s;
	while(length--)
		s += chrs[pick(rg)];
	return s;
}

void
Zombie::setName()
{
	this->m_name = this->randomName(7);
}

void
Zombie::announce()
{
	std::cout << "<" << this->m_name << "> Hello\n";
}
