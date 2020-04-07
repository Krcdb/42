#include "Brain.hpp"

Brain::Brain():
	neuronnes(1)
{
}

Brain::~Brain()
{
}

int
Brain::getNeuronnes()
{
	return (this->neuronnes);
}

std::string
Brain::identifier() const
{
	intptr_t adr = (intptr_t)this;
	
	std::stringstream ss;
	ss << "0x" << std::uppercase << std::hex << adr;
	return (ss.str());
}
