/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_steps2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:40:22 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 12:06:48 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_ra(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("ra\n", 1);
	(s->i)++;
	if (!s->a || !(*s->a))
		return (0);
	temp = ft_list_find_last_node(s->a);
	if (*s->a == temp)
		return (0);
	ft_list_move_node_after_node(s->a, *s->a, temp);
	return (1);
}

int	ft_rb(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("rb\n", 1);
	(s->i)++;
	if (!s->b || !(*s->b))
		return (0);
	temp = ft_list_find_last_node(s->b);
	if (*s->b == temp)
		return (0);
	ft_list_move_node_after_node(s->b, *s->b, temp);
	return (1);
}

int	ft_rr(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("rr\n", 1);
	(s->i)++;
	if (s->a || (*s->a))
	{
		temp = ft_list_find_last_node(s->a);
		if (*s->a != temp)
			ft_list_move_node_after_node(s->a, *s->a, temp);
	}
	if (s->b || (*s->b))
	{
		temp = ft_list_find_last_node(s->b);
		if (*s->b != temp)
			ft_list_move_node_after_node(s->b, *s->b, temp);
	}
	return (1);
}
