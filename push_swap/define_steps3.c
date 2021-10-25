/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_steps3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:38:41 by aviolini          #+#    #+#             */
/*   Updated: 2021/05/26 10:10:44 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_rra(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("rra\n", 1);
	(s->i)++;
	if (!s->a || !(*s->a))
		return (0);
	temp = ft_list_find_last_node(s->a);
	if (*s->a == temp)
		return (0);
	ft_list_move_node_after_node(s->a, temp, (t_list *)s->a);
	return (1);
}

int	ft_rrb(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("rrb\n", 1);
	(s->i)++;
	if (!s->b || !(*s->b))
		return (0);
	temp = ft_list_find_last_node(s->b);
	if (*s->b == temp)
		return (0);
	ft_list_move_node_after_node(s->b, temp, (t_list *)s->b);
	return (1);
}

int	ft_rrr(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("rrr\n", 1);
	(s->i)++;
	if (s->a || (*s->a))
	{
		temp = ft_list_find_last_node(s->a);
		if (*s->a != temp)
			ft_list_move_node_after_node(s->a, temp, (t_list *)s->a);
	}
	if (s->b || (*s->b))
	{
		temp = ft_list_find_last_node(s->b);
		if (*s->b != temp)
			ft_list_move_node_after_node(s->b, temp, (t_list *)s->b);
	}
	return (1);
}
