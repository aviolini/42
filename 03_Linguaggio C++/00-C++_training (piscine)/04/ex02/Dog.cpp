/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:52:23 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/08 09:49:57 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "[Dog][Default constructor] called" << std::endl;
	this->brain = new Brain;
}

Dog::Dog(Dog const & obj):Animal(obj)
{
	std::cout << "[Dog][Copy constructor] called" << std::endl;
	this->brain = new Brain(obj.getBrain());
}

Dog::~Dog()
{
	std::cout << "[Dog][Default destructor] called" << std::endl;
	delete this->brain;
}

Dog & Dog::operator=(Dog const & obj)
{
	std::cout << "[Dog][Assignation operator] called" << std::endl;
	this->type = obj.type;
	if (!this->brain)
		this->brain = new Brain;
	*this->brain = *obj.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << this->type << " : " << "BAU" << std::endl;
}

Brain & Dog::getBrain() const
{
	return *this->brain;
}
