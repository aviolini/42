/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:44:33 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 23:17:44 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORS_H
#define VECTORITERATORS_H

#include "utils.hpp"

template <class Category, class T, class Distance = ft::ptrdiff_t, class Pointer = T*, class Reference = T&>
class vecIterator
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
	vecIterator () : _data(0){}
	vecIterator (pointer initLoc) : _data(initLoc){}
	virtual ~vecIterator(){}
	vecIterator(vecIterator const & rhs) : _data(rhs._data){}
	vecIterator operator = (const vecIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}	
	/*MEMBER OPERATORS--------------------------------------------------*/
	reference operator *()
	{
		return *this->_data;
	}
	vecIterator operator + ( const difference_type &n ) const
	{
		vecIterator obj(this->_data + n);
		return obj;
	}
	vecIterator &operator ++()				//PREFIX
	{
		this->_data++;
		return *this;
	}
	vecIterator operator ++(int)				//POSTFIX
	{
		vecIterator temp = *this;
		this->_data++;
		return temp;
	}
	vecIterator & operator += (difference_type n)
	{
		this->_data += n;
		return *this;
	}
	vecIterator operator - ( const difference_type &n ) const
	{
		vecIterator obj(this->_data - n);
		return obj;
	}
	difference_type operator - ( const vecIterator &rhs) const
	{
		return this->_data - rhs._data;
	}
	vecIterator &operator --()				//PREFIX
	{
		this->_data--;
		return *this;
	}
	vecIterator operator --(int)				//POSTFIX
	{
		vecIterator temp = *this;
		this->_data--;
		return temp;
	}
	vecIterator & operator -= (difference_type n)
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
	bool operator == (const vecIterator & rhs)
	{
		return this->_data == rhs._data;
	}
	bool operator != (const vecIterator & rhs)
	{
		return !(this->_data == rhs._data);
	}
	bool operator > (const vecIterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator >= (const vecIterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
	bool operator < (const vecIterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator <= (const vecIterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
};

template <class Iterator> 
class vecReverse_iterator : public Iterator
{
public:
	typedef Iterator									iterator_type;
	typedef typename iterator_type::value_type 			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::iterator_category	iterator_category;
	/*CANONICAL-----------------------------------------------------------------------------------*/		
	vecReverse_iterator () : Iterator(0){}
	explicit vecReverse_iterator (iterator_type it) : Iterator(it - 1){}
	template <class Iter>
  	vecReverse_iterator (const vecReverse_iterator<Iter>& rev_it,typename myEnable_if<myHas_iterator_category<Iter>::value, value_type>::type = 0)
	{
		this->_data = rev_it._data;
	}
	~vecReverse_iterator(){}
	vecReverse_iterator(vecReverse_iterator const & rhs)
	{
		this->_data = rhs._data;
	}
	vecReverse_iterator operator = (const vecReverse_iterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	vecReverse_iterator &operator ++()				//PREFIX
	{
		this->_data--;
		return *this;
	}
	vecReverse_iterator operator ++(int)				//POSTFIX
	{
		vecReverse_iterator temp = *this;
		this->_data--;
		return temp;
	}
	vecReverse_iterator &operator --()				//PREFIX
	{
		this->_data++;
		return *this;
	}
	vecReverse_iterator operator --(int)				//POSTFIX
	{
		vecReverse_iterator temp = *this;
		this->_data++;
		return temp;
	}
	/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator > (const vecReverse_iterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator >= (const vecReverse_iterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
	bool operator < (const vecReverse_iterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator <= (const vecReverse_iterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
};

#endif