/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:44:33 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/01 00:30:31 by arrigo           ###   ########.fr       */
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
	vectorIterator(vectorIterator<Category, T, Distance, T*, T&> const & rhs) : _data(rhs.getData()){}
	vectorIterator &operator= (const vectorIterator & rhs)
	{
		_data = rhs.getData();
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	pointer getData() const
	{
		return _data;
	}
	reference operator *()
	{
		return *_data;
	}
	vectorIterator operator + ( const difference_type &n ) const
	{
		vectorIterator obj(_data + n);
		return obj;
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
	vectorIterator operator - ( const difference_type &n ) const
	{
		vectorIterator obj(_data - n);
		return obj;
	}
	difference_type operator - ( const vectorIterator &rhs) const
	{
		return _data - rhs._data;
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

/*Non-member function overloads*/
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
  	vectorReverseIterator (const vectorReverseIterator<Iter>& rev_it,typename ft::EnableIfTrue<ft::HasIteratorCategory<Iter>::value, value_type>::type = 0)
	{
		this->_data = rev_it._data;
	}
	~vectorReverseIterator(){}
	vectorReverseIterator(vectorReverseIterator const & rhs)
	{
		this->_data = rhs._data;
	}
	vectorReverseIterator operator = (const vectorReverseIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	vectorReverseIterator &operator ++()			//PREFIX
	{
		this->_data--;
		return *this;
	}
	vectorReverseIterator operator ++(int)			//POSTFIX
	{
		vectorReverseIterator temp = *this;
		this->_data--;
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
		this->_data++;
		return temp;
	}
	/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator > (const vectorReverseIterator & rhs)
	{
		return (this->_data < rhs._data);
	}
	bool operator >= (const vectorReverseIterator & rhs)
	{
		return (this->_data <= rhs._data);
	}
	bool operator < (const vectorReverseIterator & rhs)
	{
		return (this->_data > rhs._data);
	}
	bool operator <= (const vectorReverseIterator & rhs)
	{
		return (this->_data >= rhs._data);
	}
};

#endif