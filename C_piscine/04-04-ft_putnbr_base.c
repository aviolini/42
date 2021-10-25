/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:23:51 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/04 08:35:57 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_controllo(char *base)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (base[i])
	{
		c = i + 1;
		while (base[c])
		{
			if (base[i] != base[c])
			{
				c++;
			}
				else return (0);
		}
		if (base[i] != '-' && base[i] != '+')
		{
			i++;
		}
			else return (0);
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_stampa_base(int nbr, char *base, int len)
{
	if (nbr == -2147483648)
	{
		ft_stampa_base(nbr / len, base, len);
		ft_putchar(base[-(nbr % len)]);
	}
	if (nbr < 0)
	{
		if (nbr != -2147483648)
			ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr > len)
	{
		ft_stampa_base(nbr / len, base, len);
		ft_putchar(base[nbr % len]);
	}
	else
		ft_putchar(base[nbr % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = ft_controllo(base);
	if (len == 0)
	{
		return ;
	}
	else
		ft_stampa_base(nbr, base, len);
}
