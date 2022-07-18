/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:09:49 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/25 17:16:31 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name;
	std::cout << "\tDESTRUCTED" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name;
		std::cout << "\tCREATED" << std::endl;
}

void Zombie::setname(std::string const name)
{
	this->name = name;
}
