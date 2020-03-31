#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	private:
		int					index;
		static std::string	fields_name[11];
		std::string			information[11];
		enum Field {
				FirstName = 0,
				LastName,
				Nickname,
				Login,
				Address,
				Email,
				Phone,
				Birthday,
				FavoriteMeal,
				UnderwearColor,
				Secret};

	public:
		Contact();
		virtual ~Contact();

		bool	set_information(int index);
		void	display_search();
		void	display_contact();
};

#endif
