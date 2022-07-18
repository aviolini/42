/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:58:56 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/04 08:37:33 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	new_nb;
	int		modulo;
	int		risultato;

	nb = nb;
	modulo = new_nb % 10;
	risultato = new_nb / 10;
	if (new_nb < 10)
		putchar(modulo + 48);
	else
	{
		ft_putnbr(risultato);
		putchar(modulo + 48);
	}
}
