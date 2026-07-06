#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did,I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years,whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	const int level_count = 4;
	std::string levels[level_count] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[level_count])() = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};

	for (int i = 0; i < level_count; i++)
	{
		if (level == levels[i])
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "No valid level." << std::endl;
}
