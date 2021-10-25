/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:44:11 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/12 12:21:28 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	*ft_primariga(char *newpt)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (newpt[i] && (newpt[i] != '\n'))
	{
		i++;
	}
	i++;
	while (newpt[i])
	{
		newpt[y] = newpt[i];
		i++;
		y++;
	}
	newpt[y] = 0;
	return (0);
}

int		ft_num(char newpt, int tab, char *original)
{
	char empty;
	char obs;

	empty = ft_find_empty(original);
	obs = ft_find_obs(original);
	if (newpt == empty)
		tab = 2;
	if (newpt == obs)
		tab = 1;
	return (tab);
}

int		**ft_tabella(char *newpt, char *originali, int **punt)
{
	int		i;
	int		k;
	int		z;
	int		*tabella[1024];
	int		tab[1024][1024];

	i = 0;
	k = 0;
	z = 0;
	while (newpt[i])
	{
		while (newpt[i] != '\n')
		{
			ft_num(newpt[i], tab[k][z], original);
			i++;
			z++;
		}
		tabella[k] = tab[k];
		i++;
		k++;
		z = 0;
	}
	punt = tabella;
	return (punt);
}
