/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:30:00 by arrigo            #+#    #+#             */
/*   Updated: 2021/10/27 22:30:11 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_H
#define MAPITERATORS_H

#include "utils.hpp"

struct myInput_iterator_tag {};
struct myOutput_iterator_tag {};
struct myForward_iterator_tag       : public myInput_iterator_tag {};
struct myBidirectional_iterator_tag : public myForward_iterator_tag {};
struct myRandom_access_iterator_tag : public myBidirectional_iterator_tag {};

template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
class myIterator
{
public:
	typedef T					value_type;
	typedef Pointer				pointer;
	typedef Reference			reference;
	typedef Distance			difference_type;
	typedef Category			iterator_category;
protected:
	pointer _data;
public:	
	/*CANONICAL-----------------------------------------------------------------------------------*/		
	myIterator () : _data(0){}
	myIterator (pointer initLoc) : _data(initLoc){}
	virtual ~myIterator(){}
	myIterator(myIterator const & rhs) : _data(rhs._data){}
	myIterator operator = (const myIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}	
	/*MEMBER OPERATORS--------------------------------------------------*/
	reference operator *()
	{
		return *this->_data;
	}
	myIterator operator + ( const difference_type &n ) const
	{
		myIterator obj(this->_data + n);
		return obj;
	}
	myIterator &operator ++()				//PREFIX
	{
		this->_data++;
		return *this;
	}
	myIterator operator ++(int)				//POSTFIX
	{
		myIterator temp = *this;
		this->_data++;
		return temp;
	}
	myIterator & operator += (difference_type n)
	{
		this->_data += n;
		return *this;
	}
	myIterator operator - ( const difference_type &n ) const
	{
		myIterator obj(this->_data - n);
		return obj;
	}
	difference_type operator - ( const myIterator &rhs) const
	{
		return this->_data - rhs._data;
	}
	myIterator &operator --()				//PREFIX
	{
		this->_data--;
		return *this;
	}
	myIterator operator --(int)				//POSTFIX
	{
		myIterator temp = *this;
		this->_data--;
		return temp;
	}
	myIterator & operator -= (difference_type n)
	{
		this->_data -= n;
		return *this;
	}
	pointer operator -> ()
	{
		return this->_data;
	}
	reference operator [] (int index)
	{
		return *(this->_data + index);
	}
	/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator == (const myIterator & rhs)
	{
		return this->_data == rhs._data;
	}
	bool operator != (const myIterator & rhs)
	{
		return !(this->_data == rhs._data);
	}
	bool operator > (const myIterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator >= (const myIterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
	bool operator < (const myIterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator <= (const myIterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
};

template <class myIterator> 
class myRevIterator : public myIterator
{
public:
	typedef myIterator									iterator_type;
	typedef typename iterator_type::value_type 			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::iterator_category	iterator_category;
	/*CANONICAL-----------------------------------------------------------------------------------*/		
	myRevIterator () : myIterator(0){}
	explicit myRevIterator (iterator_type it) : myIterator(it - 1){}
	template <class Iter>
  	myRevIterator (const myRevIterator<Iter>& rev_it,typename myEnable_if<myHas_iterator_category<Iter>::value, value_type>::type = 0)
	{
		this->_data = rev_it._data;
	}
	~myRevIterator(){}
	myRevIterator(myRevIterator const & rhs)
	{
		this->_data = rhs._data;
	}
	myRevIterator operator = (const myRevIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	myRevIterator &operator ++()				//PREFIX
	{
		this->_data--;
		return *this;
	}
	myRevIterator operator ++(int)				//POSTFIX
	{
		myRevIterator temp = *this;
		this->_data--;
		return temp;
	}
	myRevIterator &operator --()				//PREFIX
	{
		this->_data++;
		return *this;
	}
	myRevIterator operator --(int)				//POSTFIX
	{
		myRevIterator temp = *this;
		this->_data++;
		return temp;
	}
	/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator > (const myRevIterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator >= (const myRevIterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
	bool operator < (const myRevIterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator <= (const myRevIterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
};


#endif