/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:02:24 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:02:27 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "[Cat][Default constructor] called" << std::endl;
}

Cat::Cat(Cat const & obj)
{
	std::cout << "[Cat][Copy constructor] called" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "[Cat][Default destructor] called" << std::endl;
}

Cat & Cat::operator=(Cat const & obj)
{
	std::cout << "[Cat][Assignation operator] called" << std::endl;
	this->type = obj.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << this->type << " : " << "MIAO" << std::endl;
}
