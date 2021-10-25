/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:48:25 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/15 15:51:22 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main()
{
	Data * mydata = new Data;
	
	mydata->index = 0;
	mydata->name = "NAME";
	mydata->surname = "SURNAME";
	mydata->email = "NAME@SURNAME.COM";
	mydata->mobile = "000000000000";

	std::cout << std::endl << "PRINT STRUCT:";
	std::cout << "\t\t" << mydata->index << std::endl;
	std::cout << "\t\t\t" << mydata->name << std::endl;
	std::cout << "\t\t\t" << mydata->surname << std::endl;
	std::cout << "\t\t\t" << mydata->email << std::endl;
	std::cout << "\t\t\t" << mydata->mobile << std::endl;
	std::cout << std::endl;

	std::cout << "ORIGINAL PTR:\t\t" << mydata << std::endl;
	std::cout << std::endl;
	uintptr_t ser = serialize(mydata);
	Data * deser = deserialize(ser);
	std::cout << "SERIALIZE:\t\t" << ser << std::endl;
	std::cout << "DESERIALIZE:\t\t" << deser << std::endl;
	
	std::cout << std::endl;
	std::cout << "PRINT STRUCT:";
	std::cout << "\t\t" << deser->index << std::endl;
	std::cout << "\t\t\t" << deser->name << std::endl;
	std::cout << "\t\t\t" << deser->surname << std::endl;
	std::cout << "\t\t\t" << deser->email << std::endl;
	std::cout << "\t\t\t" << deser->mobile << std::endl;
	
	return 0;
}

uintptr_t serialize (Data* ptr)
{
	uintptr_t ret;
	ret = (reinterpret_cast<uintptr_t>(ptr));
	return 	ret;
}

Data* deserialize(uintptr_t raw)
{
	Data * ret;
	ret = reinterpret_cast<Data *>(raw);
	return ret;
}