/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:26:46 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/09 09:15:36 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(std::string const type)
{
	this->type = type;
}

Ice::~Ice()
{}

Ice::Ice(Ice const & obj)
{
	*this = obj;
}

Ice * Ice::clone() const
{
	Ice *ret = new Ice(*this);
	return ret;
}

void Ice::use(ICharacter & target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
