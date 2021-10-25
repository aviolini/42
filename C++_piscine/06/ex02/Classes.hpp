/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:54:20 by aviolini          #+#    #+#             */
/*   Updated: 2021/09/25 18:39:42 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_H
#define CLASSES_H

class Base
{
	public:
		Base(){}
		virtual ~Base(){}	
};

class A : public Base
{
	public:
		A(){}
		virtual ~A(){}
};

class B : public Base
{
	public:
		B(){}
		virtual ~B(){}
};

class C : public Base
{
	public:
		C(){}
		virtual ~C(){}
};
#endif
