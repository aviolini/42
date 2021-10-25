/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:04:58 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:05:01 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat][Default constructor] called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & obj)
{
	std::cout << "[WrongCat][Copy constructor] called" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat][Default destructor] called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & obj)
{
	std::cout << "[WrongCat][Assignation operator] called" << std::endl;
	this->type = obj.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << this->type << " : " << "MIAO" << std::endl;
}
