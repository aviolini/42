/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:58:43 by fulloa-s          #+#    #+#             */
/*   Updated: 2020/10/25 11:43:36 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char q);

void	rigab(int x, char o, char i)
{
	int c;

	c = 2;
	while (c < x)
	{
		putchar(o);
		c++;
	}
	putchar(i);
	write(1, "\n", 1);
}

void	one(int x, char t)
{
	if (x > 1)
	{
		putchar(t);
	}
}

void	colonna(int x, int y)
{
	int p;

	p = 2;
	if (y > 2 && x >= 1)
	{
		while (p < y)
		{
			one(x, '|');
			rigab(x, ' ', '|');
			p++;
		}
	}
	if (y >= 2 && x >= 1)
	{
		one(x, 'o');
		rigab(x, '-', 'o');
	}
}

void	rush(int x, int y)
{
	int c;

	c = 2;
	if (x >= 1 && y >= 1)
	{
		one(x, 'o');
		while (c < x)
		{
			putchar('-');
			c++;
		}
		putchar('o');
		write(1, "\n", 1);
	}
	colonna(x, y);
}
