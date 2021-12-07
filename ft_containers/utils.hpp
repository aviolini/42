/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:56 by aviolini          #+#    #+#             */
/*   Updated: 2021/12/07 02:09:01 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>

namespace ft
{
struct Input_iterator_tag {};
struct Output_iterator_tag {};
struct Forward_iterator_tag       : public Input_iterator_tag {};
struct Bidirectional_iterator_tag : public Forward_iterator_tag {};
struct Random_access_iterator_tag : public Bidirectional_iterator_tag {};

typedef unsigned long int 	size_t;
typedef long int			ptrdiff_t;

//TYPE_TRAITS//////////////////////////////////////////////RIGA 706

template <class _Tp, _Tp __v>
struct IntegralConstant
{
    static const _Tp      		value = __v;
    typedef _Tp           		value_type;
    typedef IntegralConstant type;
    operator value_type() const throw()
	{
		return value;
	}
};

/////////////////////////////////////////////////////////////////////
typedef IntegralConstant<bool, true>  true_type;
typedef IntegralConstant<bool, false> false_type;

template <class _Tp>	struct IsIntegral						: public false_type {};
template <>				struct IsIntegral<bool>					: public true_type {};
template <>				struct IsIntegral<char>					: public true_type {};
template <>				struct IsIntegral<signed char>			: public true_type {};
template <>				struct IsIntegral<unsigned char>		: public true_type {};
template <>				struct IsIntegral<short>				: public true_type {};
template <>				struct IsIntegral<unsigned short>		: public true_type {};
template <>				struct IsIntegral<int>					: public true_type {};
template <>				struct IsIntegral<unsigned int>			: public true_type {};
template <>				struct IsIntegral<long>					: public true_type {};
template <>				struct IsIntegral<unsigned long>		: public true_type {};
template <>				struct IsIntegral<long long>			: public true_type {};
template <>				struct IsIntegral<unsigned long long>	: public true_type {};

template <class _Tp>	struct IsFloatingPoint					: public false_type {};
template <>				struct IsFloatingPoint<float>			: public true_type {};
template <>				struct IsFloatingPoint<double>			: public true_type {};
template <>				struct IsFloatingPoint<long double>		: public true_type {};

//VECTOR////////////////////////////////////////// RIGA 457 -> ITERATOR /////////
template <class _Tp>
struct HasIteratorCategory
{
private:
    template <class _Up> static short __test(...);
    template <class _Up> static char __test(typename _Up::iterator_category* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};

template <bool, typename T = void>
struct EnableIfFalse
{};

template <typename T>
struct EnableIfFalse<false, T>
{
  typedef T type;
};

template <bool, typename T = void>
struct EnableIfTrue
{};

template <typename T>
struct EnableIfTrue<true, T>
{
  typedef T type;
};

//MAP//////////////////////////////////////////////////////////////
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

template <class T1, class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1)
			return false;
		else if (*first1<*first2)
			return true;
		++first1;
		++first2;
  }
  return (first2!=last2);
}
template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1!=last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
  	}
  	return true;
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_comparePair (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
	{
        if (first1->first < first2->first)
			return true;
		if (first1->second < first2->second)
			return true;
        if (first2->first < first1->first)
			return false;
        if (first2->second < first1->second)
			return false;
    }
    return (first1 == last1) && (first2 != last2);
}
template <class InputIterator1, class InputIterator2>
bool equalPair (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1!=last1)
	{
		if (!(first1->first == first2->first))
			return false;
		++first1;
		++first2;
  	}
  	return true;
}
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

#endif