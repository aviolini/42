/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:28:06 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/12 14:35:13 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include "vectorIterators.hpp"
#include "utils.hpp"


namespace ft
{
template< typename T, typename A = std::allocator<T> >
class vector
{
public:
    typedef T										    	value_type;
	typedef A                                		    	allocator_type;
    typedef typename allocator_type::size_type		    	size_type;
    typedef value_type&								    	reference;
    typedef const value_type&						    	const_reference;
    typedef typename allocator_type::difference_type		difference_type;
    typedef typename allocator_type::pointer				pointer;
    typedef typename allocator_type::const_pointer	    	const_pointer;
	typedef vecIterator< myRandom_access_iterator_tag, T >	const_iterator;
	typedef vecIterator< myRandom_access_iterator_tag, T >	iterator;
	typedef	vecReverse_iterator< const_iterator >			const_reverse_iterator;
	typedef	vecReverse_iterator< iterator >					reverse_iterator;	
private:
	allocator_type	_allocator;
	pointer			_data;
	size_type		_size;
	size_type		_capacity;
public:	
	/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _data(0), _size(0), _capacity(0){}											//DEFAULT
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	: _allocator(alloc), _data(this->_allocator.allocate(n)), _size(n), _capacity(n)
	{
		if (n >= this->max_size())
			throw std::out_of_range("Error");
		for (size_type i = 0; i < (n); i++)
			this->_data[i] = val;
	}
	// template <class InputIterator>																		//<---|	
    // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ,		//|
	// 		typename myEnable_if<myHas_iterator_category<InputIterator>::value, T>::type = 0)					//|
	// : _allocator(alloc), _data(this->_allocator.allocate(last - first))										//|
	// {																										//|
	// 	InputIterator it = first;																				//|
	// 	InputIterator my = this->_data;																			//|
	// 	for (; it != last; ++it, ++my)																			//|
	// 		*my = *it;																							//|
	// 	this->_size = last - first;																				//|
	// 	this->_capacity = this->size();																			//|
	// }																										//|
	template <class InputIterator>																				//|
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ,			//|
			// typename myEnable_if_false<myHas_iterator_category<InputIterator>::value, T>::type = 0,		//<---|
			typename myEnable_if_false<myIs_integral<InputIterator>::value , T>::type = 0,
			typename myEnable_if_false<myIs_floating_point<InputIterator>::value , T>::type = 0)
	: _allocator(alloc), _data(this->_allocator.allocate(last - first))
	{
		if (last - first < 0)																								//|
			throw std::length_error("vector");																				//|
		InputIterator it = first;
		InputIterator my = this->_data;
		for (; it != last; ++it, ++my)
			*my = *it;
		this->_size = last - first;
		this->_capacity = this->size();	
	}
	// vector (const vector& x) : _allocator(allocator_type()), _size(x.size()), _capacity(x.size())
	vector (const vector& x) : _allocator(x._allocator), _size(x.size()), _capacity(x.size())

	{
		this->_data = this->_allocator.allocate(this->capacity());
		ft::vector<T,A>::const_iterator it = x.begin();
		iterator my = this->_data;
		for (; it != x.end(); ++it, ++my)
			*my = *it;				
	}
	~vector()
	{
		this->_allocator.deallocate(this->_data, this->capacity());
		this->_allocator.destroy(this->_data);
		this->_data = 0;
	}
	vector& operator= (const vector& x)
	{
		if (this->capacity() < x.capacity())
		{
			this->_allocator.deallocate(this->_data, this->capacity());
			this->_allocator.destroy(this->_data);
			this->_capacity = x.size();
			this->_data = this->_allocator.allocate(x.capacity());
		}
		this->_size = x.size();
		ft::vector<T,A>::const_iterator it = x.begin();
		iterator my = this->_data;
		for (; it != x.end(); ++it, ++my)
			*my = *it;
		return *this;
	}
	/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		return iterator(_data);
	}
	iterator end()
	{
		return iterator(_data) + this->size();
	}
	const_iterator begin() const
	{
		return iterator(_data);
	}
	const_iterator end() const
	{
		return iterator(_data) + this->size();
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(this->end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(this->begin());
	}
	const_reverse_iterator rbegin() const
	{
		return reverse_iterator(this->end());
	}
	const_reverse_iterator rend() const
	{
		return reverse_iterator(this->begin());
	}
	/*CAPACITY-----------------------------------------------------------------------------------*/
	size_type size() const
	{
		return this->_size;
	}
	size_type max_size() const
	{
		return _allocator.max_size();
	}
	void resize (size_type n, value_type val = value_type())
	{
		if (n <= this->size())
		{
			this->_size = n;
		}
		else if (n > this->size() && n <= this->capacity())
		{
			size_type i = this->size();
			for(; i < n; i++)
				this->_data[i] = val;
		}
		else
		{
			typename ft::vector<T,A>::pointer temp;
			size_type newCap = this->capacity() * 2;
			temp = this->_allocator.allocate(newCap);
			size_type i = 0;
			for (; i < this->size(); i++)
				temp[i] = this->_data[i];
			for(; i < n; i++)
				temp[i] = val;
			this->_allocator.deallocate(this->_data, this->capacity());
			this->_allocator.destroy(this->_data);
			this->_capacity = newCap;
			this->_data = temp;
		}
		this->_size = n;
	}
	size_type capacity() const
	{
		return this->_capacity;
	}
	bool empty() const
	{
		if (!this->size())
			return true;
		return false;
	}
	void reserve (size_type n)
	{
		if (n > this->capacity())
		{
			typename ft::vector<T,A>::pointer temp;
			size_type newCap = n;
			temp = this->_allocator.allocate(newCap);
			size_type i = 0;
			for (; i < this->size(); i++)
				temp[i] = this->_data[i];
			this->_allocator.deallocate(this->_data, this->capacity());
			this->_allocator.destroy(this->_data);
			this->_capacity = newCap;
			this->_data = temp;
		}
	}
	/*ELEMENT ACCESS-----------------------------------------------------------------------------------*/
	reference operator[] (size_type n)
	{
		return *(this->begin() + n);
	}
	const_reference operator[] (size_type n) const
	{
		return *(this->begin() + n);
	}
	reference at (size_type n)
	{
		if (n >= this->size())
			throw std::out_of_range("vector");
		return *(this->begin() + n);
	}
	const_reference at (size_type n) const
	{
		if (n >= this->size())
			throw std::out_of_range("vector");
		return *(this->begin() + n);
	}
	reference front()
	{
		return *(this->begin());
	}
	const_reference front() const
	{
		return *(this->begin());
	}
	reference back()
	{
		return *(this->end() - 1);
	}
	const_reference back() const
	{
		return *(this->end() - 1);
	}
	/*MODIFIERS-----------------------------------------------------------------------------------*/
	void assign (size_type n, const value_type& val)
	{
		if (this->capacity() < n)
		{
			this->_allocator.deallocate(this->_data, this->capacity());
			this->_allocator.destroy(this->_data);
			this->_data = this->_allocator.allocate(n);
			this->_capacity = n;
		}
		this->_size = n;
		iterator it = this->begin();
		for (; it != this->end(); ++it)
			*it = val;
	}
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, 
				typename myEnable_if_false<myHas_iterator_category<InputIterator>::value, T>::type = 0,	//--------------------|
				typename myEnable_if_false<myIs_integral<InputIterator>::value , T>::type = 0,								//|
				typename myEnable_if_false<myIs_floating_point<InputIterator>::value , T>::type = 0)						//|
	{																														//|
		if (last - first < 0)																								//|
			throw std::length_error("vector");																				//|
		unsigned int len = last - first;																					//|	
		// if (this->capacity() < len)																						//|
		// {																												//|
			this->_allocator.deallocate(this->_data, this->capacity());														//|
			this->_allocator.destroy(this->_data);																			//|
			this->_data = this->_allocator.allocate(len);																	//|
			this->_capacity = len;																							//|
		// }																												//|
    	const size_t n = static_cast<size_type>(len);																		//|
		this->_size = last - first;																							//|
		iterator it = this->begin();																						//|
		size_type i = 0;																									//|
		for (; i < n; ++it, ++first, ++i)																					//|
			*it = *first;																									//|
	}																														//|
	template <class InputIterator> //<-------------------------------------------------------------------------------------|
	void assign (InputIterator first, InputIterator last, typename myEnable_if<myHas_iterator_category<InputIterator>::value, T>::type = 0)
	{
		if (last - first < 0)																								
			throw std::length_error("vector");	
		unsigned int len = last - first;
		if (this->capacity() < len)
		{
			this->_allocator.deallocate(this->_data, this->capacity());
			this->_allocator.destroy(this->_data);
			this->_data = this->_allocator.allocate(len);
			this->_capacity = len;
		}
		this->_size = last - first;
		InputIterator it = first;
		InputIterator my = this->begin();
		for (; it != last; ++it, ++my)
			*my = *it;
	}
	void push_back (const value_type& val)
	{
		if (this->size() == this->capacity())
		{
			typename ft::vector<T,A>::pointer temp;
			size_type newCap;
			if (!this->capacity())
				newCap = 1;
			else
				newCap = this->capacity() * 2;
			temp = this->_allocator.allocate(newCap);
			size_type i = 0;
			for (; i < this->size(); i++)
				temp[i] = this->_data[i];
			this->_allocator.deallocate(this->_data, this->capacity());
			this->_allocator.destroy(this->_data);
			this->_capacity = newCap;
			this->_data = temp;	
		}
		this->_data[this->size()] = val;
		this->_size++;
	}
	void pop_back()
	{
		this->_size--;
	}
	iterator insert (iterator position, const value_type& val)
	{
		if (this->size() < this->capacity())				///////CONTROLLARE
		{
			ft::vector<T,A>::iterator it = this->begin();
			for (;it != position; ++it){}
			ft::vector<T,A>::iterator save = it;
			ft::vector<T,A>::iterator end = this->end();
			
			for (;end != (save -1); --end)
				*(end+1)=*end;
			*save = val;
			this->_size++;
			return save;
		}
		size_type newCap;
		if (!this->capacity())
			newCap = 1;
		else
			newCap = this->capacity() * 2;
			
		typename ft::vector<T,A>::pointer temp;
		temp = this->_allocator.allocate(newCap);
		size_type i = 0;
		size_type k = 0;
	
		ft::vector<T,A>::iterator it = this->begin();
		ft::vector<T,A>::iterator save;
		for (; it != position; ++it, ++i, ++k)
			temp[k] = this->_data[i];
		temp[k] = val;
		save = &(temp[k]);
		k++;
		for (; it != this->end(); ++it, ++i, ++k)
			temp[k] = this->_data[i];		
		this->_allocator.deallocate(this->_data, this->capacity());
		this->_allocator.destroy(this->_data);
		this->_capacity = newCap;
		this->_data = temp;
		this->_size++;
		return save;
	}
	void insert (iterator position, size_type n, const value_type& val)
	{
		if ((this->size() + n) <= this->capacity())
		{
			ft::vector<T,A>::iterator it = this->begin();
			for (;it != position; ++it){}
			ft::vector<T,A>::iterator save = it;
			ft::vector<T,A>::iterator end = this->end();
			
			for (;end != (save - n); --end)
				*(end + n)=*end;
			for (size_type i = 0;i < n; ++i)
			{
				*it = val;
				it++;
			}
			this->_size+=n;
			return ;
		}
		size_type newCap;
		if (!this->capacity())
			newCap = n;
		else if (this->capacity() < n)				////////////////METTERLA ANCHE ALLE FUNZIONI PRECEDENTI?
			newCap = n + this->size();
		else
			newCap = this->capacity() * 2;
		typename ft::vector<T,A>::pointer temp;
		temp = this->_allocator.allocate(newCap);
		size_type i = 0;
		size_type k = 0;
	
		ft::vector<T,A>::iterator it = this->begin();
		for (; it != position; ++it, ++i, ++k)
			temp[k] = this->_data[i];
		for (size_type i = 0; i  < n; ++i, ++k)
			temp[k] = val;
		for (; it != this->end(); ++it, ++i, ++k)
			temp[k] = this->_data[i];		
		this->_allocator.deallocate(this->_data, this->capacity());
		this->_allocator.destroy(this->_data);
		this->_capacity = newCap;
		this->_data = temp;
		this->_size+=n;
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
				typename myEnable_if_false<myHas_iterator_category<InputIterator>::value, T>::type = 0,
				typename myEnable_if_false<myIs_integral<InputIterator>::value , T>::type = 0,
				typename myEnable_if_false<myIs_floating_point<InputIterator>::value , T>::type = 0)
				
	{
		if (last - first < 0)
			return ;
    	const size_t n = static_cast<size_type>(last - first);
		if ((this->size() + n) <= this->capacity())
		{
			ft::vector<T,A>::iterator it = this->begin();
			for (;it != position; ++it){}
			ft::vector<T,A>::iterator save = it;
			ft::vector<T,A>::iterator end = this->end();
			
			for (;end != (save - n); --end)
				*(end + n)=*end;
			for (size_type i = 0;i < n; ++i)
			{
				*it = *first;
				first++;
			}
			this->_size+=n;
			return ;
		}
		size_type newCap;
		if (!this->capacity())
			newCap = n;
		else if (this->capacity() < n)
			newCap = n + this->size();
		else
			newCap = this->capacity() * 2;
		typename ft::vector<T,A>::pointer temp;
		temp = this->_allocator.allocate(newCap);
		size_type i = 0;
		size_type k = 0;
		ft::vector<T,A>::iterator it = this->begin();
		for (; it != position; ++it, ++i, ++k)
			temp[k] = this->_data[i];
		for (size_type i = 0; i  < n; ++i, ++k, first++)
			temp[k] = *first;
		for (; it != this->end(); ++it, ++i, ++k)
			temp[k] = this->_data[i];		
		this->_allocator.deallocate(this->_data, this->capacity());
		this->_allocator.destroy(this->_data);
		this->_capacity = newCap;
		this->_data = temp;
		this->_size+=n;	
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename myEnable_if<myHas_iterator_category<InputIterator>::value, T>::type = 0)
	{
		size_type n = last - first;
		if ((this->size() + n) <= this->capacity())
		{
			ft::vector<T,A>::iterator it = this->begin();
			for (;it != position; ++it){}
			ft::vector<T,A>::iterator save = it;
			ft::vector<T,A>::iterator end = this->end();
			
			for (;end != (save - n); --end)
				*(end + n)=*end;
			for (size_type i = 0;i < n; ++i)
			{
				*it = *first;
				first++;
			}
			this->_size+=n;
			return ;
		}
		size_type newCap;
		if (!this->capacity())
			newCap = n;
		else if (this->capacity() < n)
			newCap = n + this->size();
		else
			newCap = this->capacity() * 2;
		typename ft::vector<T,A>::pointer temp;
		temp = this->_allocator.allocate(newCap);
		size_type i = 0;
		size_type k = 0;
		ft::vector<T,A>::iterator it = this->begin();
		for (; it != position; ++it, ++i, ++k)
			temp[k] = this->_data[i];
		for (size_type i = 0; i  < n; ++i, ++k, first++)
			temp[k] = *first;
		for (; it != this->end(); ++it, ++i, ++k)
			temp[k] = this->_data[i];		
		this->_allocator.deallocate(this->_data, this->capacity());
		this->_allocator.destroy(this->_data);
		this->_capacity = newCap;
		this->_data = temp;
		this->_size+=n;	
	}
	iterator erase (iterator position)
	{
		iterator it;
		iterator save;
		for (it = this->begin(); it != position; ++it){}
		save = it;
		for (; it != this->end() - 1; ++it)
			*it = *(it + 1);
		this->_size--;
		return save;
	}
	iterator erase (iterator first, iterator last)
	{
		iterator it;
		iterator save;
		size_type n = last - first;
		for (it = this->begin(); it != first; ++it){}
		save = it;
		iterator it2 = it;
		for (; it2 != last; ++it2){}
		for (; it2 != this->end() + n; ++it2, ++it)
			*it = *(it2);
		this->_size -= n;
		return save;				
	}
	void swap (vector& x)
	{
		pointer temp = this->_data;
		size_type size = this->_size;
		size_type capacity = this->_capacity;
		
		this->_data = x._data;
		this->_size = x._size;
		this->_capacity = x._capacity;
		
		x._data = temp;
		x._size = size;
		x._capacity = capacity;
	}
	void clear()
	{
		this->_size = 0;
	}
	/*ALLOCATOR-----------------------------------------------------------------------------------*/
	allocator_type get_allocator() const
	{
		return this->_allocator;
	}
};
};
/*Non-member function overloads*/
/*SWAP--------------------------------------------------------------------------------*/
template <class T, class A>
void swap (ft::vector<T,A>& x, ft::vector<T,A>& y)
{
	x.swap(y);
}
/*RELATIONAL OPERATOR--------------------------------------------------------------------*/
template <class T, class A>
bool operator== (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T,A>::const_iterator lit = lhs.begin();
	typename ft::vector<T,A>::const_iterator rit = rhs.begin();
	for (;lit != lhs.end(); ++lit, ++rit)
		if (*lit != * rit)
			return false;
	return true;
}
template <class T, class A>
bool operator!= (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return !(lhs == rhs);
}
template <class T, class A>
bool operator< (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	typename ft::vector<T,A>::const_iterator lit = lhs.begin();
	typename ft::vector<T,A>::const_iterator rit = rhs.begin();
	while (lit != lhs.end())
	{
	  if (rit == rhs.end() || *rit < *lit) return false;
	  else if (*lit < *rit) return true;
	  ++lit; ++rit;
	}
	return (rit!=rhs.end());
}
template <class T, class A>
bool operator<= (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return ((lhs == rhs) || (lhs < rhs));
}
template <class T, class A>
bool operator> (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	typename ft::vector<T,A>::const_iterator lit = lhs.begin();
	typename ft::vector<T,A>::const_iterator rit = rhs.begin();
	while (rit != lhs.end())
	{
	  if (lit == rhs.end() || *lit < *rit) return false;
	  else if (*rit < *lit) return true;
	  ++rit; ++lit;
	}
	return (lit != rhs.end());
}
template <class T, class A>
bool operator>= (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return ((lhs == rhs) || (lhs > rhs));
}
#endif