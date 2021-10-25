/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:46:49 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/14 16:43:18 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->total_contacts = 0;
}

Phonebook::~Phonebook(void)
{}

void Phonebook::add(int i)
{
	this->contact_arr[i - 1].get_info(i);
	if (this->total_contacts < MAX_CONTACTS)
		this->total_contacts++;
}

void Phonebook::search()
{
	int	i = 0;

	if (!this->total_contacts)
	{
		std::cout << "No added contact" << std::endl;
		return ;
	}
	(*contact_arr).print_header();
	while (i < this->total_contacts)
	{
		this->contact_arr[i].print_preview();
		i++;
	}
	while (1)
	{
		std::cout << "Enter the contact index to expand" << std::endl;
		std::cin >> i;
		if (std::cin.eof())
			return ;
		if(std::cin.good() && i <= this->total_contacts && i > 0) 
			return this->contact_arr[i - 1].print();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}	
}
