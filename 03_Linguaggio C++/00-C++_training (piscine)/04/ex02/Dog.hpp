/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:03:23 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/04 00:39:26 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog const &obj);
		virtual ~Dog();
		Dog & operator=(Dog const &obj);
		
		void makeSound() const;
		Brain & getBrain() const;
	private:
		Brain *brain;
};
