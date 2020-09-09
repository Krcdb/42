#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

# include <string>
# include <sstream>
# include <iomanip>

class		Brain
{
	private:
		int	neuronnes;

	public:
		Brain();
		virtual ~Brain();

		int				getNeuronnes();
		std::string		identifier() const;
};

#endif
