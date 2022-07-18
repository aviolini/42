/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:33:41 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/22 10:54:57 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Span
{
		std::vector<int> _v;
		unsigned int const _maxSize;
	public:
		Span();
		Span(unsigned int const n);
		Span(Span const & obj);
		~Span();
		Span & operator = (Span const & obj);

		void print();
		void randomFill(unsigned int n);
		void addNumber(int const n);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
};

#endif