/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:11:43 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/30 20:23:55 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//BSP stands for Binary space partitioning.

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = Point::area(a,b,c);
	Fixed area1 = Point::area(a,b,point);
	Fixed area2 = Point::area(a,point,c);
	Fixed area3 = Point::area(point,b,c);

	// std::cout << std::endl;
	// std::cout << area << std::endl;
	// std::cout << area1 << std::endl;
	// std::cout << area2 << std::endl;
	// std::cout << area3 << std::endl;

	if (area1 == 0 ||
		area2 == 0 ||
		area3 == 0 ||
		(area1 + area2 + area3) > area)
		return false;
	return true;
}