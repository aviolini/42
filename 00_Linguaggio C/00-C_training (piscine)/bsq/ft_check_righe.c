/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:05:05 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/12 11:06:46 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int ft_len_rows_tab(int **tabella)
{
	int i;

	i = 0;
	while (tabella[0][i])
		i++;
	return (i);
}

int ft_len_row(char *map)
{
	int i;
	 
	i = 0;
	while(map[i] != '\n')
		i++;
	return (i);
}

int		check_map(char *map, char *original)
{
	int x;
	int y;
	char empty;
	char obs;
	
	x = 0;
	y = 0;	
	empty = ft_find_empty(original);
	obs = ft_find_obs(original);		
	printf("%p",original);

	while (map [x] != '\0')
	{
		while(map[x] != '\n')
		{
			x++;
			y++;
			if (map[x] != empty && map[x] != obs && map[x] != '\n')
				return (0);
		}
		if (y != ft_len_row(map))
			return (0);
		x++;
		y = 0;
	}
	return (1);
}

char	ft_find_empty(char *map)
{
	int		x;

	x = 0;
	while (map[x] >= '0' && map[x] <= '9')
		x++;
	return (map[x]);
}

char	ft_find_obs(char *map)
{
	int		x;

	x = 0;
	while (map[x] >= '0' && map[x] <= '9')
		x++;
	return (map[x + 1]);
}

char	ft_find_full(char *map)
{
	int		x;

	x = 0;
	while (map[x] >= '0' && map[x] <= '9')
		x++;
	return (map[x + 2]);
}
