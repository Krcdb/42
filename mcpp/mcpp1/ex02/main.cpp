#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	Zombie      *zombie_1;
    Zombie      *zombie_2;
    ZombieEvent event;

    event.setZombieType("plop");
    zombie_1 = event.randomChump();
    zombie_1->announce();
    delete zombie_1;
    event.setZombieType("oui");
    zombie_2 = event.randomChump();
    zombie_2->announce();
    delete zombie_2;
    return (0);
}
