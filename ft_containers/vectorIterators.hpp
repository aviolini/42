/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:44:33 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 22:56:33 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORS_H
#define VECTORITERATORS_H

#include "utils.hpp"

struct myInput_iterator_tag {};
struct myOutput_iterator_tag {};
struct myForward_iterator_tag       : public myInput_iterator_tag {};
struct myBidirectional_iterator_tag : public myForward_iterator_tag {};
struct myRandom_access_iterator_tag : public myBidirectional_iterator_tag {};

namespace ft
{
template <class Category, class T, class Distance = ft::ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator
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
	iterator () : _data(0){}
	iterator (pointer initLoc) : _data(initLoc){}
	virtual ~iterator(){}
	iterator(iterator const & rhs) : _data(rhs._data){}
	iterator operator = (const iterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}	
	/*MEMBER OPERATORS--------------------------------------------------*/
	reference operator *()
	{
		return *this->_data;
	}
	iterator operator + ( const difference_type &n ) const
	{
		iterator obj(this->_data + n);
		return obj;
	}
	iterator &operator ++()				//PREFIX
	{
		this->_data++;
		return *this;
	}
	iterator operator ++(int)				//POSTFIX
	{
		iterator temp = *this;
		this->_data++;
		return temp;
	}
	iterator & operator += (difference_type n)
	{
		this->_data += n;
		return *this;
	}
	iterator operator - ( const difference_type &n ) const
	{
		iterator obj(this->_data - n);
		return obj;
	}
	difference_type operator - ( const iterator &rhs) const
	{
		return this->_data - rhs._data;
	}
	iterator &operator --()				//PREFIX
	{
		this->_data--;
		return *this;
	}
	iterator operator --(int)				//POSTFIX
	{
		iterator temp = *this;
		this->_data--;
		return temp;
	}
	iterator & operator -= (difference_type n)
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
	bool operator == (const iterator & rhs)
	{
		return this->_data == rhs._data;
	}
	bool operator != (const iterator & rhs)
	{
		return !(this->_data == rhs._data);
	}
	bool operator > (const iterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator >= (const iterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
	bool operator < (const iterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator <= (const iterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
};
};

namespace ft
{
template <class Iterator> 
class reverse_iterator : public Iterator
{
public:
	typedef Iterator									iterator_type;
	typedef typename iterator_type::value_type 			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::iterator_category	iterator_category;
	/*CANONICAL-----------------------------------------------------------------------------------*/		
	reverse_iterator () : Iterator(0){}
	explicit reverse_iterator (iterator_type it) : Iterator(it - 1){}
	template <class Iter>
  	reverse_iterator (const reverse_iterator<Iter>& rev_it,typename myEnable_if<myHas_iterator_category<Iter>::value, value_type>::type = 0)
	{
		this->_data = rev_it._data;
	}
	~reverse_iterator(){}
	reverse_iterator(reverse_iterator const & rhs)
	{
		this->_data = rhs._data;
	}
	reverse_iterator operator = (const reverse_iterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	reverse_iterator &operator ++()				//PREFIX
	{
		this->_data--;
		return *this;
	}
	reverse_iterator operator ++(int)				//POSTFIX
	{
		reverse_iterator temp = *this;
		this->_data--;
		return temp;
	}
	reverse_iterator &operator --()				//PREFIX
	{
		this->_data++;
		return *this;
	}
	reverse_iterator operator --(int)				//POSTFIX
	{
		reverse_iterator temp = *this;
		this->_data++;
		return temp;
	}
	/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator > (const reverse_iterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator >= (const reverse_iterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
	bool operator < (const reverse_iterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator <= (const reverse_iterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
};
};


#endif