/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:01:42 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:01:52 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():type("Animal")
{
	std::cout << "[Animal][Default constructor] called" << std::endl;
}

Animal::Animal(std::string type):type(type)
{
	std::cout << "[Animal][Constructor] called" << std::endl;
}

Animal::Animal(Animal const & obj)
{
	std::cout << "[Animal][Copy constructor] called" << std::endl;
	*this = obj;
}

Animal::~Animal()
{
	std::cout << "[Animal][Default destructor] called" << std::endl;
}

Animal & Animal::operator=(Animal const & obj)
{
	std::cout << "[Animal][Assignation operator] called" << std::endl;
	this->type = obj.type;
	return *this;
}

std::string const & Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " : " <<  "NO SOUND" << std::endl;
}
