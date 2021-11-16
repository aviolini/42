/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/17 00:30:03 by arrigo           ###   ########.fr       */
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
		if (_ptr->_right != 0)
		{
			_ptr = _ptr->_right;
			while (_ptr->_left != 0)
				_ptr = _ptr->_left;
			return *this;		
		}
		while (!(_ptr == _ptr->_parent->_left))
			_ptr = _ptr->_parent;
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
	node() :  _value(), _parent(0), _left(0), _right(0) {}
	node(Pair & obj) : _parent(0), _left(0), _right(0)
	{
		this->_value.first = obj.first;
		this->_value.second = obj.second;
	}
	~node(){}
// private:
	Pair		_value;
	node		*_parent;
	node 		*_left;
	node 		*_right;
};

template < class Pair, class Compare = std::less<typename Pair::first_type>, class Alloc = std::allocator<node<Pair> > >
class tree
{
public:
	typedef Alloc										pair_allocator;
	typedef Compare										key_compare;
	typedef std::allocator<node<Pair> >					allocator_type;
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
	class value_compare
	{
	  friend class tree;
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
	key_compare			_compare;
	pair_allocator		_pair_allocator;
	allocator_type		_node_allocator;
	pointer				_root;
	pointer				_end;
public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit tree (const key_compare& comp = key_compare(), const pair_allocator& alloc = pair_allocator())
	:_compare(comp), _pair_allocator(alloc)
	{
		this->_end = this->_node_allocator.allocate(1);
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

		this->_root = insert(0, _root, obj);
	}
	pointer insert ( pointer parent, pointer node, Pair & obj)
	{		
		if ( node == 0 )
		{
			// std::cout << "2" << std::endl;
		 	pointer temp = new value_type;
		 	temp->_left = 0;
		 	temp->_right = 0;
			temp->_value.first = obj.first;
			temp->_value.second = obj.second;
			temp->_parent = parent;
		 	// temp->_value->first = obj.first;
		 	// temp->_value->second = obj.second;
		// std::cout << "AAH" << std::endl;
		 	return temp;
		}
		if( obj.first < node->_value.first )
		 	node->_left = insert(node, node->_left, obj );
		else
		 	node->_right = insert(node, node->_right, obj );
		return node;
	}
};
};

#endif
