/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_print_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:28:12 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 12:18:43 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_s_fl_min_0(char *str, int len, t_strutt *strutt)
{
	if (strutt->width > len && (strutt->precision >= len
		|| strutt->precision <= -1))
	{
		ft_space(strutt->width - len, strutt);
		ft_putchar(str, len, strutt);
		return (1);
	}
	if (strutt->precision < len && strutt->precision != -1)
	{
		ft_space(strutt->width - strutt->precision, strutt);
		ft_putchar(str, strutt->precision, strutt);
		return (1);
	}
	return (0);
}

int		ft_print_s_fl_min_1(char *str, int len, t_strutt *strutt)
{
	if (strutt->width > len && (strutt->precision >= len
		|| strutt->precision <= -1))
	{
		ft_putchar(str, len, strutt);
		ft_space(strutt->width - len, strutt);
		return (1);
	}
	if (strutt->precision < len && strutt->precision != -1)
	{
		ft_putchar(str, strutt->precision, strutt);
		ft_space(strutt->width - strutt->precision, strutt);
		return (1);
	}
	return (0);
}

int		ft_print_dxu(char *str, int len, t_strutt *strutt)
{
	if (strutt->flag_minus == 0)
	{
		if (strutt->width > len && strutt->precision <= len)
			ft_space(strutt->width - len, strutt);
		if (strutt->width > strutt->precision && strutt->precision > len)
			ft_space(strutt->width - strutt->precision, strutt);
		if (strutt->num_is_neg)
			ft_putchar("-", 1, strutt);
		if (strutt->precision > len)
			ft_zero(strutt->precision - len, strutt);
		ft_putchar(str, len, strutt);
	}
	if (strutt->flag_minus == 1)
	{
		if (strutt->num_is_neg)
			ft_putchar("-", 1, strutt);
		if (strutt->precision > len)
			ft_zero(strutt->precision - len, strutt);
		ft_putchar(str, len, strutt);
		if (strutt->width > len && strutt->precision <= len)
			ft_space(strutt->width - len, strutt);
		if (strutt->width > strutt->precision && strutt->precision > len)
			ft_space(strutt->width - strutt->precision, strutt);
	}
	return (1);
}

int		ft_print_p(char *str, int len, t_strutt *strutt)
{
	if (strutt->flag_minus == 0)
	{
		if (strutt->width > len && strutt->precision <= len)
			ft_space(strutt->width - len, strutt);
		if (strutt->width > strutt->precision && strutt->precision > len)
			ft_space(strutt->width - strutt->precision, strutt);
		ft_putchar("0x", 2, strutt);
		if (strutt->precision > len)
			ft_zero(strutt->precision - len, strutt);
		ft_putchar(str, len, strutt);
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar("0x", 2, strutt);
		if (strutt->precision > len)
			ft_zero(strutt->precision - len, strutt);
		ft_putchar(str, len, strutt);
		if (strutt->width > len && strutt->precision <= len)
			ft_space(strutt->width - len, strutt);
		if (strutt->width > strutt->precision && strutt->precision > len)
			ft_space(strutt->width - strutt->precision, strutt);
	}
	return (1);
}
