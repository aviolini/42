/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:06:28 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/08 08:13:34 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::~AMateria()
{}

AMateria::AMateria(AMateria const & obj)
{
	*this = obj;
}

AMateria & AMateria::operator=(AMateria const & obj)
{
	this->type = obj.type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria->use: " << target.getName() << std::endl;
}


