/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/07 11:55:30 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
#define TREE_H

#include "./utils.hpp"
#include "./mapIterators.hpp"

namespace ft
{
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
	int 		empty_var;						///TO DECREMENT SIZE FOR MAX_SIZE() TEST
};

template <class tree>
class treeIterator : public mapIterator<tree>
{
public:
	typedef mapIterator<tree>						mapIterator;
	typedef typename mapIterator::iterator_category	iterator_category;
	typedef typename mapIterator::value_type		value_type;
	typedef typename mapIterator::pointer			pointer;
	typedef typename mapIterator::reference			reference;
	typedef typename mapIterator::difference_type	difference_type;
	typedef typename mapIterator::Pair				Pair;
	treeIterator () : mapIterator(0) {}
	treeIterator (pointer initLoc) : mapIterator(initLoc) {}
	~treeIterator(){}
	treeIterator(treeIterator const & rhs) : mapIterator(rhs._ptr) {}
	treeIterator operator = (const treeIterator & rhs)
	{
		this->_ptr = rhs._ptr;
		return *this;
	}
	pointer operator -> () const
	{
		return this->_ptr;
	}
	reference operator *() const
	{
		return *this->_ptr;
	}
};

template < class P, class Compare = std::less<typename P::first_type>, class Alloc = std::allocator<P> >
class tree
{
public:
	typedef Alloc										pair_allocator;
	typedef Compare										key_compare;
	typedef std::allocator<node<P> >					node_allocator;
	typedef typename node_allocator::value_type			value_type;
    typedef typename node_allocator::size_type		    size_type;
    typedef typename node_allocator::reference			reference;
    typedef typename node_allocator::const_reference	const_reference;
    typedef typename node_allocator::difference_type	difference_type;
    typedef typename node_allocator::pointer			pointer;
    typedef typename node_allocator::const_pointer		const_pointer;
	typedef treeIterator<tree>							const_iterator;
	typedef treeIterator<tree>							iterator;
	typedef P 											Pair;
	typedef typename P::first_type								PairFirst_type;
	typedef typename P::second_type								PairSecond_type;

	
	key_compare		key_comp;
private:
	pair_allocator	_pair_allocator;
	pointer			_root;
	pointer			_end;
	pointer			_begin;
	size_type		_size;
public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit tree (const key_compare& key_comp = key_compare(), const pair_allocator& alloc = pair_allocator())
	:key_comp(key_comp), _pair_allocator(alloc)
	{
		_end = node_allocator().allocate(1);
		node_allocator().construct(_end, ft::make_pair<PairFirst_type, PairSecond_type>(PairFirst_type(), PairSecond_type()));
		_begin = node_allocator().allocate(1);
		node_allocator().construct(_begin, ft::make_pair<PairFirst_type, PairSecond_type>(PairFirst_type(), PairSecond_type()));
		_root = _end;
		this->_size = 0;
	}
	tree (const tree& x)
	:key_comp(x.key_comp),  _pair_allocator(x._pair_allocator)
	{
		_end = node_allocator().allocate(1);
		node_allocator().construct(_end, ft::make_pair<PairFirst_type, PairSecond_type>(PairFirst_type(), PairSecond_type()));
		_begin = node_allocator().allocate(1);
		node_allocator().construct(_begin, ft::make_pair<PairFirst_type, PairSecond_type>(PairFirst_type(), PairSecond_type()));
		_root = _end;
		this->_size = 0;
		iterator it = x.begin();
		// it++;
		for (; it != x.end(); ++it)
			insert(it->_value);
	}																															//COPY
	tree& operator= (const tree& x)
	{
    	if (this != &x)
    	{
			clear();
			key_comp = x.key_comp;
			_pair_allocator = x._pair_allocator;
			iterator it = x.begin();
			// it++;
			for (; it != x.end(); ++it)
				insert(it->_value);
    	}
    	return *this;
	}
	~tree()
	{
		destroy_tree();
	}
/*ITERATORS-----------------------------------------------------------------------------------*/
	iterator begin()
	{
		return iterator(find_min(_root));
	}
	iterator end()
	{
		return iterator(_end);
	}
	const_iterator begin() const
	{
		return const_iterator(find_min(_root));
	}
	const_iterator end() const
	{
		return const_iterator(_end);
	}
/*METHODS-----------------------------------------------------------------------------------*/
	size_type size() const
	{
		return _size;
	}
	/////////////////////////////////////////////////////////////////////
	//INSERT
	//jumping into c++ - Alex Allain - CAP17
	/////////////////////////////////////////////////////////////////////
	iterator insert(const Pair &obj)
	{
		_root = (insert(0, _root, obj));
		return iterator(_root);
	}
	pointer insert ( pointer parent, pointer node, const Pair & obj)
	{
		if (parent == 0 && node == _end)
		{
			pointer temp = node_allocator().allocate(1);
			node_allocator().construct(temp, obj);
		 	temp->_left = _begin;
		 	temp->_right = _end;
			_end->_parent = temp;
			_begin->_parent = temp;
			temp->_parent = 0;
			_size++;
			return temp;			
		}
		if (node == _begin)
		{
			pointer temp = node_allocator().allocate(1);
			node_allocator().construct(temp, obj);
		 	temp->_left = _begin;
		 	temp->_right = 0;
			_begin->_parent = temp;
			temp->_parent = parent;
			_size++;
			return temp;
		}	
		if (node == _end)
		{
			pointer temp = node_allocator().allocate(1);
			node_allocator().construct(temp, obj);
		 	temp->_left = 0;
		 	temp->_right = _end;
			_end->_parent = temp;
			temp->_parent = parent;
			_size++;
			return temp;
		}		
		if ( node == 0 )
		{
			pointer temp = node_allocator().allocate(1);
			node_allocator().construct(temp, obj);
		 	temp->_left = 0;
		 	temp->_right = 0;
			temp->_parent = parent;
			_size++;
		 	return temp;
		}
		if( key_compare()(obj.first,node->_value.first))
		 	node->_left = insert(node, node->_left, obj );
		else
		 	node->_right = insert(node, node->_right, obj );
		return node;
	}
	/////////////////////////////////////////////////////////////////////
	//SEARCH
	//jumping into c++ - Alex Allain - CAP17
	/////////////////////////////////////////////////////////////////////
	iterator find(const typename Pair::first_type & k) const
	{
		return iterator(find(_root,k));
	}
	pointer find(pointer node, const typename Pair::first_type  & k) const
	{
		if (node == 0)
			return _end;
		if (k == node->_value.first)
			return node;
		if( key_compare()(k,node->_value.first))
			return find(node->_left, k);
		return find(node->_right, k);
	}
	/////////////////////////////////////////////////////////////////////
	//DESTROY TREE
	//jumping into c++ - Alex Allain - CAP17
	/////////////////////////////////////////////////////////////////////
	void destroy_tree()
	{
		clear(_root);
		node_allocator().destroy(_end);
		node_allocator().deallocate(_end, 1);
		node_allocator().destroy(_begin);
		node_allocator().deallocate(_begin, 1);
		_end = 0;
		_begin = 0;
		_root = 0;
	}
	void clear()
	{
		clear(_root);
	}
	void clear(pointer node)
	{
		if (node != 0 && node != _end && node != _begin)
		{
			clear(node->_left);
			clear(node->_right);
			node_allocator().destroy(node);
			node_allocator().deallocate(node, 1);
			_size = 0;
			_root = _end;
		}
	}
	/////////////////////////////////////////////////////////////////////
	pointer find_max (pointer node) const 
	{
 		if (node == 0)
			return 0;
		if (node->_right == 0) 
			return node; 
		return find_max(node->_right); 
	}
	pointer find_min (pointer node) const
	{
 		if (node == 0)
			return 0;
		if (node->_left == 0 || node->_left == _begin) 
			return node;
		return find_min(node->_left); 
	}
	void remove(typename Pair::first_type  & k)
	{
		_root = remove(_root,k);
		if (_size == 0)
			_root = _end;
	}
	/////////////////////////////////////////////////////////////////////
	//REMOVE 
	//jumping into c++ - Alex Allain - CAP17
	/////////////////////////////////////////////////////////////////////
	pointer remove_max_node (pointer node, pointer max_node) 
	{
 		if (node == 0)
			return 0;
 		if (node == max_node)
 		{
			if (max_node->_left != 0)
				max_node->_left->_parent = max_node->_parent;
  			return max_node->_left;
		}
		node->_right = remove_max_node(node->_right, max_node);
		return node;
	}
	pointer remove (pointer node, int key)
	{
		if (node == 0)
			return 0;
		if (node->_value.first == key)
		{
			_size--;
			if ((node->_left == 0 && node->_right == 0) || _size == 0)	//NO CHILDREN
			{
				node_allocator().destroy(node);
				node_allocator().deallocate(node, 1);
				return 0;
			}
		  	if (node->_left == 0)										//RIGHT CHILD
			{
				pointer right_subtree = node->_right;
				right_subtree->_parent = node->_parent;
				node_allocator().destroy(node);
				node_allocator().deallocate(node, 1);
				return right_subtree;
			}
		  	if (node->_left == _begin)									//LEFT BEGIN
			{
				pointer right_subtree = node->_right;
				if (right_subtree)
				{
					right_subtree->_parent = node->_parent;
					pointer min_node = find_min(right_subtree);
					min_node->_left = _begin;
					_begin->_parent = min_node;
					node_allocator().destroy(node);
					node_allocator().deallocate(node, 1);
					return right_subtree;
				}
				_begin->_parent = node->_parent;
				node_allocator().destroy(node);
				node_allocator().deallocate(node, 1);
				return _begin;
			}
			if (node->_right == 0)										//LEFT CHILD
			{
				pointer left_subtree = node->_left;
				left_subtree->_parent = node->_parent;
				node_allocator().destroy(node);
				node_allocator().deallocate(node, 1);
				return left_subtree;
			}
		  	if (node->_right == _end)									//LEFT BEGIN
			{
				pointer left_subtree = node->_left;
				if (left_subtree)
				{
					left_subtree->_parent = node->_parent;
					pointer max_node = find_max(left_subtree);
					max_node->_right = _end;
					_end->_parent = max_node;
					node_allocator().destroy(node);
					node_allocator().deallocate(node, 1);
					return left_subtree;
				}
				_end->_parent = node->_parent;
				node_allocator().destroy(node);
				node_allocator().deallocate(node, 1);
				return _end;
			}
																		//LEFT AND RIGHT CHILDREN
			pointer max_node = find_max(node->_left);
			if (max_node == node->_left)										/*	 m	*/
			{																	/*	/\	*/
				node->_right->_parent = max_node;								/* d t	*/
				max_node->_right = node->_right;								/*remove m */
				max_node->_parent = node->_parent;
				node_allocator().destroy(node);
				node_allocator().deallocate(node, 1);
				return max_node;
			}
			max_node->_left = remove_max_node(node->_left, max_node);
			node->_left->_parent = max_node;
			max_node->_right = node->_right;
			node->_right->_parent = max_node;
			max_node->_parent = node->_parent;
			node_allocator().destroy(node);
			node_allocator().deallocate(node, 1);
			return max_node;
		}
		else if (key < node->_value.first)
			node->_left = remove(node->_left, key);
		else
			node->_right = remove(node->_right, key);
		return node;
	}
	void swap (tree &x)
	{
		pointer tempPointer = _root;
		pointer tempEnd = _end;
		pointer tempBegin = _begin;
		size_type tempSize = _size;
		_root = x._root;
		_end = x._end;
		_begin = x._begin;
		_size = x._size;
		x._root = tempPointer;
		x._end = tempEnd;
		x._begin = tempBegin;
		x._size = tempSize;
	}
	//PRINT TREE//////////////////////////////////////////////////////////////////////////////////////
	void print( std::string name)
	{
		std::cout << "-------------" << name << "-----------" << std::endl; 
		if (!_size)
			std::cout << "EMPTY TREE" << std::endl;
		else
		{
			std::cout << "\033[1;31mroot\033[0m" << std::endl;
			std::cout << "??? " << std::endl;
			print(_root, _root->_left, "", "");
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	void print(pointer node, pointer ref, std::string prefix, std::string str)
	{
		/////////////////////////////////////////////////PRINT LEFT SUBTREE
		if (node == ref)
		{
			std::cout << "??? " << std::endl;
			return print(ref, ref->_left, "", "");
		}
		/////////////////////////////////////////////////PRINT AND UPDATE STR PRINT FORMAT
		if (!prefix.compare("??????"))
		{
			std::cout << str;
			str = str + "??? ";
		}
		else if (!prefix.compare("??????"))
		{	
			std::cout << str;
			str = str + "  ";
		}
		else
			std::cout << str;
		/////////////////////////////////////////////////PRINT NEW PREFIX
		std::cout << prefix ;
		/////////////////////////////////////////////////REPRINT FORMAT TO INSERT VALUE IN RIGHT POSITION
		if (!prefix.compare("??? "))
			std::cout << std::endl << str;
		/////////////////////////////////////////////////PRINT NODE->VALUE
		if (node == _end)
			std::cout << "\033[1;33mend\033[0m" << std::endl;
		else if (node == _begin)
			std::cout << "\033[1;34mbegin\033[0m" << std::endl;
		else
			std::cout << "\033[1;32m" << node->_value.first << "\033[0m" << std::endl;
		/////////////////////////////////////////////////PRINT NEXT NODES
		if (node->_right && node->_left)
		{
			print(node->_right, ref, "??????", str);
			print(node->_left, ref, "", str);
		}
		else if (node->_right && !node->_left)
			print(node->_right, ref, "??????", str);
		else if (node->_left && !node->_right)
			print(node->_left, ref, "??? ", str);	
	}
};
};

#endif
