/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:03:25 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/22 15:37:16 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//IMPLEMENTARE MUTANT STACK E LA FUNZIONE PER STAMPARE LA STACK 

template<typename S>
void stackTest()
{
	// S data1;
	typename S::container_type container;
	S data2(container);
	(void)data2;
}