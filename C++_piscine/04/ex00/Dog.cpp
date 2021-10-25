/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:52:23 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/03 01:52:29 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "[Dog][Default constructor] called" << std::endl;
}

Dog::Dog(Dog const & obj)
{
	std::cout << "[Dog][Copy constructor] called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "[Dog][Default destructor] called" << std::endl;
}

Dog & Dog::operator=(Dog const & obj)
{
	std::cout << "[Dog][Assignation operator] called" << std::endl;
	this->type = obj.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << this->type << " : " << "BAU" << std::endl;
}
