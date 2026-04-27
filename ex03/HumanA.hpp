#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>
class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	HumanA(std::string name, Weapon &weapon);
	void attack(void) const;
};
#endif