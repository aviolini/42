/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:25:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 16:27:49 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "utils.hpp"

namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > 
class map
{
public:
	typedef Key										key_type;
	typedef T										mapped_type;
	typedef std::pair<const key_type,mapped_type>	value_type;
	typedef Compare									key_compare;
	//value_compare					Nested function class to compare elements													see value_comp
	typedef Alloc									allocator_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	//iterator						a bidirectional iterator to value_type														convertible to const_iterator
	//const_iterator				a bidirectional iterator to const value_type	
	//reverse_iterator				reverse_iterator<iterator>	
	//const_reverse_iterator		reverse_iterator<const_iterator>	
	//difference_type				a signed integral type, identical to: iterator_traits<iterator>::difference_type			usually the same as ptrdiff_t
	//size_type						an unsigned integral type that can represent any non-negative value of difference_type		usually the same as size_t
private:

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
	// /*OBSERVERS----------------------------------------------------------------------------------*/
	// key_compare key_comp() const;
	// value_compare value_comp() const;
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
	// allocator_type get_allocator() const;
	
};
};

#endif