#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class	Sed
{
	private:
		std::ofstream	ofs;
		std::ifstream	ifs;
	public:
		Sed();
		int		openFile(std::string filename);
		void	replace(std::string s1, std::string s2);
		void	closeFile();
		~Sed();
};

#endif