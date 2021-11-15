/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:25:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/15 10:48:17 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "./utils.hpp"
#include "./tree.hpp"
#include "./mapIterators.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key,T> > > 
class map
{
public:
	typedef Key												key_type;		//THE TYPE OF THE KEY
	typedef T												mapped_type;	//THE TYPE OF THE VALUES
	typedef ft::pair<key_type,mapped_type>					value_type;	
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;
	typedef ft::node<value_type, key_compare>				node_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
    typedef typename allocator_type::difference_type		difference_type;
    typedef typename allocator_type::size_type		   		size_type;
	typedef mapIterator<ft::treeIterator<node_type> >		const_iterator;
	typedef mapIterator<ft::treeIterator<node_type> >		iterator;
	typedef mapReverse_iterator<const_iterator> 			const_reverse_iterator;
	typedef mapReverse_iterator<iterator> 					reverse_iterator;
	
	class value_compare
	{
	  friend class map;
	protected:
	  Compare comp;
	  value_compare (Compare c) : comp(c) {}
	public:
	  typedef bool											result_type;
	  typedef value_type									first_argument_type;
	  typedef value_type									second_argument_type;
	  bool operator() (const value_type& x, const value_type& y) const
	  {
	    return comp(x.first, y.first);
	  }
	};
	
private:
	allocator_type											_allocator;
	tree<value_type> 										_tree;

public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
	_allocator(alloc){
		(void)comp;
	// value_compare(comp); 
	}									//EMPTY
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),		//RANGE
		typename myEnable_if_false<myIs_integral<InputIterator>::value , T>::type = 0,
		typename myEnable_if_false<myIs_floating_point<InputIterator>::value , T>::type = 0)
	: _allocator(alloc), value_compare(comp)
	{
		(void)first;
		(void)last;
	}
	map (const map& x)
	{
		(void)x;
	}																															//COPY
	~map(){}
	map& operator= (const map& x)
	{
		(void)x;
	}
/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		return _tree.begin();
	}
	const_iterator begin() const
	{
		return _tree.begin();
	}
    iterator end()
	{
		return _tree.end();
	}
	const_iterator end() const
	{
		return _tree.end();
	}
    reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
    reverse_iterator rend();
	const_reverse_iterator rend() const;
/*CAPACITY-----------------------------------------------------------------------------------*/
	// bool empty() const;
	// size_type size() const;
	// size_type max_size() const;
	// /*ELEMENT ACCESS-------------------------------------------------------------------------------*/
	// mapped_type& operator[] (const key_type& k);
	// /*MODIFIERS-----------------------------------------------------------------------------------*/
	// pair<iterator,bool> insert (const value_type& val)								//SINGLE ELEMENT
	void insert (value_type& val)								//SINGLE ELEMENT
	{
		_tree.addnode(val);
		return ;
	}
	// iterator insert (iterator position, const value_type& val);						//WITH HINT
	// template <class InputIterator>													//RANGE
	// void insert (InputIterator first, InputIterator last);
	// void erase (iterator position);
	// size_type erase (const key_type& k);
	// void erase (iterator first, iterator last);
	// void swap (map& x);
	// void clear();
/*OBSERVERS----------------------------------------------------------------------------------*/
// /*	key_compare key_comp() const
// 	{
// 		return __tree_.value_comp().key_comp();
// 	}
// 	value_compare value_comp() const
// 	{
// 		return value_compare(__tree_.value_comp().key_comp())
// 	}
// */
/*OPERATIONS----------------------------------------------------------------------------------*/
    // iterator find (const key_type& k);
	// const_iterator find (const key_type& k) const;
	// size_type count (const key_type& k) const;
    // iterator lower_bound (const key_type& k);
	// const_iterator lower_bound (const key_type& k) const;
	// iterator upper_bound (const key_type& k);
	// const_iterator upper_bound (const key_type& k) const;
	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	// pair<iterator,iterator>             equal_range (const key_type& k);
/*ALLOCATOR-----------------------------------------------------------------------------------*/
/*	allocator_type get_allocator() const 
// 	{
// 		return allocator_type(__tree_.__alloc());
// 	}
*/
	
};
};

#endif