/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:12:36 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/30 20:26:03 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0),y(0)
{}

Point::Point(const float x, const float y):x(x),y(y)
{}

Point::~Point()
{}

Point & Point::operator=(Point &cl)
{
	return cl;
}

Fixed Point::area (const Point a,const Point b, const Point c)
{
	Fixed determinante = (c.x - a.x)*(b.y - a.y)-(b.x - a.x)*(c.y - a.y);
	if (determinante < 0)
		determinante = determinante * Fixed(-1);
	return Fixed((float)(0.5))* determinante;
}

//www.math.it/formulario/metrici.htm

//https://www.youtube.com/watch?v=qObJQesvZUU
