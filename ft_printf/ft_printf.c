/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 15:16:09 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	t_strutt	*strutt;

	i = 0;
	va_start(ap, str);
	strutt = (t_strutt *)malloc(sizeof(t_strutt));
	strutt->total_chars = 0;
	while (str[i])
	{
		if (ft_char_is_perc(str, i, strutt))
		{
			if ((i = ft_fill_strutt(strutt, str, i, ap)) == 0)
				break ;
		}
		else if (ft_char_is_2perc(str, i, strutt))
			ft_putchar((char *)&(str[i++]), 1, strutt);
		else
			ft_putchar((char *)&(str[i]), 1, strutt);
		i++;
	}
	i = strutt->total_chars;
	free(strutt);
	va_end(ap);
	return (i);
}

void	ft_init_strutt(t_strutt *strutt)
{
	strutt->flag_minus = 0;
	strutt->flag_zero = 0;
	strutt->width = 0;
	strutt->dot = 0;
	strutt->precision = -1;
	strutt->num_is_zero = 0;
	strutt->num_is_neg = 0;
	strutt->prec_is_arg = 0;
	strutt->prev_was_perc = 0;
	strutt->type = 0;
}

void	ft_use_strutt(t_strutt *strutt, va_list ap)
{
	if (strutt->type == 0)
		return ;
	if (strutt->type == 'd')
		ft_d(strutt, ap);
	if (strutt->type == 'c')
		ft_c(strutt, ap);
	if (strutt->type == 's')
		ft_s(strutt, ap);
	if (strutt->type == 'x')
		ft_xu(strutt, ap, BASE16);
	if (strutt->type == 'X')
		ft_xu(strutt, ap, BASE16X);
	if (strutt->type == 'u')
		ft_xu(strutt, ap, BASE10);
	if (strutt->type == 'p')
		ft_p(strutt, ap);
	if (strutt->type == '%')
		ft_perc(strutt);
}

int		ft_char_is_perc(const char *str, int i, t_strutt *strutt)
{
	if (str[i] == '%' && str[i + 1] != '%' && (str[i - 1] != '%'
	|| strutt->prev_was_perc == 1))
		return (1);
	return (0);
}

int		ft_char_is_2perc(const char *str, int i, t_strutt *strutt)
{
	if (str[i] == '%' && str[i + 1] == '%'
	&& (strutt->prev_was_perc = 1))
		return (1);
	return (0);
}
