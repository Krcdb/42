#ifndef _PONY_HPP_
# define _PONY_HPP_

# include <iostream>
# include <string>

class Pony
{
	private:
		std::string const	name;
		std::string const	location;

	public:
		Pony(std::string const name, std::string const location);
		virtual ~Pony();
		
		void	talk_bb();
};

#endif
