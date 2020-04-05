#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent():
	m_type(std::string())
{
}

ZombieEvent::~ZombieEvent()
{
}

void
ZombieEvent::setZombieType(std::string type)
{
	this->m_type = type;
}

std::string
ZombieEvent::randomName(std::string::size_type length)
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

Zombie
*ZombieEvent::newZombie()
{
	return(new Zombie(this->m_type, this->randomName(7)));
}

Zombie
*ZombieEvent::randomChump()
{
	Zombie *zombie;

	if (this->m_type == "")
		this->setZombieType("Looser");
	zombie = this->newZombie();
	return (zombie);
}
