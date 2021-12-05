/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:59:04 by arrigo            #+#    #+#             */
/*   Updated: 2021/12/05 23:31:50 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_H
#define MAPITERATORS_H

#include "utils.hpp"

template <class tree>
class mapIterator
{
public:
	typedef ft::Bidirectional_iterator_tag	iterator_category;
	typedef typename tree::value_type			value_type;
	typedef typename tree::pointer				pointer;
	typedef typename tree::reference			reference;
	typedef typename tree::difference_type		difference_type;
	typedef typename tree::Pair					Pair;
protected:
	pointer _ptr;
public:	
/*CANONICAL-----------------------------------------------------------------------------------*/		
	mapIterator () : _ptr(0) {}
	mapIterator (pointer initLoc) : _ptr(initLoc) {}
	virtual ~mapIterator(){}
	mapIterator(mapIterator const & rhs) : _ptr(rhs._ptr) {}
	mapIterator operator = (const mapIterator & rhs)
	{
		this->_ptr = rhs._ptr;
		return *this;
	}
/*MEMBER OPERATORS--------------------------------------------------*/
// private:
public:
	pointer node() const
	{
		return _ptr;
	}
	pointer parent() const
	{
		return _ptr->_parent;
	}
	pointer right() const
	{
		return _ptr->_right;
	}
	pointer left() const
	{
		return _ptr->_left;
	}
	Pair & value() const
	{
		return _ptr->_value;
	}
public:
	Pair* operator -> () const
	{
		return &(this->_ptr->_value);
	}
	Pair &operator *() const
	{
		return (this->_ptr->_value);
	}
	mapIterator &operator ++()			//PREFIX
	{
		if (_ptr->_right != 0)
		{
			_ptr = _ptr->_right;
			while (_ptr->_left != 0)
				_ptr = _ptr->_left;
			return *this;		
		}
		while ( _ptr != _ptr->_parent->_left)
			_ptr = _ptr->_parent;
		_ptr = _ptr->_parent;
		return *this;
	}
	mapIterator operator ++(int)		//POSTFIX
	{
		mapIterator t(*this);
		++(*this);
		return t;
	}
	mapIterator &operator --()			//PREFIX
	{
		if (_ptr->_left != 0)
		{
			_ptr = _ptr->_left;
			while (_ptr->_right != 0)
				_ptr = _ptr->_right;
			return *this;		
		}
		_ptr = _ptr->_parent;
		return *this;
	}
	mapIterator operator --(int)		//POSTFIX
	{
		mapIterator t(*this);
		--(*this);
		return t;
	}				
/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator == (const mapIterator & rhs)
	{
		return (this->_ptr == rhs._ptr);
	}
	bool operator != (const mapIterator & rhs)
	{
		return !(this->_ptr == rhs._ptr);
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
	mapReverseIterator(mapReverseIterator const & rhs) : Iterator(rhs._ptr) {}
	mapReverseIterator operator = (const mapReverseIterator & rhs)
	{
		this->_ptr = rhs._ptr;
		return *this;
	}
/*MEMBER OPERATORS--------------------------------------------------*/
	// value_type operator -> () const
	// {
	// 	return &this->_ptr->_value;
	// }
	// reference operator *() const
	// {
	// 	return (this->_ptr->_value);
	// }	
	mapReverseIterator &operator ++()			//PREFIX
	{
		if (this->_ptr->_left != 0)
		{
			this->_ptr = this->_ptr->_left;
			while (this->_ptr->_right != 0)
				this->_ptr = this->_ptr->_right;
			return *this;		
		}
		this->_ptr = this->_ptr->_parent;
		return *this;
	}
	mapReverseIterator operator ++(int)			//POSTFIX
	{
		mapReverseIterator t(*this);
		++(*this);
		return t;
	}
	mapReverseIterator &operator --()			//PREFIX
	{
		if (this->_ptr->_right != 0)
		{
			this->_ptr = this->_ptr->_right;
			while (this->_ptr->_left != 0)
				this->_ptr = this->_ptr->_left;
			return *this;		
		}
		while ( this->_ptr != this->_ptr->_parent->_left)
			this->_ptr = this->_ptr->_parent;
		this->_ptr = this->_ptr->_parent;
		return *this;
	}
	mapReverseIterator operator --(int)			//POSTFIX
	{
		mapReverseIterator t(*this);
		--(*this);
		return t;
	}
};

#endif