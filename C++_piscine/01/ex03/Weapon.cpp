/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:00:12 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/19 14:51:16 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type): type(type)
{}

Weapon::~Weapon()
{}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}

const std::string Weapon::getType() const
{
	return (this->type);
}
