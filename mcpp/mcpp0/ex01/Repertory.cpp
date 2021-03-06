#include "Repertory.hpp"

Repertory::Repertory()
{
	this->amount = 0;
}

Repertory::~Repertory()
{
}

void	Repertory::add_contact()
{
	if (this->amount == 8)
		std::cout << "# The repertory is full\n";
	else
	{
		if (this->contact[this->amount].set_information(this->amount + 1))
			this->amount++;
	}
}

void	Repertory::display_search_header()
{
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|     Index|Fisrt Name| Last Name|  Nickname|\n";
	std::cout << "|-------------------------------------------|\n";
	for (int i = 0; i < this->amount; i++)
	{
		this->contact[i].display_search();
		if (i != this->amount - 1)
			std::cout << "|--      --|--      --|--      --|--      --|\n";
	}
	std::cout << "|-------------------------------------------|\n\n";
}

void	Repertory::search_contact()
{
	int				index;

	if (!this->amount)
		std::cout << "# The repertory is empty !\n";
	else
	{
		this->display_search_header();
		std::cout << "# Enter the index associate to the contact you want to display\n";
		std::cout << "# 0 to exit\n>";
		while (!(std::cin >> index) || (index < 0 || index > this->amount))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "# Invalid Index\n>";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index == 0)
			std::cout << "# Exit search\n";
		else
			this->contact[index - 1].display_contact();
	}
}
