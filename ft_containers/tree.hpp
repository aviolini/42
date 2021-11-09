/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/09 12:52:41 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
#define TREE_H

#include "./utils.hpp"

namespace ft
{
// template <class _Tp, class _NodePtr, class _DiffType>
template <class _Tp>
class treeIterator
{
    // typedef __tree_node_types<_NodePtr>                     _NodeTypes;
    // typedef _NodePtr                                        __node_pointer;
    // typedef typename _NodeTypes::__node_base_pointer        __node_base_pointer;
    // typedef typename _NodeTypes::__end_node_pointer         __end_node_pointer;
    // typedef typename _NodeTypes::__iter_pointer             __iter_pointer;
    // typedef pointer_traits<__node_pointer> __pointer_traits;
public:
    typedef myBidirectional_iterator_tag	iterator_category;
    typedef _Tp                         	value_type;
	typedef value_type*						pointer;
	typedef value_type&						reference;
    // typedef _DiffType					difference_type;
private:
    pointer _data;
public:
	treeIterator() : _data(0){}
	treeIterator (pointer initLoc) : _data(initLoc){}
	~treeIterator(){}
	treeIterator(treeIterator const & rhs) : _data(rhs._data) {}
	treeIterator operator = (const treeIterator & rhs)
	{
		this->_data = rhs._data;
		return *this;		
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	reference operator *()
	{
		return *this->_data;
	}
};

template < class Pair,class Compare = std::less<typename Pair::first_type> >
class node : public ft::pair<typename Pair::first_type,typename Pair::second_type>
{
public:
	// typedef std::allocator<Pair>						Alloc;
	// typedef Pair										value_type;
	// typedef Alloc										allocator_type;
    // typedef typename allocator_type::size_type		    size_type;
    // typedef value_type&								    reference;
    // typedef const value_type&						    const_reference;
    // typedef typename allocator_type::difference_type	difference_type;
    // typedef typename allocator_type::pointer			pointer;
    // typedef typename allocator_type::const_pointer	    const_pointer;
	// typedef treeIterator<Pair>						const_iterator;
	// typedef treeIterator<Pair>						iterator;
	// typedef	vecReverse_iterator< const_iterator >	const_reverse_iterator;
	// typedef	vecReverse_iterator< iterator >			reverse_iterator;
public:
	node() : _l(0), _r(0), ft::pair<typename Pair::first_type,typename Pair::second_type>() {};
	node(Pair & obj) : ft::pair<typename Pair::first_type,typename Pair::second_type>(obj), _l(0), _r(0) {};
	~node(){}
private:
	node 		*_l;
	node 		*_r;
};

template < class Pair, class Compare = std::less<typename Pair::first_type>  >
class tree
{
public:
	typedef std::allocator<node<Pair> >					Alloc;
	typedef node<Pair>									value_type;
	typedef Alloc										allocator_type;
    typedef typename allocator_type::size_type		    size_type;
    typedef value_type&								    reference;
    typedef const value_type&						    const_reference;
    typedef typename allocator_type::difference_type	difference_type;
    // typedef value_type* 								pointer;
    typedef typename allocator_type::pointer			pointer;
    // typedef typename allocator_type::const_pointer	const_pointer;
	typedef treeIterator<node<Pair> >					const_iterator;
	typedef treeIterator<node<Pair> >					iterator;
	// typedef	vecReverse_iterator<const_iterator>		const_reverse_iterator;
	// typedef	vecReverse_iterator<iterator>			reverse_iterator;	
private:
	Alloc			_allocator;
	pointer			_root;
	pointer			_begin;
	pointer			_end;
	difference_type	_size;
public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	// tree() : _allocator(0),_root(0), _begin(0), _end(0), _size(0){}
	explicit tree (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _root(0), _begin(0), _end(0), _size(0){}
	~tree(){}
/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		return iterator(_begin);
	}
	iterator end()
	{
		return iterator(_end);
	}
	const_iterator begin() const
	{
		return const_iterator(_begin);
	}
	const_iterator end() const
	{
		return const_iterator(_end);	
	}
/*METHODS-----------------------------------------------------------------------------------*/
void addnode(ft::pair<typename Pair::first_type,typename Pair::second_type> &obj)
{
	if (!_begin)
	{
		_begin = this->_allocator.allocate(1);
		this->_begin->first = obj.first;
		this->_begin->second = obj.second;
		return;	
	}
}
};
};

#endif
