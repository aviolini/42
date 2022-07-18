/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:50:31 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/24 16:38:01 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{}

Karen::~Karen()
{}

void Karen::debug (void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;
}

void Karen::info (void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough!" << std::endl; 
	std::cout << "If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning (void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error (void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	enum levels {debug = 0, info, warning, error};
	void (Karen:: *complains[4])() = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = debug; i <= error ; i++)
		if (array[i].compare(level) == 0)
			(this->*complains[i])();
}
