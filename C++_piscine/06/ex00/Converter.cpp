/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:25:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/15 23:27:33 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(const char * & arg) : arg(arg) {}

Converter::Converter(Converter const & obj) : arg(obj.arg) {}

Converter::~Converter(){}

Converter & Converter::operator=(Converter const & obj)
{
	this->arg = obj.arg;
	return *this;
}

void Converter::convertAll(const char * arg)
{
	Converter::toChar(arg);
	Converter::toInt(arg);
	Converter::toFloat(arg);
	Converter::toDouble(arg);
}

void Converter::toChar(const char * & arg)
{
	try
	{
		std::cout << "char:\t";
		if (strlen(arg) == 1 && !isdigit(*arg))
		{
			std::cout << "'" << static_cast<const char>(*arg) << "'" << std::endl;
			return;
		}
		int i;
		i = atoi(arg);
		if ((!i && strcmp(arg, "0")) || i < 0 || i > CHAR_MAX)
			throw "impossible";
		char c = static_cast<char>(i);
		if (isprint(c))
		{
			std::cout << "'" << c << "'"  << std::endl;
			return;
		}
		throw "Non displayable";
	}
	catch(const char * e)
	{
		std::cerr << e << std::endl;
	}	
}

void Converter::toInt(const char * & arg)
{
	try
	{
		std::cout << "int:\t";
		long int l;
		l = strtol(arg, 0, 10);
		if (l > INT_MAX || l < INT_MIN)
			throw "impossible";
		if (!l && strcmp(arg, "0"))
		{
			if (strlen(arg) == 1 && isprint(*arg))
				std::cout << static_cast<const int>(*arg) << std::endl;
			else
				throw "impossible";
		}
		else
			std::cout << static_cast<const int>(l) << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << std::endl;
	}
}

void Converter::toFloat(char const * & arg)
{
	try
	{
		std::cout << "float:\t";
		float f;
		f = atof(arg);
		if (!f && strcmp(arg,"0"))
		{
			if (strlen(arg) == 1 && isprint(*arg))
				std::cout << static_cast<const float>(*arg);
			else
				throw "impossible";
		}
		else
			std::cout << f;
		if (f - floor(f) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << std::endl;
	}
}

void Converter::toDouble(char const * & arg)
{
	try
	{
		std::cout << "double:\t";
		double d;
		d = strtod(arg, 0);
		if (!d && strcmp(arg,"0"))
		{
			if (strlen(arg) == 1 && isprint(*arg))
				std::cout << static_cast<const double>(*arg);
			else
				throw "impossible";
		}
		else
			std::cout << d;
		if (d - floor(d) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch(const char * e)
	{
		std::cerr << e << std::endl;
	}
		
}