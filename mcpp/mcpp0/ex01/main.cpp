#include "Repertory.hpp"

int			main(void)
{
	Repertory		repertory;
	bool			run = true;
	std::string		input;

	std::cout << "# New repertory created\n";
	std::cout << "# Enter cmd : [ADD, SEARCH, EXIT]:\n";
	while (run)
	{
		std::cout << ">";
		std::getline(std::cin, input);
		if (input == "ADD")
			repertory.add_contact();
		else if (input == "SEARCH")
			repertory.search_contact();
		else if (input == "EXIT")
			run = false;
		else
			std::cout << "# This command is not valid. [ADD, SEARCH, EXIT]\n";
	}
	std::cout << "# Closing the repertory\n";
	return (0);
}
