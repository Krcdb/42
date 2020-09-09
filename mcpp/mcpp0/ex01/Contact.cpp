#include "Contact.hpp"

std::string Contact::fields_name[11] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Login",
	"Address",
	"E-mail",
	"Phone",
	"Birthday",
	"Favorite Meal",
	"Underwear Color",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = FirstName; i <= Secret; i++)
		this->information[i] = std::string();
}

Contact::~Contact()
{
}

bool	Contact::set_information(int index)
{
	this->index = index;

	std::cout << "# Creating contact number " << this->index << std::endl;
	for (int i = FirstName; i <= Secret; i++)
	{
		std::cout << "# Enter the " << this->fields_name[i] << " :\n";
		std::getline(std::cin, information[i]);
	}
	if (!this->information[FirstName].length() && !this->information[LastName].length() &&
		!this->information[Nickname].length())
	{
		std::cout << "# You must fill one of this field : First Name, Last Name, Nickname\n";
		std::cout << "# Contact not added\n";
		for (int j = FirstName; j <= Secret; j++)
			this->information[j] = std::string();
		return (false);	
	}
	std::cout << "# Contact succesfully added !\n";
	return (true);
}

void	Contact::display_search()
{
	std::cout << "|" << std::setw(10) << this->index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		if (this->information[i].length() > 10)
			std::cout << "|" << this->information[i].substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->information[i];
	}
	std::cout << "|" << std::endl;
}

void	Contact::display_contact()
{
	std::cout << "# Contact number " << this->index << "\n\n";
	for (int i = FirstName; i <= Secret; i++)
	{
		std::cout << this->fields_name[i] << " : ";
		if (!this->information[i].length())
			std::cout << "*Empty*\n";
		else
			std::cout << this->information[i] << "\n";
	}
	std::cout << "\n";
}
