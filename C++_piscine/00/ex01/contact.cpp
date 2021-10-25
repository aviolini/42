/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:47:57 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/17 09:40:49 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

std::string fields_arr[N_FIELDS] =
{
	"first_name",
	"last_name",
	"nickname",
	"phone_number",
	"darkest_secret"
};

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void	Contact::get_info(int i)
{
	int	c = 0;
	
	std::cout << "Enter your contact information (no spaces allowed)" << std::endl;
	while (c < N_FIELDS)
	{
		this->index = i;
		std::cout << fields_arr[c] << " :\t";
		if (fields_arr[c].size() + 2 < SIZE_OF_TAB)
			std::cout << "\t";
		std::cin >> this->info_arr[c];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		c++;
	}
}

void	Contact::print_header()
{
	int	i = 0;
	
	std::cout << std::setw(CHARS_WIDE) << "index" << "|";
	while(i < 3)
		std::cout << std::setw(CHARS_WIDE) << fields_arr[i++] << "|";
	std::cout << std::endl;
}

void	Contact::print_preview()
{
	int i = 0;

	std::cout << std::setw(CHARS_WIDE) << this->index << "|";
	while (i < 3)
	{
		std::cout << std::setw(CHARS_WIDE);
		if (info_arr[i].size() <= CHARS_WIDE)
			std::cout << info_arr[i];
		else 
			std::cout << info_arr[i].substr(0, 9) + ".";
		std::cout << "|";
		i++;
	}
	std::cout << std::endl;
}

void	Contact::print()
{
	int i = 0;

	while (i < N_FIELDS)
	{
		std::cout << fields_arr[i] << " :\t";
		if (fields_arr[i].size() + 2 < SIZE_OF_TAB)
			std::cout << "\t";
		std::cout << this->info_arr[i] << std::endl;
		i++;
	}
}
