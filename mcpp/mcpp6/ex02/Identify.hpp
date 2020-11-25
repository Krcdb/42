/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:58:31 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 19:16:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>

class Base{public: virtual ~Base(){};};
class A:public Base{public: virtual ~A(){};};
class B:public Base{public: virtual ~B(){};};
class C:public Base{public: virtual ~C(){};};

Base *creatClass(void);

void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif