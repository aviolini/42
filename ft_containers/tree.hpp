/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/23 11:02:37 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
#define TREE_H

#include "./utils.hpp"

namespace ft
{
template <class _Tp>
class treeIterator
{
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
		_ptr = rhs._ptr;
		return *this;		
	}
/*MEMBER OPERATORS--------------------------------------------------*/
	pointer operator -> ()
	{
		return _ptr;
	}
	reference operator *()
	{
		return *_ptr;
	}
	treeIterator &operator ++()			//PREFIX
	{
		if (_ptr->_right != 0)
		{
			_ptr = _ptr->_right;
			while (_ptr->_left != 0)
				_ptr = _ptr->_left;
			return *this;		
		}
		// while (_ptr->_parent && _ptr != _ptr->_parent->_left)
		while ( _ptr != _ptr->_parent->_left)
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
	treeIterator &operator --()			//PREFIX
	{
		if (_ptr->_left != 0)
		{
			_ptr = _ptr->_left;
			while (_ptr->_right != 0)
				_ptr = _ptr->_right;
			return *this;		
		}
		// while (_ptr->_parent && _ptr != _ptr->_parent->_left)
		// while ( _ptr == _ptr->_parent->_left)
		// 	_ptr = _ptr->_parent;
		_ptr = _ptr->_parent;
		return *this;
	}
	treeIterator operator --(int)			//POSTFIX
	{
		treeIterator t;
		--(*this);
		return t;
	}
/*RELATIONAL OPERATORS--------------------------------------------------*/
	bool operator == (const treeIterator & rhs)
	{
		return (_ptr == rhs._ptr);
	}
	bool operator != (const treeIterator & rhs)
	{
		return !(_ptr == rhs._ptr);
	}
};

template < class Pair >
struct node
{
	typedef Pair Pair_type;
	node() :  _value(), _parent(0), _left(0), _right(0) {}
	node(const Pair & obj) : _value(obj), _parent(0), _left(0), _right(0){}
	~node(){}
	Pair		_value;
	node		*_parent;
	node 		*_left;
	node 		*_right;
};

template < class Pair, class Compare = std::less<typename Pair::first_type>, class Alloc = std::allocator<Pair> >
class tree
{
public:
	typedef Alloc										pair_allocator;
	typedef Compare										key_compare;
	typedef std::allocator<node<Pair> >					allocator_type;
	typedef typename allocator_type::value_type			value_type;
    typedef typename allocator_type::size_type		    size_type;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::difference_type	difference_type;
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
	typedef treeIterator<value_type>					const_iterator;
	typedef treeIterator<value_type>					iterator;
	// typedef	vecReverse_iterator<const_iterator>		const_reverse_iterator;
	// typedef	vecReverse_iterator<iterator>			reverse_iterator;

	// class value_compare
	// {
	//   friend class tree;
	// protected:
	//   Compare comp;
	//   value_compare (Compare c) : comp(c) {}
	// public:
	//   typedef bool			result_type;
	//   typedef value_type	first_argument_type;
	//   typedef value_type	second_argument_type;
	//   result_type operator() (const value_type& x, const value_type& y) const
	//   {
	//     return comp(x.first, y.first);
	//   }
	// };
private:
	key_compare		_compare;
	pair_allocator	_pair_allocator;
	allocator_type	_node_allocator;
	pointer			_root;
	pointer			_end;
	pointer			_begin;
	size_type		_size;
public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit tree (const key_compare& comp = key_compare(), const pair_allocator& alloc = pair_allocator())
	:_compare(comp), _pair_allocator(alloc), _node_allocator(allocator_type())
	{
		// _end = _node_allocator.allocate(1);
		_end = new value_type;
		_begin = new value_type;
		_root = _end;
		this->_size = 0;
	}
	tree (const tree& x)
	:_compare(x._compare), _pair_allocator(x._pair_allocator), _node_allocator(x._node_allocator)
	{
		_end = new value_type;
		_begin = new value_type;
		_root = _end;
		this->_size = 0;
		iterator it = x.begin();			//FARLO PARTIRE DA ROOT OPPURE COSI E BILANCIARLO DOPO?
		it++;
		for (; it != x.end(); ++it)
			insert(it->_value);
	}																															//COPY
	tree& operator= (const tree& x)
	{
    	if (this != &x)
    	{
			// if (_root == _end)
			// {
	    	//     //CANCELLA TUTTO QUELLO CHE C'ERA PRIMA
			// }
			destroy_tree();
			_compare = x._compare;
			_pair_allocator = x._pair_allocator;
			_node_allocator = x._node_allocator;
			
			_end = new value_type;
			_begin = new value_type;
			_root = _end;
			this->_size = 0;
			iterator it = x.begin();			//FARLO PARTIRE DA ROOT OPPURE COSI E BILANCIARLO DOPO?
			it++;
			for (; it != x.end(); ++it)
				insert(it->_value);
    	}
    	return *this;
	}
	~tree(){}

/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		// pointer temp = _root;
		// while (temp->_left != 0)
		// 	temp = temp->_left;
		// return iterator(temp);
		return iterator(_begin);
	}
	iterator end()
	{
		// pointer temp = _root;
		// while (temp->_right != 0)
		// 	temp = temp->_right;
		// return iterator(temp->_right);
		return iterator(_end);
	}
	const_iterator begin() const
	{
		// pointer temp = _root;
		// while (temp->_left != 0)
		// 	temp = temp->_left;
		// return const_iterator(temp);
		return const_iterator(_begin);
	}
	const_iterator end() const
	{
		// pointer temp = _root;
		// while (temp->_right != 0)
		// 	temp = temp->_right;
		// return const_iterator(temp->_right);
		return const_iterator(_end);
	}

/*METHODS-----------------------------------------------------------------------------------*/
	size_type size() const
	{
		return _size;
	}
	size_type max_size() const
	{
		return _pair_allocator.max_size();
	}
	iterator insert(const Pair &obj)
	{
		_root = (insert(0, _root, obj));
		return iterator(_root);
	}
	pointer insert ( pointer parent, pointer node, const Pair & obj)
	{
		if (parent == 0 && node == _end)				// PRIMO GIRO
		{
		 	pointer temp = new value_type(obj);
		 	temp->_left = _begin;
		 	temp->_right = _end;
			_end->_parent = temp;
			_begin->_parent = temp;
			temp->_parent = 0;
			_size++;
			return temp;			
		}
		if (node == _begin)								//SE ARRIVA AL NODO CON VALUE MINORE
		{
		 	pointer temp = new value_type(obj);
		 	temp->_left = _begin;
		 	temp->_right = 0;
			_begin->_parent = temp;
			temp->_parent = parent;
			_size++;
			return temp;
		}	
		if (node == _end)								//SE ARRIVA AL NODO CON VALUE MAGGIORE
		{
		 	pointer temp = new value_type(obj);
		 	temp->_left = 0;
		 	temp->_right = _end;
			_end->_parent = temp;
			temp->_parent = parent;
			_size++;
			return temp;
		}		
		if ( node == 0 )								//SE ARRIVA ALLA FINE DI UN SUBTREE
		{
		 	pointer temp = new value_type(obj);
		 	temp->_left = 0;
		 	temp->_right = 0;
			// if (parent == 0)
			// 	temp->_parent = temp;
			// else 
				temp->_parent = parent;
			_size++;
		 	return temp;
		}
		if( _compare(obj.first,node->_value.first))
		 	node->_left = insert(node, node->_left, obj );
		else
		 	node->_right = insert(node, node->_right, obj );
		return node;
	}
	iterator find(typename Pair::first_type & k)
	{
		return iterator(find(_root,k));
	}
	pointer find(pointer node, typename Pair::first_type  & k)
	{
		if (node == 0)
			return _end;				//SERVE AL FIND DEL MAP
		if (k == node->_value.first)
			return node;
		if( _compare(k,node->_value.first))
			return find(node->_left, k);
		return find(node->_right, k);
	}
	void destroy_tree()
	{
		destroy_tree(_root);
		delete _end;
		delete _begin;
	}
	void destroy_tree(pointer node)
	{
		if (node != 0 && node != _end && node != _begin)
		{
			destroy_tree(node->_left);
			destroy_tree(node->_right);
			delete node;
		}
	}
	void remove(typename Pair::first_type  & k)
	{
		pointer temp = find(_root, k);
		std::cout << "TEMP: " << temp->_value.first << std::endl;
	}
};
};

#endif
