/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:56 by aviolini          #+#    #+#             */
/*   Updated: 2021/11/02 11:13:07 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <__tree>

struct myInput_iterator_tag {};
struct myOutput_iterator_tag {};
struct myForward_iterator_tag       : public myInput_iterator_tag {};
struct myBidirectional_iterator_tag : public myForward_iterator_tag {};
struct myRandom_access_iterator_tag : public myBidirectional_iterator_tag {};

namespace ft
{
  typedef unsigned long int 	size_t;
  typedef long int				ptrdiff_t;
};

//TYPE_TRAITS//////////////////////////////////////////////RIGA 706
template <class _Tp, _Tp __v>
struct myIntegral_constant
{
    static const _Tp      		value = __v;
    typedef _Tp           		value_type;
    typedef myIntegral_constant type;
//     _LIBCPP_INLINE_VISIBILITY
    operator value_type() const throw() {return value;}
// #if _LIBCPP_STD_VER > 11
//     _LIBCPP_INLINE_VISIBILITY
    // constexpr value_type operator ()() const _NOEXCEPT {return value;}

};

/////////////////////////////////////////////////////////////////////
typedef myIntegral_constant<bool, true>  true_type;
typedef myIntegral_constant<bool, false> false_type;

template <class _Tp> struct myIs_integral                     : public false_type {};
template <>          struct myIs_integral<bool>               : public true_type {};
template <>          struct myIs_integral<char>               : public true_type {};
template <>          struct myIs_integral<signed char>        : public true_type {};
template <>          struct myIs_integral<unsigned char>      : public true_type {};
template <>          struct myIs_integral<short>              : public true_type {};
template <>          struct myIs_integral<unsigned short>     : public true_type {};
template <>          struct myIs_integral<int>                : public true_type {};
template <>          struct myIs_integral<unsigned int>       : public true_type {};
template <>          struct myIs_integral<long>               : public true_type {};
template <>          struct myIs_integral<unsigned long>      : public true_type {};
template <>          struct myIs_integral<long long>          : public true_type {};
template <>          struct myIs_integral<unsigned long long> : public true_type {};

template <class _Tp> struct myIs_floating_point              : public false_type {};
template <>          struct myIs_floating_point<float>       : public true_type {};
template <>          struct myIs_floating_point<double>      : public true_type {};
template <>          struct myIs_floating_point<long double> : public true_type {};



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

template <bool, typename T = void>
struct myEnable_if_false
{};

template <typename T>
struct myEnable_if_false<false, T> {
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
	pair (const first_type& a, const second_type& b) : first(a), second(b) {}		//INIZIALIZATION
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