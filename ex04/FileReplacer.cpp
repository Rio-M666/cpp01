#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string &filename,
	const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2)
{
}

std::string FileReplacer::replaceAll(const std::string &content) const
{
	std::string result;
	std::size_t start;
	std::size_t pos;

	start = 0;
	pos = content.find(_s1, start);
	while (pos != std::string::npos)
	{
		result += content.substr(start, pos - start);
		result += _s2;
		start = pos + _s1.length();
		pos = content.find(_s1, start);
	}
	result += content.substr(start);
	return (result);
}

bool FileReplacer::readFile(std::string &content) const
{
	char c;
	std::ifstream input;

	input.open(_filename.c_str(), std::ios::in);
	if (!input)
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return (false);
	}
	while (input.get(c))
		content += c;
	if (input.bad())
	{
		std::cerr << "Error: failed while reading input file" << std::endl;
		input.close();
		return (false);
	}
	input.close();
	return (true);
}

bool FileReplacer::writeFile(const std::string &content) const
{
	std::string output_name;
	std::ofstream output;

	output_name = _filename + ".replace";
	output.open(output_name.c_str(), std::ios::out | std::ios::trunc);
	if (!output)
	{
		std::cerr << "Error: cannot open output file" << std::endl;
		return (false);
	}
	output << content;
	if (!output)
	{
		std::cerr << "Error: failed while writing output file" << std::endl;
		output.close();
		return (false);
	}
	output.close();
	return (true);
}

bool FileReplacer::run(void) const
{
	std::string content;

	if (!readFile(content))
		return (false);
	return (writeFile(replaceAll(content)));
}
