/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:41:20 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/30 20:42:26 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <cmath>

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main()
{
	{
		//INTERNO
		Point a(0,1),b(0,5),c(3,3),point(1,3);
		std:: cout << bsp(a,b,c,point) << std::endl;
	}
	{
		//INTERNO
		Point a(0.7,0.6),b(7,7.5),c(13.4,1.7),point(8,3);
		std:: cout << bsp(a,b,c,point) << std::endl;
	}
	{
		//SUL LATO
		Point a(1,1),b(3,1),c(4,2),point(2,1);
		std:: cout << bsp(a,b,c,point) << std::endl;
	}
	{
		//ESTERNO
		Point a(1,1),b(3,1),c(4,2),point(1,3);
		std:: cout << bsp(a,b,c,point) << std::endl;
	}
	{
		//ESTERNO
		Point a(1,1),b(3,1),c(4,2),point(100,300);
		std:: cout << bsp(a,b,c,point) << std::endl;
	}
	return 0;
}
