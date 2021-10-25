/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:37:51 by aviolini          #+#    #+#             */
/*   Updated: 2021/05/26 14:15:48 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_init(t_data **s)
{
	(*s) = (t_data *)malloc(sizeof(t_data));
	(*s)->a = ft_list_init();
	(*s)->b = ft_list_init();
	(*s)->steps = ft_list_init();
	(*s)->i = 0;
	if (!(*s) || !(*s)->a || !(*s)->b || !(*s)->steps)
		return (0);
	return (1);
}

void	ft_exit(t_data *s)
{
	ft_list_del_list(&s->a);
	ft_list_del_list(&s->b);
	ft_list_del_list(&s->steps);
	free(s);
	s = NULL;
	exit (0);
}

void	ft_exit_error(t_data *s)
{
	ft_putstr_fd("Error\n", 1);
	ft_list_del_list(&s->a);
	ft_list_del_list(&s->b);
	ft_list_del_list(&s->steps);
	free(s);
	s = NULL;
	exit (1);
}
