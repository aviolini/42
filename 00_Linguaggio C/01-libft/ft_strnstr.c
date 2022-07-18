/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:18:24 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/20 10:07:02 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t l)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)str);
	while (str[i] && i < l)
	{
		while (needle[y] == str[i + y])
		{
			if (needle[y + 1] == '\0' && l > (y + i))
				return ((char *)str + i);
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
