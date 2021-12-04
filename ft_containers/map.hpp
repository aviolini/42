/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:25:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/04 01:25:01 by arrigo           ###   ########.fr       */
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
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
class map
{
public:
	typedef Key												key_type;		//THE TYPE OF THE KEY
	typedef T												mapped_type;	//THE TYPE OF THE VALUES
	typedef Alloc											allocator_type;
	typedef Compare											key_compare;
	typedef typename allocator_type::value_type				value_type;	
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
    typedef typename allocator_type::difference_type		difference_type;
    typedef typename allocator_type::size_type		   		size_type;
	typedef tree<value_type,key_compare,allocator_type> 	tree_type;
	// typedef typename tree_type::value_compare				value_compare;
	typedef ft::node<value_type>							node_type;
	typedef mapIterator<ft::treeIterator<node_type> >		const_iterator;
	typedef mapIterator<ft::treeIterator<node_type> >		iterator;
	typedef mapReverseIterator<const_iterator> 				const_reverse_iterator;
	typedef mapReverseIterator<iterator> 					reverse_iterator;
	class value_compare
	{
	//   friend class map;
	// protected:
	public:
	  Compare key_comp;
	  value_compare (Compare c) : key_comp(c) {}
	  ~value_compare(){}
	public:
	  typedef bool			result_type;
	  typedef value_type	first_argument_type;
	  typedef value_type	second_argument_type;
	  result_type operator() (const value_type& x, const value_type& y) const
	  {
	    return key_comp(x.first, y.first);
	  }
	};
// private:
	tree_type	_tree;

public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
	_tree(comp, alloc){}									//EMPTY
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())//,		//RANGE
		// typename EnableIfFalse<ft::IsIntegral<InputIterator>::value , T>::type = 0,
		// typename EnableIfFalse<ft::IsFloatingPoint<InputIterator>::value , T>::type = 0)
	:_tree(comp,alloc)
	{
		insert(first,last);
	}
	map (const map& x) : _tree(x._tree){}																															//COPY
	~map(){}
	map& operator= (const map& x)
	{
		_tree = x._tree;
		return *this;
	}
/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		return iterator(_tree.begin());
	}
	const_iterator begin() const
	{
		return const_iterator(_tree.begin());
	}
    iterator end()
	{
		return iterator(_tree.end());
	}
	const_iterator end() const
	{
		return const_iterator(_tree.end());
	}
    reverse_iterator rbegin()
	{
		return reverse_iterator(--iterator(_tree.end()));
	}
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(--const_iterator(_tree.end()));
	}
    reverse_iterator rend()
	{
		return reverse_iterator(--iterator(_tree.begin()));		
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(--const_iterator(_tree.begin()));
	}
/*CAPACITY-----------------------------------------------------------------------------------*/
	bool empty() const
	{
		if (!size())
			return true;
		return false;
	}
	size_type size() const
	{
		return _tree.size();
	}
	size_type max_size() const
	{
		// return allocator_type().max_size();
		return typename tree_type::node_allocator().max_size();
	}
/*ELEMENT ACCESS-------------------------------------------------------------------------------*/
	mapped_type& operator[] (const key_type& k)
	{
		iterator it = find(k);
		if (it != end())
			return it ->second;
		insert(ft::make_pair(k,mapped_type()));
		return find(k)->second;
		// return (--(insert(ft::make_pair(k,mapped_type())).first))->second;/////////////////FARE UN TEST
	}
/*MODIFIERS-----------------------------------------------------------------------------------*/
	pair<iterator,bool> insert (const value_type& val)								//SINGLE ELEMENT
	{
		iterator it = find(val.first);
		if (it != end()) //FOUND
			return pair<iterator,bool>(it, false);
		return pair<iterator,bool>(++(iterator(_tree.insert(val))), true);
	}
	iterator insert (iterator position, const value_type& val)						//WITH HINT
	{
		iterator it = find(val.first);
		if (it != end()) //FOUND
			return it;
		typename tree_type::pointer ptr;
		ptr = _tree.insert(position.getNode()->_parent, position.getNode(), val);
		it = iterator(typename tree_type::iterator(ptr));
			return it;
	}
	template <class InputIterator>													//RANGE
	void insert (InputIterator first, InputIterator last)
	{
		for (; first != last; ++first)
			insert(*first);
	}
	void erase (iterator position)
	{
		_tree.remove(position->first);
	}
	size_type erase (const key_type& k)
	{
		if (find(k) == end())
			return 0;
		_tree.remove(k);
		return 1;
	}
	void erase (iterator first, iterator last)
	{
		iterator temp = first;
		temp++;
		if (first != last)
		{
			erase(temp, last);
			_tree.remove(first->first);
		}
	}
	void swap (map& x)
	{
		map temp(x);
		x = *this;
		*this = temp;
	}
	void clear()
	{
		_tree.clear();
	}
/*OBSERVERS----------------------------------------------------------------------------------*/
	key_compare key_comp() const
	{
		return _tree.key_comp;
	}
	value_compare value_comp() const
	{
		return value_compare(key_compare());
	}
/*OPERATIONS----------------------------------------------------------------------------------*/
	iterator find (const key_type & k)
	{
		return iterator(_tree.find(k));
	}
	const_iterator find (const key_type& k) const
	{
		return const_iterator(_tree.find(k));
	}
	size_type count (const key_type& k) const
	{
		if (find(k) == end())
			return 0;
		return 1;
	}
    iterator lower_bound (const key_type& k)
	{
		return find(k);
	}
	const_iterator lower_bound (const key_type& k) const
	{
		return find(k);
	}
	iterator upper_bound (const key_type& k)
	{
		return ++find(k);
	}
	const_iterator upper_bound (const key_type& k) const
	{
		return ++find(k);		
	}
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return pair<const_iterator, const_iterator> (lower_bound(k), upper_bound(k));
	}
	pair<iterator,iterator> equal_range (const key_type& k)
	{
		return pair<iterator, iterator> (lower_bound(k), upper_bound(k));
	}
/*ALLOCATOR-----------------------------------------------------------------------------------*/
	allocator_type get_allocator() const 
	{
		return allocator_type();
	}
/*EXTRA-------------------------------------------------------------------------------------------------------------------------------*/
	void print(std::string name)
	{
		_tree.print(name);
	}
};
};

#endif