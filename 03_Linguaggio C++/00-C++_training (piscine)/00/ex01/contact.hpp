/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:51:49 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/17 09:40:01 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# define N_FIELDS 5
# define SIZE_OF_TAB 16
# define CHARS_WIDE 10

class Contact
{
	public:

	Contact(void);
	~Contact(void);

	void get_info(int i);
	void print_header();
	void print_preview();
	void print();
	
	private:

	int index;
	std::string info_arr[N_FIELDS];
};

#endif
