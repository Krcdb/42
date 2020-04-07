#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	
	HumanA bob("Bob", club);
	HumanB jim("Jim");
	jim.setWeapon(club);
	bob.attack();
	jim.attack();
	club.setType("some other type of club");
	bob.attack();
	jim.attack();
}
