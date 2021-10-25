/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:38 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 15:01:55 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_zero_rather_space_sdxu(char *str, int len, t_strutt *strutt)
{
	if (strutt->flag_zero && strutt->width > len
		&& (strutt->precision <= -1 || !strutt->dot))
	{
		if (strutt->num_is_neg)
			ft_putchar("-", 1, strutt);
		ft_zero(strutt->width - len, strutt);
		ft_putchar(str, len, strutt);
		return (1);
	}
	return (0);
}

int		ft_zero_rather_space_p(char *str, int len, t_strutt *strutt)
{
	if (strutt->flag_zero && strutt->width > len
		&& (strutt->precision <= -1 || !strutt->dot))
	{
		if (strutt->num_is_neg)
			ft_putchar("0x", 2, strutt);
		ft_zero(strutt->width - len, strutt);
		ft_putchar(str, len, strutt);
		return (1);
	}
	return (0);
}

int		ft_num_is_zero(t_strutt *strutt)
{
	strutt->num_is_zero = 1;
	if (strutt->dot == 1 && (strutt->precision == 0))
	{
		if (!strutt->width && strutt->prec_is_arg)
			return (ft_putchar("0", 1, strutt));
		if (strutt->width > 0)
		{
			if (strutt->flag_minus == 0 && strutt->prec_is_arg)
			{
				if (strutt->flag_zero)
					return (ft_zero(strutt->width, strutt));
				ft_space(strutt->width - 1, strutt);
				ft_putchar("0", 1, strutt);
			}
			if (strutt->flag_minus == 1 && strutt->prec_is_arg)
			{
				ft_putchar("0", 1, strutt);
				ft_space(strutt->width - 1, strutt);
			}
			if (strutt->precision == 0)
				ft_space(strutt->width, strutt);
		}
		return (1);
	}
	return (0);
}

int		ft_num_is_null(t_strutt *strutt)
{
	strutt->num_is_zero = 1;
	if (strutt->dot == 1 && (strutt->precision == 0))
	{
		ft_space(strutt->width, strutt);
		if (strutt->width > 2)
			strutt->width = strutt->width - 2;
		ft_putchar("0x", 2, strutt);
		return (1);
	}
	return (0);
}

int		ft_num_is_neg(t_strutt *strutt, int num)
{
	num = num * -1;
	strutt->width = strutt->width - 1;
	strutt->num_is_neg = 1;
	return (num);
}
