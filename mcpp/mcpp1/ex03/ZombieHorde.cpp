#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde()
{
}

ZombieHorde::ZombieHorde(int nb):
	m_nb(nb)
{
	this->horde = new Zombie[this->m_nb];
	for (int i = 0; i < this->m_nb; i++)
		horde[i].setName();
}

ZombieHorde::~ZombieHorde()
{
	delete[] this->horde;
	std::cout << "Horde deleted\n";
}

void
ZombieHorde::announce()
{
	std::cout << "Here comes the Zombies\n";
	for (int i = 0; i < this->m_nb; i++)
		horde[i].announce();
}
