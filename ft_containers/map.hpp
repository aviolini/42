/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:25:40 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/29 17:49:27 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "./utils.hpp"
#include "./mapIterators.hpp"


namespace ft
{
/*
template <class _Key, class _CP, class _Compare,
          bool = is_empty<_Compare>::value && !__libcpp_is_final<_Compare>::value>
class __map_value_compare
    : private _Compare
{
public:
    _LIBCPP_INLINE_VISIBILITY
    __map_value_compare()
        _NOEXCEPT_(is_nothrow_default_constructible<_Compare>::value)
        : _Compare() {}
    _LIBCPP_INLINE_VISIBILITY
    __map_value_compare(_Compare c)
        _NOEXCEPT_(is_nothrow_copy_constructible<_Compare>::value)
        : _Compare(c) {}
    _LIBCPP_INLINE_VISIBILITY
    const _Compare& key_comp() const _NOEXCEPT {return *this;}
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _CP& __x, const _CP& __y) const
        {return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y.__get_value().first);}
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _CP& __x, const _Key& __y) const
        {return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y);}
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _Key& __x, const _CP& __y) const
        {return static_cast<const _Compare&>(*this)(__x, __y.__get_value().first);}
    void swap(__map_value_compare&__y)
        _NOEXCEPT_(__is_nothrow_swappable<_Compare>::value)
    {
      using _VSTD::swap;
      swap(static_cast<_Compare&>(*this), static_cast<_Compare&>(__y));
    }
};

template <class _Key, class _CP, class _Compare>
class __map_value_compare<_Key, _CP, _Compare, false>
{
    _Compare comp;

public:
    _LIBCPP_INLINE_VISIBILITY
    __map_value_compare()
        _NOEXCEPT_(is_nothrow_default_constructible<_Compare>::value)
        : comp() {}
    _LIBCPP_INLINE_VISIBILITY
    __map_value_compare(_Compare c)
        _NOEXCEPT_(is_nothrow_copy_constructible<_Compare>::value)
        : comp(c) {}
    _LIBCPP_INLINE_VISIBILITY
    const _Compare& key_comp() const _NOEXCEPT {return comp;}

    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _CP& __x, const _CP& __y) const
        {return comp(__x.__get_value().first, __y.__get_value().first);}
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _CP& __x, const _Key& __y) const
        {return comp(__x.__get_value().first, __y);}
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _Key& __x, const _CP& __y) const
        {return comp(__x, __y.__get_value().first);}
    void swap(__map_value_compare&__y)
        _NOEXCEPT_(__is_nothrow_swappable<_Compare>::value)
    {
        using _VSTD::swap;
        swap(comp, __y.comp);
    }
};

template <class _Allocator>
class __map_node_destructor
{
    typedef _Allocator                          allocator_type;
    typedef allocator_traits<allocator_type>    __alloc_traits;

public:
    typedef typename __alloc_traits::pointer    pointer;

private:
    allocator_type& __na_;

    __map_node_destructor& operator=(const __map_node_destructor&);

public:
    bool __first_constructed;
    bool __second_constructed;

    _LIBCPP_INLINE_VISIBILITY
    explicit __map_node_destructor(allocator_type& __na) _NOEXCEPT
        : __na_(__na),
          __first_constructed(false),
          __second_constructed(false)
        {}

    _LIBCPP_INLINE_VISIBILITY
    void operator()(pointer __p) _NOEXCEPT
    {
        if (__second_constructed)
            __alloc_traits::destroy(__na_, _VSTD::addressof(__p->__value_.__get_value().second));
        if (__first_constructed)
            __alloc_traits::destroy(__na_, _VSTD::addressof(__p->__value_.__get_value().first));
        if (__p)
            __alloc_traits::deallocate(__na_, __p, 1);
    }
};

template <class _Key, class _Tp, class _Compare, class _Allocator>
    class map;

template <class _Key, class _Tp>
struct __value_type
{
    typedef _Key                                     key_type;
    typedef _Tp                                      mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;

private:
    value_type __cc;

public:
    _LIBCPP_INLINE_VISIBILITY
    value_type& __get_value() { return __cc; }
    _LIBCPP_INLINE_VISIBILITY
    const value_type& __get_value() const { return __cc; }

private:
   __value_type();
   __value_type(__value_type const&);
   __value_type& operator=(__value_type const&);
   ~__value_type();
};


template <class _Tp>
struct __extract_key_value_types;

template <class _Key, class _Tp>
struct __extract_key_value_types<__value_type<_Key, _Tp> >
{
  typedef _Key const __key_type;
  typedef _Tp        __mapped_type;
};

template <class _TreeIterator>
class _LIBCPP_TEMPLATE_VIS __map_iterator
{
    typedef typename _TreeIterator::_NodeTypes                   _NodeTypes;
    typedef typename _TreeIterator::__pointer_traits             __pointer_traits;

    _TreeIterator __i_;

public:
    typedef bidirectional_iterator_tag                           iterator_category;
    typedef typename _NodeTypes::__map_value_type                value_type;
    typedef typename _TreeIterator::difference_type              difference_type;
    typedef value_type&                                          reference;
    typedef typename _NodeTypes::__map_value_type_pointer        pointer;

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator() _NOEXCEPT {}

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator(_TreeIterator __i) _NOEXCEPT : __i_(__i) {}

    _LIBCPP_INLINE_VISIBILITY
    reference operator*() const {return __i_->__get_value();}
    _LIBCPP_INLINE_VISIBILITY
    pointer operator->() const {return pointer_traits<pointer>::pointer_to(__i_->__get_value());}

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator& operator++() {++__i_; return *this;}
    _LIBCPP_INLINE_VISIBILITY
    __map_iterator operator++(int)
    {
        __map_iterator __t(*this);
        ++(*this);
        return __t;
    }

    _LIBCPP_INLINE_VISIBILITY
    __map_iterator& operator--() {--__i_; return *this;}
    _LIBCPP_INLINE_VISIBILITY
    __map_iterator operator--(int)
    {
        __map_iterator __t(*this);
        --(*this);
        return __t;
    }

    friend _LIBCPP_INLINE_VISIBILITY
    bool operator==(const __map_iterator& __x, const __map_iterator& __y)
        {return __x.__i_ == __y.__i_;}
    friend
    _LIBCPP_INLINE_VISIBILITY
    bool operator!=(const __map_iterator& __x, const __map_iterator& __y)
        {return __x.__i_ != __y.__i_;}

    template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS map;
    template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS multimap;
    template <class> friend class _LIBCPP_TEMPLATE_VIS __map_const_iterator;
};

template <class _TreeIterator>
class _LIBCPP_TEMPLATE_VIS __map_const_iterator
{
    typedef typename _TreeIterator::_NodeTypes                   _NodeTypes;
    typedef typename _TreeIterator::__pointer_traits             __pointer_traits;

    _TreeIterator __i_;

public:
    typedef bidirectional_iterator_tag                           iterator_category;
    typedef typename _NodeTypes::__map_value_type                value_type;
    typedef typename _TreeIterator::difference_type              difference_type;
    typedef const value_type&                                    reference;
    typedef typename _NodeTypes::__const_map_value_type_pointer  pointer;

    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator() _NOEXCEPT {}

    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator(_TreeIterator __i) _NOEXCEPT : __i_(__i) {}
    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator(__map_iterator<
        typename _TreeIterator::__non_const_iterator> __i) _NOEXCEPT
        : __i_(__i.__i_) {}

    _LIBCPP_INLINE_VISIBILITY
    reference operator*() const {return __i_->__get_value();}
    _LIBCPP_INLINE_VISIBILITY
    pointer operator->() const {return pointer_traits<pointer>::pointer_to(__i_->__get_value());}

    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator& operator++() {++__i_; return *this;}
    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator operator++(int)
    {
        __map_const_iterator __t(*this);
        ++(*this);
        return __t;
    }

    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator& operator--() {--__i_; return *this;}
    _LIBCPP_INLINE_VISIBILITY
    __map_const_iterator operator--(int)
    {
        __map_const_iterator __t(*this);
        --(*this);
        return __t;
    }

    friend _LIBCPP_INLINE_VISIBILITY
    bool operator==(const __map_const_iterator& __x, const __map_const_iterator& __y)
        {return __x.__i_ == __y.__i_;}
    friend _LIBCPP_INLINE_VISIBILITY
    bool operator!=(const __map_const_iterator& __x, const __map_const_iterator& __y)
        {return __x.__i_ != __y.__i_;}

    template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS map;
    template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS multimap;
    template <class, class, class> friend class _LIBCPP_TEMPLATE_VIS __tree_const_iterator;
};
	
*/
/////////////////////////////////////////MAPBEGIN//////////////////////////////////////////////////////////
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
class map
{
public:
	typedef Key													key_type;		//THE TYPE OF THE KEY
	typedef T													mapped_type;	//THE TYPE OF THE VALUES
	typedef ft::pair<const key_type,mapped_type>				value_type;	
	typedef Compare												key_compare;
	typedef Alloc												allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
    typedef typename allocator_type::difference_type			difference_type;
    typedef typename allocator_type::size_type		   			size_type;
	typedef mapIterator< myBidirectional_iterator_tag, T > 		const_iterator;
	typedef mapIterator< myBidirectional_iterator_tag, T > 		iterator;
	typedef mapReverse_iterator<const_iterator> 				const_reverse_iterator;
	typedef mapReverse_iterator<iterator> 						reverse_iterator;
	
	class value_compare
	{
	  friend class map;
	protected:
	  Compare comp;
	  value_compare (Compare c) : comp(c) {}
	public:
	  typedef bool result_type;
	  typedef value_type first_argument_type;
	  typedef value_type second_argument_type;
	  bool operator() (const value_type& x, const value_type& y) const
	  {
	    return comp(x.first, y.first);
	  }
	};
	
private:
	allocator_type	_allocator;

// private:
//     typedef _VSTD::__value_type<key_type, mapped_type>             									__value_type;
//     typedef __map_value_compare<key_type, __value_type, key_compare> 								__vc;
//     typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>, __value_type>::type 	__allocator_type;
//     typedef __tree<__value_type, __vc, __allocator_type>            								__base;
//     typedef typename __base::__node_traits                          								__node_traits;
//     typedef allocator_traits<allocator_type>                        								__alloc_traits;
//     __base __tree_;

// public:
//     typedef typename __alloc_traits::pointer         				pointer;
//     typedef typename __alloc_traits::const_pointer   				const_pointer;
//     typedef typename __alloc_traits::size_type       				size_type;
//     typedef typename __alloc_traits::difference_type 				difference_type;
//     typedef __map_iterator<typename __base::iterator>				iterator;
//     typedef __map_const_iterator<typename __base::const_iterator> 	const_iterator;
//     typedef _VSTD::reverse_iterator<iterator>               		reverse_iterator;
//     typedef _VSTD::reverse_iterator<const_iterator>         		const_reverse_iterator;

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
	///*OBSERVERS----------------------------------------------------------------------------------*/
// /*	key_compare key_comp() const
// 	{
// 		return __tree_.value_comp().key_comp();
// 	}
// 	value_compare value_comp() const
// 	{
// 		return value_compare(__tree_.value_comp().key_comp())
// 	}
// */
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
// /*	allocator_type get_allocator() const 
// 	{
// 		return allocator_type(__tree_.__alloc());
// 	}
// */
	
};
};

#endif