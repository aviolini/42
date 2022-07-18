/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:23:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 15:01:32 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_space(int y, t_strutt *strutt)
{
	int i;

	i = 0;
	while (i++ < y)
		ft_putchar(" ", 1, strutt);
	return (1);
}

int		ft_zero(int x, t_strutt *strutt)
{
	int i;

	i = 0;
	while (i++ < x)
		ft_putchar("0", 1, strutt);
	return (1);
}

int		ft_putchar(char *str, int size, t_strutt *strutt)
{
	write(1, str, size);
	strutt->total_chars = strutt->total_chars + size;
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_perc(t_strutt *strutt)
{
	if (strutt->flag_minus == 0)
	{
		if (strutt->flag_zero)
		{
			ft_zero(strutt->width - 1, strutt);
			ft_putchar("%", 1, strutt);
			return ;
		}
		ft_space(strutt->width - 1, strutt);
		ft_putchar("%", 1, strutt);
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar("%", 1, strutt);
		ft_space(strutt->width - 1, strutt);
	}
}
