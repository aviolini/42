/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:02:02 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:02:06 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string name);
		Animal(Animal const & obj);
		virtual ~Animal();
		Animal & operator=(Animal const & obj);
		virtual void makeSound() const;
		std::string const & getType() const;
	protected:
		std::string type;
};

#endif
