/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:57:20 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 13:57:31 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_av_is_empty(char *s)
{
	int	i;
	int	len ;

	i = -1;
	len = ft_strlen(s);
	while (++i < len)
	{
		if (!ft_isspace_or_tab(s[i]))
			return (0);
	}	
	return (1);
}

int	ft_check_ac(int ac, char **av)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ac < 2)
		return (0);
	while (++i < ac)
	{
		if (ft_av_is_empty(av[i]))
			c++;
	}
	if (c == ac - 1)
		return (0);
	return (1);
}

int	ft_check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace_or_tab(s[i]) && \
			s[i] != '-' && s[i] != '\n')
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}		
		if (s[i] == '-' && (!s[i + 1] || !ft_isdigit(s[i + 1]) || \
			(ft_isdigit(s[i - 1]))))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_insert_arg(t_list **a, char *s, int *i)
{
	long int	num;
	int			sign;

	sign = 0;
	if (s[*i] == '-')
	{	
		(*i)++;
		sign = 1;
	}
	num = 0;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		num = num * 10 + s[*i] - 48;
		(*i)++;
	}
	if (sign)
		num = num * -1;
	if (num < LIMIT_DOWN_INT || num > LIMIT_UP_INT || \
			(ft_list_find_node_by_data(a, &num)))
	{	
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	ft_list_add_node_back_list(a, &num, T_I);
	return (1);
}

int	ft_add_args_to_list(t_list **a, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!ft_check_ac(ac, av))
		return (0);
	while (i++ < ac - 1)
	{
		j = 0;
		if (!ft_check_arg(av[i]))
			return (0);
		while (av[i][j])
		{
			while (av[i][j] && ft_isspace_or_tab(av[i][j]))
				j++;
			if (ft_isdigit(av[i][j]) || av[i][j] == '-')
			{	
				if (!ft_insert_arg(a, av[i], &j))
					return (0);
			}
		}
	}
	return (1);
}
