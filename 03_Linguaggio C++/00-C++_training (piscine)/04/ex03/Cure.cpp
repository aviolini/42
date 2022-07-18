/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cureure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:26:46 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/08 09:17:20 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(std::string const type)
{
	this->type = type;
}

Cure::~Cure()
{}

Cure::Cure(Cure const & obj)
{
	*this = obj;
}

Cure * Cure::clone() const
{
	Cure *ret = new Cure(*this);
	return ret;
}

void Cure::use(ICharacter & target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *" << std::endl;
}
