/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:51:49 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/15 15:07:40 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <string>

typedef struct 	Data_s
{
	int 		index;
	std::string name;
	std::string surname;
	std::string mobile;
	std::string email;
}				Data;

uintptr_t serialize (Data* ptr);
Data* deserialize(uintptr_t raw);

#endif