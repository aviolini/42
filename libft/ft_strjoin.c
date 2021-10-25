/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:47:30 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/14 18:11:55 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		i;
	size_t		lens1;
	size_t		lens2;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(ptr = (char *)(malloc(sizeof(char) * (lens1 + lens2 + 1)))))
		return (NULL);
	while (i < lens1)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		ptr[lens1 + i] = s2[i];
		i++;
	}
	ptr[lens1 + i] = '\0';
	return (ptr);
}
