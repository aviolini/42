/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:03:23 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/04 00:42:40 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(Cat const &obj);
		virtual ~Cat();
		Cat & operator=(Cat const &obj);
		
		void makeSound() const;
		Brain & getBrain() const;
	private:
		Brain *brain;
};
