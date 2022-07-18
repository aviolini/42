/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:52:23 by arrigo            #+#    #+#             */
/*   Updated: 2021/09/04 00:46:49 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "[Cat][Default constructor] called" << std::endl;
	this->brain = new Brain;
}

Cat::Cat(Cat const & obj):Animal(obj)
{
	std::cout << "[Cat][Copy constructor] called" << std::endl;
	this->brain = new Brain(obj.getBrain());
}

Cat::~Cat()
{
	std::cout << "[Cat][Default destructor] called" << std::endl;
	delete this->brain;
}

Cat & Cat::operator=(Cat const & obj)
{
	std::cout << "[Cat][Assignation operator] called" << std::endl;
	this->type = obj.type;
	if (!this->brain)
		this->brain = new Brain;
	*this->brain = *obj.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << this->type << " : " << "MIAO" << std::endl;
}

Brain & Cat::getBrain() const
{
	return *this->brain;
}
