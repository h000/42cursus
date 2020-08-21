#include "Sed.hpp"

int	main(int argc, char **argv)
{
	Sed	sed;

	if (argc != 4)
	{
		std::cout << "Error: Invalid Number Of Arguments" << std::endl;
		return (0);
	}
	if (sed.openFile(argv[1]))
	{
		sed.replace(argv[2], argv[3]);
		sed.closeFile();
	}
	else
		std::cout << "Error: Cannot Open File" << std::endl;
}