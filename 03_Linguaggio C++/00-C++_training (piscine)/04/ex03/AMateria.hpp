/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:06:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/08 09:27:22 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria & obj);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & obj);

		std::string const & getType() const;
		virtual AMateria * clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
