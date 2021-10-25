/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:38:53 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/30 12:54:50 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _maxSize(0)
{}

Span::Span(unsigned int const n) : _maxSize(n)
{}

Span::Span(Span const & obj) : _v(obj._v), _maxSize(obj._maxSize)
{}

Span & Span::operator = (Span const & obj)
{
	if (obj._maxSize != this->_maxSize)
		throw std::invalid_argument("Error: different sizes");
	this->_v = obj._v;
	return *this;
}

Span::~Span()
{
	this->_v.clear();
}

void Span::print()
{
	std::cout << "Print: " << std::endl;
	std::vector<int>::iterator it;
	for (it = this->_v.begin(); it != this->_v.end(); ++it)
		std::cout << *it << std::endl;
}

void Span::addNumber(int const n)
{
	try
	{
		if (this->_v.size() == this->_maxSize)
			throw std::out_of_range("Error: No more space");
		this->_v.push_back(n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

unsigned int Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw std::invalid_argument("Error: Too few elements to match");
	long min = UINT_MAX;
	std::vector<int> temp;
	temp = this->_v;
	std::sort(temp.begin(), temp.end());
	std::vector<int>::reverse_iterator rit;
	for (rit = temp.rbegin(); rit != temp.rend() - 1; ++rit)
	{
		long temp = static_cast<long>(*rit) - static_cast<long>(*(rit + 1));
		if ( temp < min )
			min = temp;
	}
	return static_cast<unsigned int>(min);
}

unsigned int Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw std::invalid_argument("Error: Too few elements to match");
	int min = *(std::min_element(this->_v.begin(), this->_v.end()));
	int max = *(std::max_element(this->_v.begin(), this->_v.end()));
	return static_cast<unsigned int>((static_cast<long>(max) - static_cast<long>(min)));
}

int randomNumber()
{
	return (std::rand() % 1000000);
}

void Span::randomFill(unsigned int n)
{
	if (this->_maxSize < n)
		throw std::invalid_argument("Error: Too many elements");
	this->_v.resize(n);						/*INIZIALIZZA IL VETTORE CON UNA SIZE*/
											/*AFFINCHE generate_n LO POSSA RIEMPIRE*/ 
	std::srand (unsigned (std::time(0)));
	std::generate_n(this->_v.begin(), n, randomNumber);
}