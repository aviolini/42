/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 08:44:58 by aviolini          #+#    #+#             */
/*   Updated: 2020/10/27 09:04:14 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	w(int ab, int cd)
{
	char cf1;
	char cf2;
	char cf3;
	char cf4;

	cf1 = ab / 10 + '0';
	cf2 = ab % 10 + '0';
	cf3 = cd / 10 + '0';
	cf4 = cd % 10 + '0';
	write(1, &cf1, 1);
	write(1, &cf2, 1);
	write(1, " ", 1);
	write(1, &cf3, 1);
	write(1, &cf4, 1);
}

void	se(int ab, int cd)
{
	if (!(ab == 98 && cd == 99))
	{
		write(1, ",", 1);
	}
}

void	ft_print_comb2(void)
{
	int ab;
	int cd;

	ab = 0;
	while (ab <= 98)
	{
		cd = ab + 1;
		while (cd <= 99)
		{
			w(ab, cd);
			se(ab, cd);
			cd++;
		}
		cd = 0;
		ab++;
	}
}
