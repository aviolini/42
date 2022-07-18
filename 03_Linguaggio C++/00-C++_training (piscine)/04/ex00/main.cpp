/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:03:39 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/03 02:03:45 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	delete meta;
	delete j;
	delete i;
	
	std::cout << "------------" << std::endl;

	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();

	std::cout << Wrongmeta->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	Wrongmeta->makeSound();
	h->makeSound();
	delete Wrongmeta;
	delete h;

	return 0;
}

