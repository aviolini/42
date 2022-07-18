/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:01:26 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 12:09:19 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_sa(t_data *s)
{
	if (s->flag_st_output)
		ft_putstr_fd("sa\n", 1);
	(s->i)++;
	if (!s->a || (!(*s->a)) || !(*s->a)->next)
		return (0);
	ft_list_swap(s->a, *s->a, (*s->a)->next);
	return (1);
}

int	ft_sb(t_data *s)
{
	if (s->flag_st_output)
		ft_putstr_fd("sb\n", 1);
	(s->i)++;
	if (!s->b || (!(*s->b)) || !(*s->b)->next)
		return (0);
	ft_list_swap(s->b, *s->b, (*s->b)->next);
	return (1);
}

int	ft_ss(t_data *s)
{
	if (s->flag_st_output)
		ft_putstr_fd("ss\n", 1);
	(s->i)++;
	if (s->a || ((*s->a)) || (*s->a)->next)
		ft_list_swap(s->a, *s->a, (*s->a)->next);
	if (s->b || ((*s->b)) || (*s->b)->next)
		ft_list_swap(s->b, *s->b, (*s->b)->next);
	return (1);
}

int	ft_pa(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("pa\n", 1);
	(s->i)++;
	if (!s->b || !(*s->b))
		return (0);
	temp = ft_list_find_next_node(s->b, (t_list *)s->b);
	ft_list_add_node_front_list(s->a, temp->data, T_I);
	ft_list_del_node_by_node(s->b, temp);
	return (1);
}

int	ft_pb(t_data *s)
{
	t_list	*temp;

	if (s->flag_st_output)
		ft_putstr_fd("pb\n", 1);
	(s->i)++;
	if (!s->a || !(*s->a))
		return (0);
	temp = ft_list_find_next_node(s->a, (t_list *)s->a);
	ft_list_add_node_front_list(s->b, temp->data, T_I);
	ft_list_del_node_by_node(s->a, temp);
	return (1);
}
