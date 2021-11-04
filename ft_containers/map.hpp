/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:25:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/04 14:47:11 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "./utils.hpp"
#include "./mapIterators.hpp"


namespace ft
{	
template <class T1, class T2>
struct pair
{
public:
	typedef T1		first_type;
	typedef T2		second_type;
	first_type		first;
	second_type 	second;

	pair() : first(0), second(0) {}													//DEFAULT
	template<class U, class V> 														//COPY
	pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
	pair (const first_type& a, const second_type& b) : first(a), second(b) {}		//INIZIALIZATION
	pair& operator= (const pair& pr)
	{
		this->first = pr.first;
		this->second = pr.second;
		return *this;
	}
	~pair() {}
};
};
template <class T1, class T2>
bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs.first == rhs.first && lhs.second == rhs.second;
}
template <class T1, class T2>
bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs != rhs;
}
template <class T1, class T2>
bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}
template <class T1, class T2>
bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return !(rhs < lhs);
}
template <class T1, class T2>
bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return rhs < lhs;
}
template <class T1, class T2>
bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return !(lhs < rhs);
}
///////////////////////////////////////////////////////////////////////////////
namespace ft
{
template <class T1, class T2>
ft::pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( ft::pair<T1,T2>(x,y) );
};
};
/////////////////////////////////////////////////////////////////////////////////

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key,T> > >
class node
{
public:
	typedef ft::pair<Key, T> 	Pair;
	node() : _l(0), _r(0) {}
	node(Pair & obj) : _content(obj), _l(0), _r(0) {}
	~node(){}
// private:
	Pair _content;
	node *_l;
	node *_r;
};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key,T> > >
class tree
{
public:
	typedef ft::pair<Key, T> 	Pair;
	tree() : _b(0){}
	~tree(){}
private:
	node<Key,T> *_b;
public:
	void addnode(Pair & obj)
	{
		if (!_b)
		{
			_b = new node<Key,T>(obj);
			std::cout << "EMPTY" << std::endl;
			return ;
		}
		std::cout << " NOT EMPTY" << std::endl;
	}
};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key,T> > > 
class map
{
public:
	typedef Key													key_type;		//THE TYPE OF THE KEY
	typedef T													mapped_type;	//THE TYPE OF THE VALUES
	typedef ft::pair<const key_type,mapped_type>				value_type;	
	typedef Compare												key_compare;
	typedef Alloc												allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
    typedef typename allocator_type::difference_type			difference_type;
    typedef typename allocator_type::size_type		   			size_type;
	typedef mapIterator< myBidirectional_iterator_tag, T > 		const_iterator;
	typedef mapIterator< myBidirectional_iterator_tag, T > 		iterator;
	typedef mapReverse_iterator<const_iterator> 				const_reverse_iterator;
	typedef mapReverse_iterator<iterator> 						reverse_iterator;
	
	class value_compare
	{
	  friend class map;
	protected:
	  Compare comp;
	  value_compare (Compare c) : comp(c) {}
	public:
	  typedef bool result_type;
	  typedef value_type first_argument_type;
	  typedef value_type second_argument_type;
	  bool operator() (const value_type& x, const value_type& y) const
	  {
	    return comp(x.first, y.first);
	  }
	};
	
private:
	allocator_type	_allocator;

// private:
//     typedef _VSTD::__value_type<key_type, mapped_type>             									__value_type;
//     typedef __map_value_compare<key_type, __value_type, key_compare> 								__vc;
//     typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>, __value_type>::type 	__allocator_type;
//     typedef __tree<__value_type, __vc, __allocator_type>            								__base;
//     typedef typename __base::__node_traits                          								__node_traits;
//     typedef allocator_traits<allocator_type>                        								__alloc_traits;
//     __base __tree_;

// public:
//     typedef typename __alloc_traits::pointer         				pointer;
//     typedef typename __alloc_traits::const_pointer   				const_pointer;
//     typedef typename __alloc_traits::size_type       				size_type;
//     typedef typename __alloc_traits::difference_type 				difference_type;
//     typedef __map_iterator<typename __base::iterator>				iterator;
//     typedef __map_const_iterator<typename __base::const_iterator> 	const_iterator;
//     typedef _VSTD::reverse_iterator<iterator>               		reverse_iterator;
//     typedef _VSTD::reverse_iterator<const_iterator>         		const_reverse_iterator;

public:
	/*CANONICAL-----------------------------------------------------------------------------------*/
	// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());										//EMPTY
	// template <class InputIterator>
	// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());		//RANGE
	// map (const map& x);																															//COPY
	// ~map();
	// map& operator= (const map& x);
	// /*ITERATORS-----------------------------------------------------------------------------------*/
	// iterator begin();
	// const_iterator begin() const;
    // iterator end();
	// const_iterator end() const;
    // reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
    // reverse_iterator rend();
	// const_reverse_iterator rend() const;
	// /*CAPACITY-----------------------------------------------------------------------------------*/
	// bool empty() const;
	// size_type size() const;
	// size_type max_size() const;
	// /*ELEMENT ACCESS-------------------------------------------------------------------------------*/
	// mapped_type& operator[] (const key_type& k);
	// /*MODIFIERS-----------------------------------------------------------------------------------*/
	// pair<iterator,bool> insert (const value_type& val);								//SINGLE ELEMENT
	// iterator insert (iterator position, const value_type& val);						//WITH HINT
	// template <class InputIterator>													//RANGE
	// void insert (InputIterator first, InputIterator last);
	// void erase (iterator position);
	// size_type erase (const key_type& k);
	// void erase (iterator first, iterator last);
	// void swap (map& x);
	// void clear();
	///*OBSERVERS----------------------------------------------------------------------------------*/
// /*	key_compare key_comp() const
// 	{
// 		return __tree_.value_comp().key_comp();
// 	}
// 	value_compare value_comp() const
// 	{
// 		return value_compare(__tree_.value_comp().key_comp())
// 	}
// */
	// /*OPERATIONS----------------------------------------------------------------------------------*/
    // iterator find (const key_type& k);
	// const_iterator find (const key_type& k) const;
	// size_type count (const key_type& k) const;
    // iterator lower_bound (const key_type& k);
	// const_iterator lower_bound (const key_type& k) const;
	// iterator upper_bound (const key_type& k);
	// const_iterator upper_bound (const key_type& k) const;
	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	// pair<iterator,iterator>             equal_range (const key_type& k);
	// /*ALLOCATOR-----------------------------------------------------------------------------------*/
// /*	allocator_type get_allocator() const 
// 	{
// 		return allocator_type(__tree_.__alloc());
// 	}
// */
	
};
};

#endif