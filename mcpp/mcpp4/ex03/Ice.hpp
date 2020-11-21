/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:23:49 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:52:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice(const Ice &other);
        
        virtual ~Ice();

        Ice& operator=(const Ice &other);

        virtual Ice* clone() const;
        virtual void use(ICharacter &target);
};

#endif