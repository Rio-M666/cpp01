#include <iostream>

int	main(int ac, char *av[])
{
	std::string filename;
	std::string s1;
	std::string s2;
	if (ac != 4)
		return (1);
	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	if (s1.empty())
		return (1);
	
}