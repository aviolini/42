/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:26:20 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/15 12:13:57 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <cfloat>

class Converter
{
	public:
		Converter(const char * & arg);
		Converter(Converter const & obj);
		~Converter();
		Converter & operator=(Converter const & obj);
		
		static void convertAll(const char *);
		static void toChar(const char * &);
		static void toInt(const char * &);
		static void toFloat(const char * &);
		static void toDouble(const char * &);

	private:
		const char * arg;
};

#endif