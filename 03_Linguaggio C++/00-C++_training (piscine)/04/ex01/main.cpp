/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 02:03:39 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/04 00:43:40 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#define SIZE 4

int main()
{
	Animal *animal[SIZE];
	for(int c = 0; c < SIZE; c++)
	{		
		if (c % 2)
			animal[c] = new Dog();
		else
			animal[c] = new Cat();
		std::cout << "-------" << std::endl;
	}
	for(int c = 0; c < SIZE; c++)
	{
		std::cout << animal[c]->getType() << std::endl;
		animal[c]->makeSound();
	}
	std::cout << "=======" << std::endl;
	for(int c = 0; c < SIZE; c++)
	{
		std::cout << "-------" << std::endl;
		delete animal[c];
	}
	
	std::cout << "=======" << std::endl;
	std::cout << "--Creating new dog1----" << std::endl;
	Dog *dog1 = new (Dog);
	std::cout << "Type: " << dog1->getType() << std::endl;
	std::cout << "Sound: ";
	dog1->makeSound();
	std::cout << "---dog1 ideas----" << std::endl;
	for (int i=0;i<10;i++)
		std::cout << "IDEA " << i << " " << dog1->getBrain().getIdea(i) << std::endl;
	std::cout << "--dog1 changing ideas---" << std::endl;
	int c = 0;
	for(int i=9;i>=5;i--)
	{
		dog1->getBrain().setIdea(c,dog1->getBrain().getIdea(i));
		c++;
	}
	for (int i=0;i<10;i++)
		std::cout << "IDEA " << i << " " << dog1->getBrain().getIdea(i) << std::endl;
	std::cout << "--Creating new dog2----" << std::endl;
	Dog dog2(*dog1);
	std::cout << "--Creating new dog3----" << std::endl;
	Dog dog3;
	dog3 = *dog1;
	std::cout << "--Deleting dog1---" << std::endl;
	delete dog1;
	std::cout << "---dog2 ideas----" << std::endl;
	for (int i=0;i<10;i++)
		std::cout << "IDEA " << i << " " << dog2.getBrain().getIdea(i) << std::endl;
	std::cout << "---dog3 ideas----" << std::endl;
	for (int i=0;i<10;i++)
		std::cout << "IDEA " << i << " " << dog3.getBrain().getIdea(i) << std::endl;
	return 0;
}

