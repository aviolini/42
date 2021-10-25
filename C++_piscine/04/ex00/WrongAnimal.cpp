/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:04:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:04:16 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("WrongAnimal")
{
	std::cout << "[WrongAnimal][Default constructor] called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):type(type)
{
	std::cout << "[WrongAnimal][Constructor] called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & obj)
{
	std::cout << "[WrongAnimal][Copy constructor] called" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal][Default destructor] called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & obj)
{
	std::cout << "[WrongAnimal][Assignation operator] called" << std::endl;
	this->type = obj.type;
	return *this;
}

std::string const & WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " : " <<  "NO SOUND" << std::endl;
}
