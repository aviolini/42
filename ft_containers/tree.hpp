/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:55:32 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/25 16:19:29 by aviolini         ###   ########.fr       */
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
	pointer getNode() const
	{
		return _ptr;	
	}
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


	key_compare		key_comp;
	// value_compare	value_comp;
private:
	pair_allocator	_pair_allocator;
	allocator_type	_node_allocator;
	pointer			_root;
	pointer			_end;
	pointer			_begin;
	size_type		_size;
public:
/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit tree (const key_compare& key_comp = key_compare(), const pair_allocator& alloc = pair_allocator())
	:key_comp(key_comp), _pair_allocator(alloc), _node_allocator(allocator_type())
	{
		// _end = _node_allocator.allocate(1);
		_end = new value_type;
		_begin = new value_type;
		_root = _end;
		this->_size = 0;
	}
	tree (const tree& x)
	:key_comp(x.key_comp),  _pair_allocator(x._pair_allocator), _node_allocator(x._node_allocator)
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
			// destroy_tree();
			clear();
			key_comp = x.key_comp;
			_pair_allocator = x._pair_allocator;
			_node_allocator = x._node_allocator;
			
			// _end = new value_type;
			// _begin = new value_type;
			// _root = _end;
			// this->_size = 0;
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
			// std::cout << "AAAA" <<std::endl;
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
		if( key_comp(obj.first,node->_value.first))
		 	node->_left = insert(node, node->_left, obj );
		else
		 	node->_right = insert(node, node->_right, obj );
		return node;
	}
	iterator find(const typename Pair::first_type & k) const
	{
		return iterator(find(_root,k));
	}
	pointer find(pointer node, const typename Pair::first_type  & k) const
	{
		if (node == 0)
			return _end;				//SERVE AL FIND DEL MAP
		if (k == node->_value.first)
			return node;
		if( key_comp(k,node->_value.first))
			return find(node->_left, k);
		return find(node->_right, k);
	}
	void destroy_tree()
	{
		clear(_root);
		delete _end;
		delete _begin;
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
			delete node;
			_size = 0;
			_root = _end;
		}
	}
	/////////////////////////////////////////////////////////////////////
	pointer find_max (pointer node) 
	{
 		if (node == 0)
			return 0;
		if (node->_right == 0) 
			return node; 
		return find_max(node->_right); 
	}
	pointer find_min (pointer node) 
	{
 		if (node == 0)
			return 0;
		if (node->_left == 0) 
			return node; 
		return find_min(node->_left); 
	}
	void remove(typename Pair::first_type  & k)
	{
		_root = remove(_root,k);
		// std::cout << "SIZE: " << _size << std::endl;
		if (_size == 0)
		_root = _end;
		// Delete(_root, k);
	}
	/////////////////////////////////////////////////////////////////////
	//REMOVE 
	//1. jumping into c++ - Alex Allain - PAG195
	//2. https://www.youtube.com/watch?v=gcULXE7ViZw    ->  https://gist.github.com/mycodeschool/9465a188248b624afdbf 
	// https://www.geeksforgeeks.org/deletion-binary-tree/?ref=lbp
	/////////////////////////////////////////////////////////////////////
	
	//1.////////////////////////////////////////////////////////////////
	pointer remove_max_node (pointer node, pointer max_node) 
	{
 		// defensive coding--shouldn't actually hit this 
 		if ( node == 0 )
			return 0;
 		// we found or node, now we can replace it 
 		if ( node == max_node ) 
 		{
  			// the only reason we can do this is because we know  
  			// max_node->_right is 0 so we aren’t losing  
  			// any information. If max_node has no left sub-tree,  
  			// then we will just return 0 from this branch, which  
  			// will result in max_node being replaced with an empty tree, 
  			// which is what we want.
			if (max_node->_left != 0)
				max_node->_left->_parent = max_node->_parent;
  			return max_node->_left;
		} 
		// each recursive call replaces the right sub-tree tree with a  
		// new sub-tree that does not contain max_node. 
		node->_right = remove_max_node( node->_right, max_node ); 
		return node; 
	}
	pointer remove (pointer node, int key)
	{
		if (node == 0)
			return 0;
		if (node->_value.first == key)
		{
			_size--;
			// the first two cases handle having zero or one child node
			if (_size == 0)	//SE E' L'ULTIMO ELEMENTO			<-----------------------------|
			{																				//|
				delete node;																//|
				return 0;																	//|
			}																				//|
			if ((node->_left == 0 && node->_right == 0))// || 			//NO CHILDREN		  |
				//(node->_left == _begin && node->_right == _end))		//ULTIMO ELEMENTO-----|
			{
				// std::cout << "0" << std::endl;
				delete node;
				return 0;
			}
		  	if (node->_left == 0)	//RIGHT CHILD
			{
				// std::cout << "1" << std::endl;
				pointer right_subtree = node->_right;
				right_subtree->_parent = node->_parent;
				delete node;
				// this might return 0 if there are zero child nodes,
				// but that is what we want anyway
				return right_subtree;
			}
		  	if (node->_left == _begin)	//LEFT BEGIN
			{
				// std::cout << "1" << std::endl;
				pointer right_subtree = node->_right;
				if (right_subtree)
				{
					// right_subtree->_parent = node->_parent;
					// right_subtree->_left = _begin;////////////////////////////////////////TESTARE	
					// _begin->_parent = right_subtree;
					
					right_subtree->_parent = node->_parent;
					pointer min_node = find_min(right_subtree);
					min_node->_left = _begin;
					_begin->_parent = min_node;

					delete node;
					// this might return 0 if there are zero child nodes,
					// but that is what we want anyway
					return right_subtree;
				}
				_begin->_parent = node->_parent;
				delete node;
				return _begin;
			}
			if (node->_right == 0)	//LEFT CHILD
			{
				// std::cout << "2" << std::endl;
				pointer left_subtree = node->_left;
				left_subtree->_parent = node->_parent;
				delete node;
				// this will always return a valid node, since we know
				// is not 0 from the previous if statement
				return left_subtree;
			}
		  	if (node->_right == _end)	//LEFT BEGIN
			{
				// std::cout << "1" << std::endl;
				pointer left_subtree = node->_left;
				if (left_subtree)
				{
					left_subtree->_parent = node->_parent;
					pointer max_node = find_max(left_subtree);
					max_node->_right = _end;
					_end->_parent = max_node;
					delete node;
					// this might return 0 if there are zero child nodes,
					// but that is what we want anyway
					return left_subtree;
				}
				_end->_parent = node->_parent;
				delete node;
				return _end;				
			}
			//LEFT AND RIGHT CHILDREN
			// std::cout << "3" << std::endl;
			pointer max_node = find_max(node->_left);
			// since max_node came from the left sub-tree, we need to
			// remove it from that sub-tree before re-linking that sub-tree
			// back into the rest of the tree
			if (max_node == node->_left)										/*	 m	*/
			{																	/*	/\	*/
				node->_right->_parent = max_node;								/* d t	*/
				max_node->_right = node->_right;								/*si rimuove m */
				delete node;
				return max_node;
			}
			max_node->_left = remove_max_node(node->_left, max_node);
			// if (node->_left != max_node)
				node->_left->_parent = max_node;
			max_node->_right = node->_right;
			node->_right->_parent = max_node;
			max_node->_parent = node->_parent;
			delete node;
			// ////////////////////PRINT///////////////////////////////////////////////////////
			// if (max_node)
			// 	std::cout << "VALUE:" << max_node->_value.first << std::endl;
			// if (max_node->_parent)
			// 	std::cout << "PARENT:" << max_node->_parent->_value.first << std::endl;
			// if (max_node->_left)
			// 	std::cout << "LEFT:" << max_node->_left->_value.first << std::endl;
			// if (max_node->_right)
			// 	std::cout << "RIGHT:" << max_node->_right->_value.first << std::endl;
			// ///////////////////////////////////////////////////////////////////////////////
			return max_node;
		}
		else if (key < node->_value.first)
			node->_left = remove(node->_left, key);
		else
			node->_right = remove(node->_right, key);
		return node;
	}
	///////////////////////////////////////////////////////////////////
	
	//2.////////////////////////////////////////////////////////////////
	pointer FindMin(pointer node)
	{
		while(node->_left != 0)
			node = node->_left;
		return node;
	}
	pointer Delete(pointer node, int key)
	{
		if(node == 0)
			return node; 
		else if(key < node->_value.first)
			node->_left = Delete(node->_left, key);
		else if (key > node->_value.first)
			node->_right = Delete(node->_right, key);
		// Wohoo... I found you, Get ready to be deleted	
		else 
		{
			// Case 1:  No child
			if(node->_left == 0 && node->_right == 0)
			{ 
				delete node;
				node = 0;
			}
			//Case 2: One child 
			else if(node->_left == 0)
			{
				pointer temp = node;
				node = node->_right;
				delete temp;
			}
			else if(node->_right == 0)
			{
				pointer temp = node;
				node = node->_left;
				delete temp;
			}
			// case 3: 2 children
			else
			{ 
				pointer temp = FindMin(node->_right);
				node->_value.first = temp->_value.first;
				node->_right = Delete(node->_right, temp->_value.first);
			}
		}
		return node;
	}
	///////////////////////////////////////////////////////////////////
void print(std::string name)
{
	std::cout << "-----" << name << "-----------------------" << std::endl;
	if (!_size)
	{
		std::cout << "EMPTY TREE" << std::endl;
		std::cout << "------------------------------" << std::endl;
		return ;
	}
	std::cout << "size:" << _size << std::endl;
	std::cout << "content: "<< std::endl;
	iterator itB = begin();
	itB++;
	iterator itE = end();
	// itE--;
	for (; itB != itE ; ++itB)
	{
		std::cout << "F: " << itB->_value.first << "\tS: " << itB->_value.second;
		if (itB->_parent)
			std::cout << "\tP: " << itB->_parent->_value.first <<  std::endl;
		else
			std::cout << "\tP: NULL" << std::endl;
			
	}
	std::cout << "-----------------------------" << std::endl;
}


};
};

#endif
