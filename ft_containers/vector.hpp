/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:56:26 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/03 16:30:43 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "vectorIterators.hpp"
#include "utils.hpp"

namespace ft
{
template< typename T, typename A = std::allocator<T> >
class vector
{
public:
    typedef T										    		value_type;
	typedef A                                		    		allocator_type;
    typedef typename allocator_type::size_type		    		size_type;
    typedef typename allocator_type::reference		    		reference;
    typedef typename allocator_type::const_reference    		const_reference;
    typedef typename allocator_type::difference_type			difference_type;
    typedef typename allocator_type::pointer					pointer;
    typedef typename allocator_type::const_pointer	    		const_pointer;
	typedef vectorIterator<ft::Random_access_iterator_tag, 
		value_type, ptrdiff_t, const_pointer, const_reference>	const_iterator;
	typedef vectorIterator<ft::Random_access_iterator_tag, T>	iterator;
	typedef	vectorReverseIterator<const_iterator>				const_reverse_iterator;
	typedef	vectorReverseIterator<iterator>						reverse_iterator;	
private:
	allocator_type	_allocator;
	pointer			_data;
	size_type		_size;
	size_type		_capacity;
public:	
	/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _data(0), _size(0), _capacity(0){}											//DEFAULT
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	: _allocator(alloc),  _size(n), _capacity(n)
	{
		_data = _allocator.allocate(n);
		for (size_type i = 0; i < n; ++i)
			_allocator.construct(&_data[i], val);
		// _allocator.construct(_data, val);

	}
	template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ,
			typename ft::EnableIfFalse<ft::IsIntegral<InputIterator>::value , T>::type = 0,
			typename ft::EnableIfFalse<ft::IsFloatingPoint<InputIterator>::value , T>::type = 0)
	: _allocator(alloc) 
	{
		size_t len = 0;
		for (InputIterator temp = first; temp != last; temp++) 
			len++;
		// std::cout <<"END" << std::endl;
		_data = (_allocator.allocate(len));
		_allocator.construct(_data, value_type());
		// if (last - first < 0)
		// 	throw std::length_error("vector");
		InputIterator it = first;
		pointer my = _data;
		for (; it != last; ++it, ++my)
			*my = *it;
		_size = len;
		_capacity = size();
	}
	vector (const vector& x) : _allocator(x._allocator), _size(x.size()), _capacity(x.size())
	{
		const_iterator it = x.begin();
		_data = _allocator.allocate(capacity());
		for (size_t i = 0; it != end(); ++i, ++it)
			_allocator.construct(_data + i, *it);
		// iterator my = _data;
		// for (; it != x.end(); ++it, ++my)
		// 	*my = *it;				
	}
	~vector()
	{
		if (_data)
		{
			_allocator.destroy(_data);
			_allocator.deallocate(_data, capacity());
			_data = 0;
		}
	}
	vector& operator= (const vector& x)
	{
		if (capacity() < x.capacity())
		{
			_allocator.deallocate(_data, capacity());
			_allocator.destroy(_data);
			_capacity = x.size();
			_data = _allocator.allocate(x.capacity());
			_allocator.construct(_data, value_type());
		}
		_size = x.size();
		const_iterator it = x.begin();
		iterator my = _data;
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
		return iterator(_data) + size();
	}
	const_iterator begin() const
	{
		return const_iterator(_data);
	}
	const_iterator end() const
	{
		return const_iterator(_data + size());
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}
	/*CAPACITY-----------------------------------------------------------------------------------*/
	size_type size() const
	{
		return _size;
	}
	size_type max_size() const
	{
		return _allocator.max_size();
	}
	void resize (size_type n, value_type val = value_type())
	{
		if (n <= size())
		{
			_size = n;
		}
		else if (n > size() && n <= capacity())
		{
			size_type i = size();
			for(; i < n; i++)
				_data[i] = val;
		}
		else
		{
			pointer temp;
			size_type newCap = capacity() * 2;
			temp = _allocator.allocate(newCap);
			_allocator.construct(temp, value_type());
			size_type i = 0;
			for (; i < size(); i++)
				temp[i] = _data[i];
			for(; i < n; i++)
				temp[i] = val;
			_allocator.deallocate(_data, capacity());
			_allocator.destroy(_data);
			_capacity = newCap;
			_data = temp;
		}
		_size = n;
	}
	size_type capacity() const
	{
		return _capacity;
	}
	bool empty() const
	{
		if (!size())
			return true;
		return false;
	}
	void reserve (size_type n)
	{
		if (n > capacity())
		{
			pointer temp;
			size_type newCap = n;
			temp = _allocator.allocate(newCap);
			_allocator.construct(temp, value_type());
			size_type i = 0;
			for (; i < size(); i++)
				temp[i] = _data[i];
			_allocator.deallocate(_data, capacity());
			_allocator.destroy(_data);
			_capacity = newCap;
			_data = temp;
		}
	}
	/*ELEMENT ACCESS-----------------------------------------------------------------------------------*/
	reference operator[] (size_type n)
	{
		return *(begin() + n);
	}
	const_reference operator[] (size_type n) const
	{
		return *(begin() + n);
	}
	reference at (size_type n)
	{
		if (n >= size())
			throw std::out_of_range("vector");
		return *(begin() + n);
	}
	const_reference at (size_type n) const
	{
		if (n >= size())
			throw std::out_of_range("vector");
		return *(begin() + n);
	}
	reference front()
	{
		return *(begin());
	}
	const_reference front() const
	{
		return *(begin());
	}
	reference back()
	{
		return *(end() - 1);
	}
	const_reference back() const
	{
		return *(end() - 1);
	}
	/*MODIFIERS-----------------------------------------------------------------------------------*/
	void assign (size_type n, const value_type& val)
	{
		if (capacity() < n)
		{
			_allocator.deallocate(_data, capacity());
			_allocator.destroy(_data);
			_data = _allocator.allocate(n);
			_allocator.construct(_data, value_type());
			_capacity = n;
		}
		_size = n;
		iterator it = begin();
		for (; it != end(); ++it)
			*it = val;
	}
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, 
				typename ft::EnableIfFalse<ft::IsIntegral<InputIterator>::value , T>::type = 0,
				typename ft::EnableIfFalse<ft::IsFloatingPoint<InputIterator>::value , T>::type = 0)	
	{
		// if (last - first < 0)																								
		// 	throw std::length_error("vector");	
		size_t len = 0;
		for (InputIterator temp = first; temp != last; temp++) 
			len++;
		if (capacity() < len)
		{
			_allocator.deallocate(_data, capacity());
			_allocator.destroy(_data);
			_data = _allocator.allocate(len);
			_allocator.construct(_data, value_type());
			_capacity = len;
		}
		_size = len;
		InputIterator it = first;
		pointer my = _data;
		for (; it != last; ++it, ++my)
			*my = *it;
	}
	void push_back (const value_type& val)
	{
		if (size() == capacity())
		{
			pointer temp;
			size_type newCap;
			if (!capacity())
				newCap = 1;
			else
				newCap = capacity() * 2;
			temp = _allocator.allocate(newCap);
			size_type i = 0;
			_allocator.construct(temp, value_type());
			for (; i < size(); i++)
				temp[i] = _data[i];
			// _allocator.construct(&temp[i], _data[i]);
			if (_data)
			{
				_allocator.destroy(_data);
				_allocator.deallocate(_data, capacity());
			}
			_capacity = newCap;
			_data = temp;	
		}
		_data[size()] = val;
		_size++;
	}
	void pop_back()
	{
		_size--;
	}
	iterator insert (iterator position, const value_type& val)
	{
		if (size() < capacity())
		{
			iterator it = begin();
			for (;it != position; ++it){}
			iterator save = it;
			iterator temp = end();		
			for (;temp != (save -1); --temp)
				*(temp+1)=*temp;
			*save = val;
			_size++;
			return save;
		}
		size_type newCap;
		if (!capacity())
			newCap = 1;
		else
			newCap = capacity() * 2;		
		pointer temp;
		temp = _allocator.allocate(newCap);
		_allocator.construct(temp, value_type());
		size_type i = 0;
		size_type k = 0;
		iterator it = begin();
		iterator save;
		for (; it != position; ++it, ++i, ++k)
			temp[k] = _data[i];
		temp[k] = val;
		save = &(temp[k]);
		k++;
		for (; it != end(); ++it, ++i, ++k)
			temp[k] = _data[i];		
		_allocator.deallocate(_data, capacity());
		_allocator.destroy(_data);
		_capacity = newCap;
		_data = temp;
		_size++;
		return save;
	}
	void insert (iterator position, size_type n, const value_type& val)
	{
		if ((size() + n) <= capacity())
		{
			iterator it = begin();
			for (;it != position; ++it){}
			iterator save = it;
			iterator temp = end();
			
			for (;temp != (save - n); --temp)
				*(temp + n)=*temp;
			for (size_type i = 0;i < n; ++i)
			{
				*it = val;
				it++;
			}
			_size+=n;
			return ;
		}
		size_type newCap;
		if (!capacity())
			newCap = n;
		else if (capacity() < n)
			newCap = n + size();
		else
			newCap = capacity() * 2;
		pointer temp;
		temp = _allocator.allocate(newCap);
		_allocator.construct(temp, value_type());
		size_type i = 0;
		size_type k = 0;
		iterator it = begin();
		for (; it != position; ++it, ++i, ++k)
			temp[k] = _data[i];
		for (size_type i = 0; i  < n; ++i, ++k)
			temp[k] = val;
		for (; it != end(); ++it, ++i, ++k)
			temp[k] = _data[i];		
		_allocator.deallocate(_data, capacity());
		_allocator.destroy(_data);
		_capacity = newCap;
		_data = temp;
		_size+=n;
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::EnableIfFalse<ft::IsIntegral<InputIterator>::value , T>::type = 0,
				typename ft::EnableIfFalse<ft::IsFloatingPoint<InputIterator>::value , T>::type = 0)
	{
		size_t len = 0;
		for (InputIterator temp = first; temp != last; temp++) 
			len++;
		if ((size() + len) <= capacity())
		{
			iterator it = begin();
			for (;it != position; ++it){}
			iterator save = it;
			iterator temp = end();		
			for (;temp != (save - len); --temp)
				*(temp + len)=*temp;
			for (size_type i = 0;i < len; ++i)
			{
				*it = *first;
				first++;
			}
			_size+=len;
			return ;
		}
		size_type newCap;
		if (!capacity())
			newCap = len;
		else if (capacity() < len)
			newCap = len + size();
		else
			newCap = capacity() * 2;
		pointer temp;
		temp = _allocator.allocate(newCap);
		_allocator.construct(temp, value_type());
		size_type i = 0;
		size_type k = 0;
		iterator it = begin();
		for (; it != position; ++it, ++i, ++k)
			temp[k] = _data[i];
		for (size_type i = 0; i  < len; ++i, ++k, first++)
			temp[k] = *first;
		for (; it != end(); ++it, ++i, ++k)
			temp[k] = _data[i];		
		_allocator.deallocate(_data, capacity());
		_allocator.destroy(_data);
		_capacity = newCap;
		_data = temp;
		_size+=len;	
	}
	iterator erase (iterator position)
	{
		iterator it;
		iterator save;
		for (it = begin(); it != position; ++it){}
		save = it;
		for (; it != end() - 1; ++it)
			*it = *(it + 1);
		_size--;
		return save;
	}
	iterator erase (iterator first, iterator last)
	{
		iterator it;
		iterator save;
		size_type n = last - first;
		for (it = begin(); it != first; ++it){}
		save = it;
		iterator it2 = it;
		for (; it2 != last; ++it2){}
		for (; it2 != end() + n; ++it2, ++it)
			*it = *(it2);
		_size -= n;
		return save;				
	}
	void swap (vector& x)
	{
		pointer temp = _data;
		size_type size = _size;
		size_type capacity = _capacity;
		_data = x._data;
		_size = x._size;
		_capacity = x._capacity;
		x._data = temp;
		x._size = size;
		x._capacity = capacity;
	}
	void clear()
	{
		_size = 0;
	}
	/*ALLOCATOR-----------------------------------------------------------------------------------*/
	allocator_type get_allocator() const
	{
		return _allocator;
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
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template <class T, class A>
bool operator!= (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return !(lhs == rhs);
}
template <class T, class A>
bool operator< (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return ft::lexicographical_compare<typename ft::vector<T,A>::const_iterator, typename ft::vector<T,A>::const_iterator>
	(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class T, class A>
bool operator<= (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return ((lhs == rhs) || (lhs < rhs));
}
template <class T, class A>
bool operator> (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return !(lhs<=rhs);
}
template <class T, class A>
bool operator>= (const ft::vector<T,A>& lhs, const ft::vector<T,A>& rhs)
{
	return ((lhs == rhs) || (lhs > rhs));
}
#endif