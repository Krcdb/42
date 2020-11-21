/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:55:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:43:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter ;

class AMateria
{
    private:
        AMateria();
        unsigned int _xp;
        std::string _type;

    public:
        AMateria(std::string const & type);
        AMateria(const AMateria &other);
        
        virtual ~AMateria();

        AMateria& operator=(const AMateria &other);

        const std::string & getType() const;
        unsigned int getXP() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif