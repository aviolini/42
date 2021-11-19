/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:59:04 by arrigo            #+#    #+#             */
/*   Updated: 2021/11/19 17:21:35 by arrigo           ###   ########.fr       */
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
	typedef typename treeIterator::value_type			value_type;
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

template <class Iterator>
class mapReverseIterator : public Iterator 
{
public:
	typedef Iterator									iterator_type;
	typedef typename iterator_type::value_type 			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::iterator_category	iterator_category;
public:	
/*CANONICAL-----------------------------------------------------------------------------------*/		
	mapReverseIterator () : Iterator(0) {}
	mapReverseIterator (Iterator initLoc) : Iterator(initLoc) {}
	~mapReverseIterator(){}
	mapReverseIterator(mapReverseIterator const & rhs) : Iterator(rhs._data) {}
	mapReverseIterator operator = (const mapReverseIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}
/*MEMBER OPERATORS--------------------------------------------------*/
	mapReverseIterator &operator ++()				//PREFIX
	{
		--this->_data;
		return *this;
	}
	mapReverseIterator operator ++(int)			//POSTFIX
	{
		mapReverseIterator t(*this);
		++(*this);
		return t;
	}
	mapReverseIterator &operator --()
	{
		++this->_data;
		return *this;
	}
	mapReverseIterator operator --(int)
	{
		mapReverseIterator t(*this);
		--(*this);
		return t;
	}				//POSTFIX
};

#endif