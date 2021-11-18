/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:59:04 by arrigo            #+#    #+#             */
/*   Updated: 2021/11/18 17:46:49 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_H
#define MAPITERATORS_H

#include "utils.hpp"

template <class treeIterator>
class mapIterator
{
public:
	typedef typename treeIterator::iterator_category	iterator_category;
	typedef typename treeIterator::pointer				pointer;
	typedef typename treeIterator::reference			reference;
	typedef typename treeIterator::difference_type		difference_type;
	typedef typename treeIterator::Pair					Pair;
protected:
	treeIterator _data;
public:	
/*CANONICAL-----------------------------------------------------------------------------------*/		
	mapIterator () : _data(0) {}
	mapIterator (treeIterator initLoc) : _data(initLoc) {}
	~mapIterator(){}
	mapIterator(mapIterator const & rhs) : _data(rhs._data) {}
	mapIterator operator = (const mapIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}
/*MEMBER OPERATORS--------------------------------------------------*/
	Pair *operator -> ()
	{
		return &this->_data->_value;
	}
	Pair operator *()
	{
		return (this->_data->_value);
	}
	mapIterator &operator ++()				//PREFIX
	{
		++this->_data;
		return *this;
	}
	mapIterator operator ++(int)			//POSTFIX
	{
		mapIterator t(*this);
		++(*this);
		return t;
	}
	mapIterator &operator --()
	{
		--this->_data;
		return *this;
	}
	mapIterator operator --(int)
	{
		mapIterator t(*this);
		--(*this);
		return t;
	}				//POSTFIX
/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator == (const mapIterator & rhs)
	{
		return (this->_data == rhs._data);
	}
	bool operator != (const mapIterator & rhs)
	{
		return !(this->_data == rhs._data);
	}
};

#endif