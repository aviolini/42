/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/15 11:41:26 by aviolini         ###   ########.fr       */
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
    typedef ft::ptrdiff_t					difference_type;
private:
    pointer _ptr;
public:
	treeIterator() : _ptr(0){}
	treeIterator (pointer initLoc) : _ptr(initLoc){}
	~treeIterator(){}
	treeIterator(treeIterator const & rhs) : _ptr(rhs._ptr) {}
	treeIterator operator = (const treeIterator & rhs)
	{
		this->_ptr = rhs._ptr;
		return *this;		
	}
	/*MEMBER OPERATORS--------------------------------------------------*/
	reference operator *()
	{
		return *this->_ptr;
	}
	treeIterator operator + ( const difference_type &n ) const;
	treeIterator &operator ++()			//PREFIX
	{
		if (this->_ptr->_right != 0)
		{
			this->_ptr = this->_ptr->_right;
			while (this->_ptr->_left != 0)
				this->_ptr = this->_ptr->_left;
			return *this;		
		}
		while (_ptr == _ptr->_parent->_left)
			_ptr = _ptr->_parent;
		return *this;
	}
	treeIterator operator ++(int)			//POSTFIX
	{
		treeIterator t;
		++(*this);
		return t;
	}
	treeIterator & operator += (difference_type n);
	treeIterator operator - ( const difference_type &n ) const;
	difference_type operator - ( const treeIterator &rhs) const;
	treeIterator &operator --()		;		//PREFIX
	treeIterator operator --(int)	;			//POSTFIX
	treeIterator & operator -= (difference_type n);
	pointer operator -> ();
	reference operator [] (int index);
	/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator == (const treeIterator & rhs)
	{
		return (this->_ptr == rhs._ptr);
	}
	bool operator != (const treeIterator & rhs)
	{
		return !(this->_ptr == rhs._ptr);
	}
	bool operator > (const treeIterator & rhs);
	bool operator >= (const treeIterator & rhs);
	bool operator < (const treeIterator & rhs);
	bool operator <= (const treeIterator & rhs);
};

template < class Pair,class Compare = std::less<typename Pair::first_type> >
class node : public ft::pair<typename Pair::first_type,typename Pair::second_type>
{
public:
	node() : ft::pair<typename Pair::first_type, typename Pair::second_type>(), _parent(0), _left(0), _right(0) {}
	node(Pair & obj) : ft::pair<typename Pair::first_type, typename Pair::second_type>(obj), _parent(0), _left(0), _right(0) {}
	~node(){}
// private:
	node		*_parent;
	node 		*_left;
	node 		*_right;
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
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
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
	void addnode(Pair &obj)
	{
		this->_root = insert(_root, obj);
	}
	pointer insert (pointer p_tree, Pair & obj)
	{
		if ( p_tree == 0 )
		{
		 	pointer p_new_tree = new value_type;
		 	p_new_tree->_left = 0;
		 	p_new_tree->_right = 0;
		 	p_new_tree->first = obj.first;
		 	p_new_tree->second = obj.second;
		 	return p_new_tree;
		}
		if( obj.first < p_tree->first )
		 	p_tree->_left = insert( p_tree->_left, obj );
		else
		 	p_tree->_right = insert( p_tree->_right, obj );
		return p_tree;
	}
};
};

#endif
