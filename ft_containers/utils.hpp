/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:56 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 22:02:45 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

//VECTOR////////////////////////////////////////// RIGA 457 -> ITERATOR /////////
template <class _Tp>
struct myHas_iterator_category
{
private:
    template <class _Up> static short __test(...);
    template <class _Up> static char __test(typename _Up::iterator_category* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};
//////////////////////////////////////////////////////////////////////////
template <bool, typename T = void>
struct myEnable_if
{};

template <typename T>
struct myEnable_if<true, T> {
  typedef T type;
};
////////////////////////////////////////////////////////////////

//MAP//////////////////////////////////////////////////////////////
namespace ft
{	
template <class T1, class T2>
struct pair
{
public:
	typedef T1		first_type;
	typedef T2		second_type;
	first_type		first;
	second_type 	second;

	pair() : first(0), second(0) {}													//DEFAULT
	template<class U, class V> 														//COPY
	pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}	
	pair (const first_type& a, const second_type& b) : first(a), second(b) {}								//INIZIALIZATION
	pair& operator= (const pair& pr)
	{
		this->first = pr.first;
		this->second = pr.second;
		return *this;
	}
	~pair() {}
};
};
template <class T1, class T2>
bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs.first == rhs.first && lhs.second == rhs.second;
}
template <class T1, class T2>
bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs != rhs;
}
template <class T1, class T2>
bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}
template <class T1, class T2>
bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return !(rhs < lhs);
}
template <class T1, class T2>
bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return rhs < lhs;
}
template <class T1, class T2>
bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return !(lhs < rhs);
}
///////////////////////////////////////////////////////////////////////////////
namespace ft
{
template <class T1, class T2>
ft::pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( ft::pair<T1,T2>(x,y) );
};
};
/////////////////////////////////////////////////////////////////////////////////

#endif