/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:38:56 by aviolini          #+#    #+#             */
/*   Updated: 2021/10/21 16:39:24 by aviolini         ###   ########.fr       */
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

#endif