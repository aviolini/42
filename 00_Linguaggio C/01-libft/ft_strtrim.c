/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:15:36 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/15 12:18:54 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_search(char const *s1, char const *set)
{
	size_t y;
	size_t i;

	i = 0;
	y = 0;
	while (s1[i] && set[y])
	{
		while (set[y] == s1[i])
		{
			i++;
			y = 0;
		}
		y++;
	}
	return (i);
}

size_t	ft_search_rev(char const *s1, char const *set, size_t i)
{
	size_t y;
	size_t len;

	y = 0;
	len = ft_strlen(s1);
	while ((len > i) && set[y])
	{
		while (set[y] == s1[len - 1])
		{
			len--;
			y = 0;
		}
		y++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	y;
	size_t	len;
	size_t	size;

	if (!(s1))
		return (0);
	i = 0;
	y = 0;
	i = ft_search(s1, set);
	len = ft_search_rev(s1, set, i);
	size = len - i + 1;
	if (!(ptr = (char *)malloc(sizeof(char) * (size))))
		return (0);
	y = 0;
	while (y < (size - 1))
	{
		ptr[y] = s1[i];
		y++;
		i++;
	}
	ptr[y] = '\0';
	return (ptr);
}
