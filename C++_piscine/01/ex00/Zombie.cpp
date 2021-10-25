/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:09:49 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/18 17:15:51 by arrigo           ###   ########.fr       */
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
