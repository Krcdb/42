/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:24:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:36:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

# include "IMateriaSource.hpp"
# include "Character.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_inventory[MAX_INVENTORY];
		void initInventory();

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);

		virtual ~MateriaSource();

		MateriaSource& operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const &type);
};

#endif