/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:46:50 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/22 13:59:56 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "vector.hpp"

namespace ft
{
template <class T, class C = ft::vector<T> > 
class stack
{
public:
	typedef C 							container_type;
	typedef typename C::value_type 		value_type;
	typedef typename C::reference		reference;
	typedef typename C::const_reference	const_reference;
	typedef typename C::size_type		size_type;
protected:
	container_type _container;
public:	
	/*CANONICAL-----------------------------------------------------------------------------------*/
	stack() : _container(0){}
	stack(const stack& rhs) : _container(rhs._container){}
	stack& operator=(const stack& rhs)
	{
		_container = rhs._container;
		return *this;
	}
	explicit stack (const container_type& ctnr = container_type()) : _container(ctnr){}
	~stack(){}
	bool empty() const						//EMPTY VECTOR
	{
		return _container.empty();
	}
	size_type size() const					//SIZE VECTOR
	{
		return _container.size();	
	}
	reference top()							//BACK VECTOR
	{
		return _container.back();	
	}
	const_reference top() const				//BACK VECTOR
	{
		return _container.back(); 
	}
	void push (const value_type& val)		//PUSH_BACK VECTOR
	{
		_container.push_back(val); 
	}
	void pop()								//POP_BACK VECTOR
	{
		_container.pop_back(); 
	}
};
};
/*Non-member function overloads*/
/*RELATIONAL OPERATOR--------------------------------------------------------------------*/
template <class T, class C>
bool operator== (const ft::stack<T,C>& lhs, const ft::stack<T,C>& rhs)
{
	return lhs._container == rhs._container;
}
template <class T, class C>
bool operator!= (const ft::stack<T,C>& lhs, const ft::stack<T,C>& rhs)
{
	return lhs._container != rhs._container; 	  
}
template <class T, class C>
bool operator<  (const ft::stack<T,C>& lhs, const ft::stack<T,C>& rhs)
{
	return lhs._container < rhs._container; 	  
}
template <class T, class C>
bool operator<= (const ft::stack<T,C>& lhs, const ft::stack<T,C>& rhs)
{
	return lhs._container <= rhs._container;   
}
template <class T, class C>
bool operator>  (const ft::stack<T,C>& lhs, const ft::stack<T,C>& rhs)
{
	return lhs._container > rhs._container; 	  
}
template <class T, class C>
bool operator>= (const ft::stack<T,C>& lhs, const ft::stack<T,C>& rhs)
{
	return lhs._container >= rhs._container; 	  
}

#endif