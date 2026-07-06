#include "FileReplacer.hpp"

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (std::string(av[2]).empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}
	FileReplacer replacer(av[1], av[2], av[3]);
	if (!replacer.run())
		return (1);
	return (0);
}
