/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 08:40:38 by aviolini          #+#    #+#             */
/*   Updated: 2021/06/03 08:49:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!str || !to_find)
		return (NULL);
	i = 0;
	while (to_find[i])
		i++;
	if (i == 0)
		return (str);
	i = 0;
	j = 0;
	while (to_find[j] == str[j])
	{
		if (to_find[j + 1] == '\0')
		{
			return (str + i);
		}
		j++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		i;
	size_t		lens1;
	size_t		lens2;

	i = -1;
	if (!(s1) || !(s2))
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!ptr)
		return (NULL);
	while (++i < lens1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < lens2)
		ptr[lens1 + i] = s2[i];
	ptr[lens1 + i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(s))
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if ((start < ft_strlen(s)))
	{
		while (i < len)
		{
			*(ptr + i) = *(s + start + i);
			i++;
		}
		*(ptr + i) = '\0';
	}
	return (ptr);
}
