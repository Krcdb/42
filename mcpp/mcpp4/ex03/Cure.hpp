/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:51:32 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 10:51:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        
        virtual ~Cure();

        Cure& operator=(const Cure &other);

        virtual Cure* clone() const;
        virtual void use(ICharacter &target);
};

#endif