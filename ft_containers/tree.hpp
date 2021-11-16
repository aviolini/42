/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/16 16:26:58 by aviolini         ###   ########.fr       */
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
	typedef typename _Tp::Pair_type 		Pair;
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
	pointer operator -> ()
	{
		return this->_ptr;
	}
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

template < class Pair >
class node
{
public:
	typedef Pair Pair_type;
	node() : _parent(0), _left(0), _right(0), _value(0) {}
	node(Pair & obj) : _parent(0), _left(0), _right(0)
	{
		this->_value = new Pair(obj);
	}
	~node(){}
// private:
	node		*_parent;
	node 		*_left;
	node 		*_right;
	Pair		*_value;
};

template < class Pair, class Compare = std::less<typename Pair::first_type>  >
class tree
{
public:
	typedef std::allocator<node<Pair> >					Alloc;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::value_type			value_type;
    typedef typename allocator_type::size_type		    size_type;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference   const_reference;
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
	pointer			_end;
	difference_type	_size;
public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit tree (const allocator_type& alloc = allocator_type()) : _allocator(alloc)//, _root(0), _end(0), _size(0){}
	{
		this->_end = this->_allocator.allocate(1);
		// this->_root = this->_end;
		this->_size = 0;
		this->_root = 0;
	}
	~tree(){}
/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		pointer temp = this->_root;
		while (temp->_left != 0)
			temp = temp->_left;
		return iterator(temp);
	}
	iterator end()
	{
		pointer temp = this->_root;
		while (temp->_right != 0)
			temp = temp->_right;
		return iterator(temp->_right);
	}
	const_iterator begin() const
	{
		pointer temp = this->_root;
		while (temp->_left != 0)
			temp = temp->_left;
		return const_iterator(temp);
	}
	const_iterator end() const
	{
		pointer temp = this->_root;
		while (temp->_right != 0)
			temp = temp->_right;
		return const_iterator(temp->_right);
	}
/*METHODS-----------------------------------------------------------------------------------*/
	void addnode(Pair &obj)
	{

		this->_root = insert(_root, obj);
	}
	pointer insert (pointer root, Pair & obj)
	{
		if ( root == this->_end )
		{
			std::cout << "1" << std::endl;
		 	pointer temp = new value_type;
		 	temp->_left = 0;
		 	temp->_right = this->_end;
			temp->_value = new Pair(obj);
			// temp->_parent = parent;
		 	// temp->_value->first = obj.first;
		 	// temp->_value->second = obj.second;
		// std::cout << "AAH" << std::endl;
		 	return temp;
		}		
		if ( root == 0 )
		{
			std::cout << "2" << std::endl;
		 	pointer temp = new value_type;
		 	temp->_left = 0;
		 	temp->_right = 0;
			temp->_value = new Pair(obj);
			// temp->_parent = parent;
		 	// temp->_value->first = obj.first;
		 	// temp->_value->second = obj.second;
		// std::cout << "AAH" << std::endl;
		 	return temp;
		}
		if( obj.first < root->_value->first )
		 	root->_left = insert(root->_left, obj );
		else
		 	root->_right = insert(root->_right, obj );
		return root;
	}
};
};

#endif
