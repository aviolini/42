/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:49:27 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/13 12:48:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src < dest)
	{
		while (len)
		{
			len--;
			*(unsigned char *)(dest + len) = *(unsigned const char *)
				(src + len);
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
