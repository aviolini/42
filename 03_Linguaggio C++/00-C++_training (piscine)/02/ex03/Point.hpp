/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:12:51 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/30 20:26:13 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_H
# define _POINT_H

#include "Fixed.hpp"

class Point
{
	public:
	Point();
	Point(const float x, const float y);
	~Point();

	Point &operator=(Point &cl);
	static Fixed area (const Point a,const Point b, const Point c);


	private:
	const Fixed x;
	const Fixed y;
};

#endif