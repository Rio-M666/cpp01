#include <iostream>

int	main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "STR'S ADDRESS IS " << &str << std::endl;
	std::cout << "STRINGPTR'S ADDRESS IS " << stringPTR << std::endl;
	std::cout << "STRINGREF'S ADDRESS IS " << &stringREF << std::endl;

	std::cout << "STR'S VALUE IS " << str << std::endl;
	std::cout << "STRINGPTR'S VALUE IS " << *stringPTR << std::endl;
	std::cout << "STRINGREF'S VALUE IS " << stringREF << std::endl;
}