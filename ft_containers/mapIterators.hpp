/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:59:04 by arrigo            #+#    #+#             */
/*   Updated: 2021/11/17 19:44:53 by arrigo           ###   ########.fr       */
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
	// mapIterator(mapIterator const & rhs);
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
	Pair *operator *()
	{
		return (this->_data->_value);
	}
	mapIterator operator + ( const difference_type &n ) const;
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
	mapIterator & operator += (difference_type n);
	mapIterator operator - ( const difference_type &n ) const;
	difference_type operator - ( const mapIterator &rhs) const;
	mapIterator &operator --();				//PREFIX
	mapIterator operator --(int);				//POSTFIX
	mapIterator & operator -= (difference_type n);
	reference operator [] (int index);
/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator == (const mapIterator & rhs)
	{
		return (this->_data == rhs._data);
	}
	bool operator != (const mapIterator & rhs)
	{
		return !(this->_data == rhs._data);
	}
	bool operator > (const mapIterator & rhs);
	bool operator >= (const mapIterator & rhs);
	bool operator < (const mapIterator & rhs);
	bool operator <= (const mapIterator & rhs);
};

template <class Iterator> 
class mapReverse_iterator : public Iterator
{
public:
	typedef Iterator									iterator_type;
	typedef typename iterator_type::value_type 			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::iterator_category	iterator_category;
/*CANONICAL-----------------------------------------------------------------------------------*/		
	mapReverse_iterator ();
	explicit mapReverse_iterator (iterator_type it);
	template <class Iter>
  	mapReverse_iterator (const mapReverse_iterator<Iter>& rev_it,typename myEnable_if<myHas_iterator_category<Iter>::value, value_type>::type = 0);
	~mapReverse_iterator();
	mapReverse_iterator(mapReverse_iterator const & rhs);
	mapReverse_iterator operator = (const mapReverse_iterator & rhs);
/*MEMBER OPERATORS--------------------------------------------------*/
	mapReverse_iterator &operator ++();				//PREFIX
	mapReverse_iterator operator ++(int);				//POSTFIX
	mapReverse_iterator &operator --();				//PREFIX
	mapReverse_iterator operator --(int);				//POSTFIX
/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator > (const mapReverse_iterator & rhs);
	bool operator >= (const mapReverse_iterator & rhs);
	bool operator < (const mapReverse_iterator & rhs);
	bool operator <= (const mapReverse_iterator & rhs);
};

#endif