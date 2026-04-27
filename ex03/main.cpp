#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon club("crude spiked club");

	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();

	club.setType("some other type of club");
	jim.attack();
}