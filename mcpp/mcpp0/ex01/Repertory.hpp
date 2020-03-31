#ifndef _REPERTORY_CPP_
# define _REPERTORY_CPP_

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"


class Repertory
{
	private:
		Contact		contact[8];
		int			amount;
	
	public:
		Repertory();
		virtual ~Repertory();

		void	add_contact();
		void	search_contact();
		void	display_search_header();
};

#endif
