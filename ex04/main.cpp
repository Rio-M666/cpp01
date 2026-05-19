#include <fstream>
#include <iostream>
#include <string>

static std::string replace_all(const std::string &content,
	const std::string &s1, const std::string &s2)
{
	std::string result;
	std::size_t start;
	std::size_t pos;
	start = 0;
	pos = content.find(s1, start);
	while (pos != std::string::npos)
	{
		result += content.substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
		pos = content.find(s1, start);
	}
	result += content.substr(start);
	return (result);
}

int	main(int ac, char *av[])
{
	char	c;

	std::string filename;
	std::string s1;
	std::string s2;
	std::string content;
	std::string output_name;
	std::ifstream input;
	std::ofstream output;
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}
	input.open(filename.c_str(), std::ios::in);
	if (!input)
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return (1);
	}
	while (input.get(c))
		content += c;
	if (input.bad())
	{
		std::cerr << "Error: failed while reading input file" << std::endl;
		input.close();
		return (1);
	}
	input.close();
	output_name = filename + ".replace";
	output.open(output_name.c_str(), std::ios::out | std::ios::trunc);
	if (!output)
	{
		std::cerr << "Error: cannot open output file" << std::endl;
		return (1);
	}
	output << replace_all(content, s1, s2);
	if (!output)
	{
		std::cerr << "Error: failed while writing output file" << std::endl;
		output.close();
		return (1);
	}
	output.close();
	return (0);
}
