/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:58:43 by fulloa-s          #+#    #+#             */
/*   Updated: 2020/10/25 11:03:44 by fulloa-s         ###   ########.fr       */
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
			one(x, 'B');
			rigab(x, ' ', 'B');
			p++;
		}
	}
	if (y >= 2 && x >= 1)
	{
		if (x == 1)
		{
			putchar('A');
			write(1, "\n", 1);
		}
		else
		{
			one(x, 'A');
			rigab(x, 'B', 'C');
		}
	}
}

void	rush(int x, int y)
{
	int c;

	c = 2;
	if (x >= 1 && y >= 1)
	{
		putchar('A');
		while (c < x)
		{
			putchar('B');
			c++;
		}
		one(x, 'C');
		write(1, "\n", 1);
	}
	colonna(x, y);
}
