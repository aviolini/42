/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:43:36 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/04 00:20:17 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain][Default constructor] called" << std::endl;
	std::string ideas[5] = {"eat" , "walk" , "run", "sleep", "drink"};
	this->ideas = new std::string[SIZE_ARR];
	for (int i = 0; i < SIZE_ARR; i++)
		this->ideas[i] = ideas[i % 5];
}

Brain::Brain(Brain const & obj)
{
	std::cout << "[Brain][Copy constructor] called" << std::endl;
	this->ideas = new std::string[SIZE_ARR];
	for (int i = 0; i < SIZE_ARR; i++)
		this->ideas[i] = obj.ideas[i];
}

Brain::~Brain()
{
	delete[] this->ideas;
	std::cout << "[Brain][Destructor] called" << std::endl;
}

Brain & Brain::operator=(Brain const & obj)
{
	std::cout << "[Brain][Assignation operator] called" << std::endl;
	for (int i = 0; i < SIZE_ARR; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

std::string const & Brain::getIdea(int i) const
{
	return this->ideas[i];
}

void Brain::setIdea(int i, const std::string new_idea)
{
	this->ideas[i] = new_idea;
}
