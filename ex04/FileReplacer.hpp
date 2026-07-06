#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <fstream>
# include <iostream>
# include <string>

class FileReplacer
{
  private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	std::string replaceAll(const std::string &content) const;
	bool readFile(std::string &content) const;
	bool writeFile(const std::string &content) const;

  public:
	FileReplacer(const std::string &filename, const std::string &s1,
		const std::string &s2);
	bool run(void) const;
};

#endif
