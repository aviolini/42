/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:48:01 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/19 17:25:57 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i--);
	write(fd, "\n", 1);
}
