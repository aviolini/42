/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:02:47 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/12 13:29:36 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*(unsigned const char*)(str + i) == (unsigned char)c)
			return ((unsigned char*)str + i);
		i++;
	}
	return (NULL);
}
