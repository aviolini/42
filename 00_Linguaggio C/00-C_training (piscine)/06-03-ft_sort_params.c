/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:10:20 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/05 15:49:14 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	x;
	int				res;

	x = 0;
	while (s1[x] || s2[x])
	{
		if (s1[x] != s2[x])
		{
			res = (s1[x] - s2[x]);
			return (res);
		}
		else
			x++;
	}
	return (0);
}

void	ft_print_param(int argc, char *argv[])
{
	int i;
	int k;

	k = 1;
	i = 0;
	while (argc > 1)
	{
		while (argv[k][i])
			i++;
		write(1, argv[k], i);
		write(1, "\n", 1);
		i = 0;
		argc--;
		k++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		k;
	int		x;
	char	*temp;

	i = 1;
	k = 1;
	x = 0;
	while (k < argc)
	{
		while ((k + i) < argc)
		{
			x = ft_strcmp(argv[k], argv[k + i]);
			if (x >= 0)
			{
				temp = argv[k];
				argv[k] = argv[k + i];
				argv[k + i] = temp;
			}
			i++;
		}
		k++;
		i = 1;
	}
	ft_print_param(argc, argv);
}
