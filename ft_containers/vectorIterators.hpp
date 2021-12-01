/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:44:33 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/01 15:49:06 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORS_H
#define VECTORITERATORS_H

#include "utils.hpp"

template <class Category, class T, class Distance = ft::ptrdiff_t, class Pointer = T*, class Reference = T&>
class vectorIterator
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
	vectorIterator () : _data(0){}
	vectorIterator (pointer initLoc) : _data(initLoc){}
	// vectorIterator (T* initLoc) : _data(initLoc){}
	virtual ~vectorIterator(){}
	vectorIterator(vectorIterator<Category, T, Distance, T*, T&> const & rhs) : _data(rhs.base()){}
	vectorIterator &operator= (const vectorIterator & rhs)
	{
		_data = rhs.base();
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	pointer base() const
	{
		return _data;
	}
	reference operator *()
	{
		return *_data;
	}
	vectorIterator &operator ++()			//PREFIX
	{
		_data++;
		return *this;
	}
	vectorIterator operator ++(int)			//POSTFIX
	{
		vectorIterator temp = *this;
		_data++;
		return temp;
	}
	vectorIterator & operator += (difference_type n)
	{
		_data += n;
		return *this;
	}
	vectorIterator &operator --()			//PREFIX
	{
		_data--;
		return *this;
	}
	vectorIterator operator --(int)			//POSTFIX
	{
		vectorIterator temp = *this;
		_data--;
		return temp;
	}
	vectorIterator & operator -= (difference_type n)
	{
		_data -= n;
		return *this;
	}
	pointer operator -> ()
	{
		return _data;
	}
	reference operator [] (int index)
	{
		return *(_data + index);
	}

/*Non-member function overloads*/
// /*ARITHMETIC OPERATORS--------------------------------------------------*/
	friend vectorIterator	operator+(const vectorIterator& it, difference_type n) 
	{ return vectorIterator(it._data + n); }
	friend vectorIterator	operator+(difference_type n, const vectorIterator& it) 
	{ return vectorIterator(it._data + n); }
	friend vectorIterator	operator-(const vectorIterator& it, difference_type n) 
	{ return vectorIterator(it._data - n); }
	friend vectorIterator	operator-(difference_type n, const vectorIterator& it) 
	{ return vectorIterator(it._data - n); }
	friend difference_type	operator-(const vectorIterator& a, const vectorIterator& b) 
	{ return (a._data - b._data); }

	
	// /*RELATIONAL OPERATORS--------------------------------------------------*/
	// bool operator == (const vectorIterator & rhs)
	// {
	// 	return _data == rhs._data;
	// }
	// bool operator != (const vectorIterator & rhs)
	// {
	// 	return !(_data == rhs._data);
	// }
	// bool operator > (const vectorIterator & rhs)
	// {
	// 	return (_data > rhs._data);
	// }
	// bool operator >= (const vectorIterator & rhs)
	// {
	// 	return (_data >= rhs._data);
	// }
	// bool operator < (const vectorIterator & rhs)
	// {
	// 	return (_data < rhs._data);
	// }
	// bool operator <= (const vectorIterator & rhs)
	// {
	// 	return (_data <= rhs._data);
	// }

/*RELATIONAL OPERATOR--------------------------------------------------------------------*/
	friend bool operator== (const vectorIterator& lhs, const vectorIterator& rhs) 
	{ return lhs._data == rhs._data; }
	friend bool operator!= (const vectorIterator& lhs, const vectorIterator& rhs) 
	{ return lhs._data != rhs._data; }
	friend bool operator< (const vectorIterator& lhs, const vectorIterator& rhs) 
	{ return lhs._data < rhs._data; }
	friend bool operator<= (const vectorIterator& lhs, const vectorIterator& rhs) 
	{ return lhs._data <= rhs._data; }
	friend bool operator> (const vectorIterator& lhs, const vectorIterator& rhs) 
	{ return lhs._data > rhs._data; }
	friend bool operator>= (const vectorIterator& lhs, const vectorIterator& rhs) 
	{ return lhs._data >= rhs._data; }
};

template <class Iterator> 
class vectorReverseIterator : public Iterator
{
public:
	typedef Iterator									iterator_type;
	typedef typename iterator_type::value_type 			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::iterator_category	iterator_category;
	/*CANONICAL-----------------------------------------------------------------------------------*/		
	vectorReverseIterator () : Iterator(0){}
	explicit vectorReverseIterator (iterator_type it) : Iterator(it - 1){}
	template <class Iter>
  	vectorReverseIterator (const vectorReverseIterator<Iter>& rev_it, typename ft::EnableIfTrue<ft::HasIteratorCategory<Iter>::value, value_type>::type = 0)
	{
		this->_data = rev_it.base() - 1;
	}
	~vectorReverseIterator(){}
	vectorReverseIterator(vectorReverseIterator const & rhs)// : Iterator::_data(rhs.base()){}
	{
		this->_data = rhs.base() - 1;
	}
	vectorReverseIterator & operator =(const vectorReverseIterator & rhs)
	{
		this->_data = rhs.base() - 1;
		return *this;
	}
	vectorReverseIterator & operator =(const pointer& ptr)
	{
		this->_data = ptr;
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	pointer base() const
	{
		return (this->_data + 1);
	}
	vectorReverseIterator &operator ++()			//PREFIX
	{
		this->_data--;
		return *this;
	}
	vectorReverseIterator operator ++(int)			//POSTFIX
	{
		vectorReverseIterator temp = *this;
		++this->_data;
		return temp;
	}
	vectorReverseIterator &operator --()			//PREFIX
	{
		this->_data++;
		return *this;
	}
	vectorReverseIterator operator --(int)			//POSTFIX
	{
		vectorReverseIterator temp = *this;
		--this->_data;
		return temp;
	}
	vectorReverseIterator & operator += (difference_type n)
	{
		this->_data -= n;
		return *this;
	}
	vectorReverseIterator & operator -= (difference_type n)
	{
		this->_data += n;
		return *this;
	}
	difference_type operator - (const vectorReverseIterator& b) const
	{
		return (b.base() - this->base());
	}
	reference operator [] (int index)
	{
		return *(this->_data - index);
	}
/*Non-member function overloads*/
// /*ARITHMETIC OPERATORS--------------------------------------------------*/
	friend vectorReverseIterator	operator+(const vectorReverseIterator& it, difference_type n) 
	{ return vectorReverseIterator(it.base() - n); }
	friend vectorReverseIterator	operator+(difference_type n, const vectorReverseIterator& it) 
	{ return vectorReverseIterator(it.base() - n); }
	friend vectorReverseIterator	operator-(const vectorReverseIterator& it, difference_type n) 
	{ return vectorReverseIterator(it.base() + n); }
	friend vectorReverseIterator	operator-(difference_type n, const vectorReverseIterator& it) 
	{ return vectorReverseIterator(it.base() + n); }

/*RELATIONAL OPERATOR--------------------------------------------------------------------*/
	friend bool operator< (const vectorReverseIterator& lhs, const vectorReverseIterator& rhs) 
	{ return lhs._data >= rhs._data; }
	friend bool operator<= (const vectorReverseIterator& lhs, const vectorReverseIterator& rhs) 
	{ return lhs._data > rhs._data; }
	friend bool operator> (const vectorReverseIterator& lhs, const vectorReverseIterator& rhs) 
	{ return lhs._data <= rhs._data; }
	friend bool operator>= (const vectorReverseIterator& lhs, const vectorReverseIterator& rhs) 
	{ return lhs._data < rhs._data; }
};

#endif