#include <iostream>
#include <string>

int main(void)
{
	std::string	str = std::string("HI THIS IS BRAIN");
	std::string	*str_ptr = &str;
	std::string	&str_ref = str;
	std::cout << "str: " << str << std::endl;
	std::cout << "ptr_str: " << *str_ptr << std::endl;
	std::cout << "ref_str: " << str_ref << std::endl;
	return (0);
}
