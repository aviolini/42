/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:41:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/14 12:13:07 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t x;

	i = 0;
	x = 0;
	while (dst[i] && i < size)
		i++;
	while (src[x] && (i + x + 1) < size)
	{
		dst[i + x] = src[x];
		x++;
	}
	if (i < size)
		dst[i + x] = '\0';
	return (i + ft_strlen(src));
}
