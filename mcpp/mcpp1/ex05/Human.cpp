#include <iostream>
#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

const Brain
&Human::getBrain() const
{
	return(this->brain);
}

std::string
Human::identifier() const
{
	return(this->brain.identifier());
}
