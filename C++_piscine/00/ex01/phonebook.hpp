/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:51:49 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/14 16:43:28 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# define MAX_CONTACTS 8

class Phonebook
{
	private:
	Contact contact_arr[MAX_CONTACTS];
	int total_contacts;

	public:
	
	Phonebook();
	~Phonebook();
	
	void add(int i);
	void search(void);
	
};

#endif
