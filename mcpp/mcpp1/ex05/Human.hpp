#ifndef _HUMAN_HPP_
# define _HUMAN_HPP_

# include <string>
# include "Brain.hpp"

class		Human
{
	private:
		const Brain brain;

	public:
		Human();
		virtual ~Human();

		std::string		identifier() const;
		const Brain		&getBrain() const;
};

#endif
