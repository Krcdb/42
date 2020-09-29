/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:17:31 by memartin          #+#    #+#             */
/*   Updated: 2020/09/29 17:45:38 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(){
	m_name = "";
};

Human::Human(std::string name):
	m_name(name){
}
Human::~Human(){
};

void
Human::meleeAttack(std::string const & target){
	if (this->m_name.size() == 0)
		m_name = "Bob";
	std::cout << this->m_name << " gently attack " << target << " !\n";
}

void
Human::rangedAttack(std::string const & target){
	if (this->m_name.size() == 0)
		m_name = "Bob";
	std::cout << this->m_name << " throw a rock at " << target << " !\n";
}

void
Human::intimidatingShout(std::string const & target){
	if (this->m_name.size() == 0)
		m_name = "Bob";
	std::cout << this->m_name << " shout at " << target << " but he's deaf !\n";
}

void
Human::action(std::string const & action_name, std::string const & target){
	void (Human::*fptr[3])(std::string const & target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	const std::string action[] = {
		"melee",
		"range",
		"shout"
	};

	for (int i = 0; i < 3; i++){
		if (action[i] == action_name)
			(this->*fptr[i])(target);
	}
}
