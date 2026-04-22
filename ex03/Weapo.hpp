#ifndef WEAPON_HPP
# define WEAPOS_HPP

# include <iostream>
class Weapon
{
  private:
	std::string type;

  public:
	const std::string &getType();
	const std::string *setType();
};
#endif