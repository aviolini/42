/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:56 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/27 15:51:39 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

//////////////////////////////////////////// RIGA 457 -> ITERATOR /////////
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

template <class T1, class T2>
struct myPair
{
public:
	typedef T1		first_type;
	typedef T2		second_type;
private:

public:
	myPair();														//DEFAULT
	template<class U, class V> myPair (const myPair<U,V>& pr);		//COPY
	myPair (const first_type& a, const second_type& b);			//INIZIALIZATION
	myPair& operator= (const myPair& pr);
	~myPair();	
};

template <class T1, class T2>
  bool operator== (const myPair<T1,T2>& lhs, const myPair<T1,T2>& rhs);
template <class T1, class T2>
  bool operator!= (const myPair<T1,T2>& lhs, const myPair<T1,T2>& rhs);
template <class T1, class T2>
  bool operator<  (const myPair<T1,T2>& lhs, const myPair<T1,T2>& rhs);
template <class T1, class T2>
  bool operator<= (const myPair<T1,T2>& lhs, const myPair<T1,T2>& rhs);
template <class T1, class T2>
  bool operator>  (const myPair<T1,T2>& lhs, const myPair<T1,T2>& rhs);
template <class T1, class T2>
  bool operator>= (const myPair<T1,T2>& lhs, const myPair<T1,T2>& rhs);

///////////////////////////////////////////////////////////////////////////////
template <class T1, class T2>
myPair<T1,T2> myMake_pair (T1 x, T2 y)
{
	(void)x;
	(void)y;
}


#endif