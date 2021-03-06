/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:46:50 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/07 11:56:41 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <deque>

namespace ft
{
template <class T, class C = std::deque<T> > 
class stack
{
public:
	typedef C 							container_type;
	typedef typename C::value_type 		value_type;
	typedef typename C::reference		reference;
	typedef typename C::const_reference	const_reference;
	typedef typename C::size_type		size_type;
protected:
	container_type c;
public:	
	/*CANONICAL-----------------------------------------------------------------------------------*/
	explicit stack (const container_type& ctnr = container_type()) : c(ctnr){}
	stack(const stack& rhs) : c(rhs.c){}
	stack& operator=(const stack& rhs)
	{
		c = rhs.c;
		return *this;
	}
	~stack(){}
	bool empty() const						//EMPTY VECTOR
	{
		return c.empty();
	}
	size_type size() const					//SIZE VECTOR
	{
		return c.size();	
	}
	reference top()							//BACK VECTOR
	{
		return c.back();	
	}
	const_reference top() const				//BACK VECTOR
	{
		return c.back(); 
	}
	void push (const value_type& val)		//PUSH_BACK VECTOR
	{
		c.push_back(val); 
	}
	void pop()								//POP_BACK VECTOR
	{
		c.pop_back(); 
	}
/*Non-member function overloads*/
/*RELATIONAL OPERATOR--------------------------------------------------------------------*/
private:
	friend bool operator== (const ft::stack< T, C >& lhs, const ft::stack< T, C >& rhs)
	{
		return lhs.c == rhs.c;
	}
	friend bool operator!= (const ft::stack< T, C >& lhs, const ft::stack< T, C >& rhs)
	{
		return lhs.c != rhs.c; 	  
	}
	friend bool operator<  (const ft::stack< T, C >& lhs, const ft::stack< T, C >& rhs)
	{
		return lhs.c < rhs.c; 	  
	}
	friend bool operator<= (const ft::stack< T, C >& lhs, const ft::stack< T, C >& rhs)
	{
		return lhs.c <= rhs.c;   
	}
	friend bool operator>  (const ft::stack< T, C >& lhs, const ft::stack< T, C >& rhs)
	{
		return lhs.c > rhs.c; 	  
	}
	friend bool operator>= (const ft::stack< T, C >& lhs, const ft::stack< T, C >& rhs)
	{
		return lhs.c >= rhs.c; 	  
	}
};
}

#endif